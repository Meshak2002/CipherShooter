// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmGameMode.h"
#include "MyPlayerController.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "MyAIController.h"

void AKillEmGameMode::PawnKilled(APawn* killed)
{
    Super::PawnKilled(killed);
    AMyPlayerController* pcontroller = Cast<AMyPlayerController>(killed->GetController());
    if(pcontroller!=nullptr){
        UE_LOG(LogTemp, Warning, TEXT("Player is dead"));
        EndGame(false);
    }

    for(AMyAIController* enemy : TActorRange<AMyAIController>(GetWorld())){
        if(!enemy->isEDead()){
            return;
        }
    }
    EndGame(true);
}

void AKillEmGameMode::EndGame(bool isPlayerAlive)
{
    for(AController* ctroller : TActorRange<AController>(GetWorld())){
        if(ctroller->IsPlayerController() ==isPlayerAlive){
            ctroller->GameHasEnded(ctroller->GetPawn(),true);
        }else{
             ctroller->GameHasEnded(ctroller->GetPawn(),false);
        }
    }
}
