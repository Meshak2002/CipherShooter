// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"
#include "CollisionQueryParams.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	parent=CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent=parent;
	mesh=CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal_Mesh");
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AGun::GunTrace(FRotator& r,FHitResult& hit)
{
	APawn* player=Cast<APawn>(GetOwner());
	if(player!=nullptr){
		FVector l;
		//FRotator r;
		player->GetController()->GetPlayerViewPoint(l,r);
	    UGameplayStatics::SpawnEmitterAttached(muzzle,mesh,TEXT("RifleRootSocket"));
		UGameplayStatics::SpawnSoundAttached(muzzleSound,mesh,TEXT("Muzzle Sound"));

		FVector endPoint=l+r.Vector()*range;
		FCollisionQueryParams param ;
		param.AddIgnoredActor(GetOwner());

		return GetWorld()->LineTraceSingleByChannel(hit,l,endPoint,ECC_GameTraceChannel1,param);
	}
	return false;
}

void AGun::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("This is a log message."));
	FRotator r; 
	FHitResult hit;
	if(GunTrace(r, hit)){
		//DrawDebugPoint(GetWorld(),hit.Location,30,FColor::Red,true);
		FVector opDir= -r.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),impactPoint,hit.Location,opDir.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(),ImpactSound,hit.Location);

		FPointDamageEvent DamageEvent(damage,hit,opDir,nullptr);
		AActor* actor= hit.GetActor();
		if(actor!=nullptr){
			actor->TakeDamage(damage,DamageEvent,Cast<AController>(GetOwner()),this);
			
		}
	}
}
