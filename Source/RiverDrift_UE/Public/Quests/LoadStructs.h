// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Quests/QuestLookup.h"
#include "LoadStructs.generated.h"

/**
 * 
 */
UCLASS()
class RIVERDRIFT_UE_API ULoadStructs : public UObject
{
	GENERATED_BODY()

public:
	ULoadStructs() {

		(void)FDialogueQuestLookup::StaticStruct();
	}
	
};
