// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearBlackBoardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UClearBlackBoardValue::UClearBlackBoardValue()
{
    NodeName = "Clear Black Board Value";
    
}

EBTNodeResult::Type UClearBlackBoardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp,NodeMemory);
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    return EBTNodeResult::Succeeded;
}

