// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_RDPrototypeAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class RIVERDRIFT_UE_API UDA_RDPrototypeAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bAllowOverridingWater;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bAllowWaterGeneration;

};
