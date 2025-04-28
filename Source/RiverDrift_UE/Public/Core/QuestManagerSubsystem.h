// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataTableUtils.h"
#include "Subsystems/WorldSubsystem.h"
#include "Enumerators/QuestEnums.h"

#include "QuestManagerSubsystem.generated.h"

UCLASS(Blueprintable)

class UQuestManagerSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UQuestManagerSubsystem();

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable)
        void ShowQuestDialogue(EQuestEnums Quest);

protected:
    UFUNCTION(BlueprintNativeEvent)
        void InitializeSubsystem();
    UFUNCTION(BlueprintNativeEvent)
        void DeinitializeSubsystem();

    UFUNCTION(BlueprintNativeEvent)
        void BPShowQuestDialogue();

public:



protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        int32 QuestDialogueToDisplay;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UDataTable* DTQuestLines;

    UPROPERTY(BlueprintReadWrite)
        EQuestEnums CurrentQuestEnum;
};