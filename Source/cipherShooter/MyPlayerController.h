// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CIPHERSHOOTER_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
		virtual void BeginPlay() override;

public :
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;

	UPROPERTY(EditDefaultsOnly)
	float timer = 3;

	FTimerHandle time;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> widget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> Wwidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUD;

	UPROPERTY()
	UUserWidget* UI;
};
