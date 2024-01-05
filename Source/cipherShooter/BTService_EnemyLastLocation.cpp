// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_EnemyLastLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "MyAIController.h"

UBTService_EnemyLastLocation::UBTService_EnemyLastLocation()
{
    NodeName="BTService_EnemyLastLocation";
}

void UBTService_EnemyLastLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
    APawn* player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
     if(player){
        AMyCharacter* pCharacter = Cast<AMyCharacter>(player);
        AAIController* ai= OwnerComp.GetAIOwner();
        if(pCharacter !=nullptr && ai!=nullptr){
        if(pCharacter->health>0){
                OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),player->GetActorLocation());
        }
        }
     }
}
