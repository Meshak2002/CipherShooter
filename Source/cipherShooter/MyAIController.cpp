// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyCharacter.h"

void AMyAIController::BeginPlay()
{
    Super::BeginPlay();
    enemyMe = Cast<AMyCharacter>(GetPawn());
    RunBehaviorTree(behavComp);
    APawn* player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
    GetBlackboardComponent()->SetValueAsVector(TEXT("CharacterInitialPos"), player->GetActorLocation());
}

void AMyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool AMyAIController::isEDead()
{
    AMyCharacter* enemy = Cast<AMyCharacter>(GetPawn());
    if(enemy!=nullptr){
        return enemy->isDead();
    }
    return false;
}
