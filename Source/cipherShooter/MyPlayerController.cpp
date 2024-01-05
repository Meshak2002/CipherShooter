// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    UI->RemoveFromViewport();

    if(bIsWinner){
          UE_LOG(LogTemp, Warning, TEXT("This is a W message."));
          UUserWidget* winwidget = CreateWidget<UUserWidget>(this, Wwidget.Get());
          if(winwidget!=nullptr)
             winwidget->AddToViewport();
    }else{
          UE_LOG(LogTemp, Warning, TEXT("This is a L message."));
          UUserWidget* losewidget = CreateWidget<UUserWidget>(this, widget.Get());
          if(losewidget!=nullptr)
             losewidget->AddToViewport();
    }
    GetWorldTimerManager().SetTimer(time,this,&AMyPlayerController::RestartLevel,timer);
    
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UI = CreateWidget<UUserWidget>(this, HUD.Get());
    if(UI!=nullptr)
         UI->AddToViewport();
}
