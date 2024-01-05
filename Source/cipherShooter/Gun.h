// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class CIPHERSHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	UPROPERTY(VisibleAnywhere)
	USceneComponent* parent;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* mesh;

	void Shoot();

	UPROPERTY(EditAnywhere)
	UParticleSystem* muzzle;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* impactPoint;

	UPROPERTY(EditAnywhere)
	float range=5000;

	UPROPERTY(EditAnywhere)
	float damage=20;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

	bool GunTrace(FRotator& r,FHitResult& hit);

	UPROPERTY(EditDefaultsOnly)
	USoundBase* muzzleSound;

	UPROPERTY(EditDefaultsOnly)
	USoundBase* ImpactSound;
};
