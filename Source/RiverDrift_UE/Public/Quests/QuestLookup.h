#pragma once

//#include "Quests/RDQuestLine.h"
#include "UI/DA_RDDialogueScene.h"
#include "QuestLookup.generated.h"


USTRUCT(BlueprintType)
struct RIVERDRIFT_UE_API FQuestLookup : public FTableRowBase
{
	GENERATED_BODY()

	FQuestLookup() {
		//UE_LOG(QuestLog, Log, TEXT("constructor called"))
		//QuestID = FGuid::NewGuid();
	};

	//FQuestLookup(UDA_RDDialogueScene* Scene) {
	//	FQuestLookup();
	//	//DialogueScene = Scene;

	//};

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tiles")
	FGuid QuestID = FGuid::NewGuid();


	//Used to set the reference to what other object is associated with this quest. 
	// When the player "interacts" with this object, the quest will progress
	// - Table: needs to be set to the landmarks data table or the dialogue quest lookup table
	// - Row: the row within that table that will identify the object
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quests")
	FDataTableRowHandle OtherObjectRowHandle;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tiles")
	//TObjectPtr<UDA_RDDialogueScene> DialogueScene;


};



USTRUCT(BlueprintType)
struct RIVERDRIFT_UE_API FDialogueQuestLookup : public FTableRowBase
{
	GENERATED_BODY()

	FDialogueQuestLookup() 
		: QuestID(), DialogueScene(nullptr)
	{}

	//explicit FDialogueQuestLookup(UDA_RDDialogueScene* Scene) 
	//	:  DialogueScene(Scene) {
	//	//FDialogueQuestLookup();
	//	//DialogueScene = Scene;

	//	//QuestID = FGuid::NewGuid();
	//}

public:



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tiles")
	FGuid QuestID;


	//Used to set the reference to what other object is associated with this quest. 
	// When the player "interacts" with this object, the quest will progress
	// - Table: needs to be set to the landmarks data table or the dialogue quest lookup table
	// - Row: the row within that table that will identify the object
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quests")
	FDataTableRowHandle OtherObjectRowHandle;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tiles")
	//FGuid QuestID = FGuid::NewGuid();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tiles")
	TObjectPtr<UDA_RDDialogueScene> DialogueScene = nullptr;

};

//template<> RIVERDRIFT_UE_API UScriptStruct* StaticStruct<FDialogueQuestLookup>()
//{
//	static class UScriptStruct* Singleton = nullptr;
//	if (!Singleton)
//	{
//		Singleton = FDialogueQuestLookup::StaticStruct();
//	}
//	return Singleton;
//}

 