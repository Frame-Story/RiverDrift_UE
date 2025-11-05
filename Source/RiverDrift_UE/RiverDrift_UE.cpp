// Copyright Epic Games, Inc. All Rights Reserved.

#include "RiverDrift_UE.h"
#include "Modules/ModuleManager.h"
#include "Quests/QuestLookup.h"


class FRiverDrift_UEModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override {
		(void)FDialogueQuestLookup::StaticStruct();

	}

};

IMPLEMENT_PRIMARY_GAME_MODULE(FRiverDrift_UEModule, RiverDrift_UE, "RiverDrift_UE" );

DEFINE_LOG_CATEGORY(QuestLog);
