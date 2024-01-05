// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "cipherShooterGameModeBase.h"
#include "KillEmGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CIPHERSHOOTER_API AKillEmGameMode : public AcipherShooterGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* killed) override;

	void EndGame(bool isPlayerAlive);
};
