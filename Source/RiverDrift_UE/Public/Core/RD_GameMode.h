// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RD_GameMode.generated.h"

/**
 * 
 */
class ATileManager;

UCLASS()
class RIVERDRIFT_UE_API ARD_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	// --- VARS ---

public:

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<ATileManager> TileManager;
	// --- FUNCTIONS ---

public:
	ARD_GameMode();


};
