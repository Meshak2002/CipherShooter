#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
 #include "Gun.h"
 #include "KillEmGameMode.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damageToTake = Super::TakeDamage(DamageAmount,DamageEvent,EventInstigator,DamageCauser);
	damageToTake= FMath::Min(damageToTake,health);
	health-=damageToTake;

	if(isDead()){
		AKillEmGameMode* AKMGameMode = Cast<AKillEmGameMode>(GetWorld()->GetAuthGameMode());
		AKMGameMode->PawnKilled(this);
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	return damageToTake;
}

bool AMyCharacter::isDead() const
{
	return health<=0;
}

float AMyCharacter::getHealth() const
{
	return health/MaxHealth;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetMesh()->HideBoneByName("weapon_r",PBO_None);
	Gun=GetWorld()->SpawnActor<AGun>(MGun);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("hand_rSocket"));
	Gun->SetOwner(this);
	health=MaxHealth;
	if(FocusPoint){
		fp= Cast<APawn>(GetWorld()->SpawnActor(FocusPoint));
		fp->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("FocusAttack"));
		fp->SetOwner(this);
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAction("MoveForward");
	PlayerInputComponent->BindAxis("MoveForward",this,&AMyCharacter::MoveForw);
	PlayerInputComponent->BindAxis("Turn",this,&AMyCharacter::Strafe);
	PlayerInputComponent->BindAxis("MouseX",this,&AMyCharacter::MouseUpp);
	PlayerInputComponent->BindAxis("MouseY",this,&AMyCharacter::MouseSide);
	PlayerInputComponent->BindAction("Fire",EInputEvent::IE_Pressed,this,&AMyCharacter::pullTrigger);
	PlayerInputComponent->BindAction("Jump",EInputEvent::IE_Pressed,this,&ACharacter::Jump);
}

void AMyCharacter::MoveForw(float x)
{
	float speed=x*MovSpeed;   //*UGameplayStatics::GetWorldDeltaSeconds(this);
	AddMovementInput(APawn::GetActorForwardVector()*speed);
}

void AMyCharacter::Strafe(float x)
{
	float speed=x*MovSpeed; //*UGameplayStatics::GetWorldDeltaSeconds(this);
	AddMovementInput(APawn::GetActorRightVector()*speed);
}

void AMyCharacter::MouseUpp(float x)
{
	AddControllerYawInput(x*UGameplayStatics::GetWorldDeltaSeconds(this)*RotSpeed);

}

void AMyCharacter::MouseSide(float x)
{
		AddControllerPitchInput(-x*UGameplayStatics::GetWorldDeltaSeconds(this)*RotSpeed);
}

void AMyCharacter::pullTrigger()
{
	Gun->Shoot();
}




