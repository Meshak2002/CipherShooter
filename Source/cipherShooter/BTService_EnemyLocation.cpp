// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_EnemyLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "MyAIController.h"

void UBTService_EnemyLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
    APawn* player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
     if(player){
          USkeletalMeshComponent* skelMesh= player->FindComponentByClass<USkeletalMeshComponent>();
          if(skelMesh){
                FTransform transf = skelMesh->GetSocketTransform("Chest");
                //UE_LOG(LogTemp, Warning, TEXT("Chest")); 
                 AMyCharacter* pCharacter = Cast<AMyCharacter>(player);
                 AAIController* ai= OwnerComp.GetAIOwner();
                 if(pCharacter !=nullptr && ai!=nullptr){
                    if(ai->LineOfSightTo(player)){
                         //UE_LOG(LogTemp, Warning, TEXT("%f"),player->GetActorLocation().Z);
                         OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(),pCharacter->fp);
                        // OwnerComp.GetBlackboardComponent()->SetValueAsObject("EnemyRot",transf);
                    }else{
                       OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
                       OwnerComp.GetBlackboardComponent()->SetValueAsVector("EnemyLastLocation",player->GetActorLocation());
                       // OwnerComp.GetBlackboardComponent()->ClearValue("EnemyLoc");
                    }
                }
            }
     }
}


UBTService_EnemyLocation::UBTService_EnemyLocation()
{
    NodeName="BTService_EnemyLocation";
}
