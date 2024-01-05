// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "cipherShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CIPHERSHOOTER_API AcipherShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* killed);
};
