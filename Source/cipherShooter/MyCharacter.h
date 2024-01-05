// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class CIPHERSHOOTER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AMyCharacter();


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGun> MGun;

	UPROPERTY()
	 class AGun* Gun;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(VisibleAnywhere)
	float health;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth=100;

	UFUNCTION(BlueprintPure)
	bool isDead() const;

	UFUNCTION(BlueprintPure)
	float getHealth() const;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> FocusPoint;

	UPROPERTY()
	APawn* fp;

private :
	 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void play();
	
	UPROPERTY(EditAnywhere)
	int MovSpeed=10;

	UPROPERTY(EditAnywhere)
	int RotSpeed=10;
	
	void MoveForw(float x);

	void Strafe(float x);

	void MouseUpp(float x);

	void MouseSide(float x);

	void pullTrigger();
};
