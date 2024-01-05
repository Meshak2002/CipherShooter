// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "ClearBlackBoardValue.generated.h"

/**
 * 
 */
UCLASS()
class CIPHERSHOOTER_API UClearBlackBoardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	 UClearBlackBoardValue();

	 virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
