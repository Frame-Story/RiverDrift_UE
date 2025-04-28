// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/QuestManagerSubsystem.h"


UQuestManagerSubsystem::UQuestManagerSubsystem()
{

}


void UQuestManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    InitializeSubsystem();
}


void UQuestManagerSubsystem::Deinitialize()
{
    Super::Deinitialize();
    DeinitializeSubsystem();
}


void UQuestManagerSubsystem::ShowQuestDialogue(EQuestEnums Quest)
{
    CurrentQuestEnum = Quest;

    BPShowQuestDialogue();
}


void UQuestManagerSubsystem::BPShowQuestDialogue_Implementation()
{
}


void UQuestManagerSubsystem::InitializeSubsystem_Implementation()
{
}


void UQuestManagerSubsystem::DeinitializeSubsystem_Implementation()
{
}
