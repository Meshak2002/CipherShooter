// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Shoot.h"
#include "AIController.h"
#include "MyCharacter.h"

UBTT_Shoot::UBTT_Shoot()
{
    NodeName = "Shoot";
}

EBTNodeResult::Type UBTT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
     Super::ExecuteTask(OwnerComp,NodeMemory);
     AMyCharacter* charac= Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
     if(charac!=nullptr){
            charac->pullTrigger();
     }
     return EBTNodeResult::Succeeded;
}
