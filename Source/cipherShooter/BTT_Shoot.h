// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class CIPHERSHOOTER_API UBTT_Shoot : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Shoot();
	 virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
