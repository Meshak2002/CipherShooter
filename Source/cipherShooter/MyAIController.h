// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class CIPHERSHOOTER_API AMyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

	UPROPERTY()
	class AMyCharacter* enemyMe;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* behavComp;

	bool isEDead();
};
