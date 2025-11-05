// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DA_RDDialogueScene.h"
#include "Quests/QuestLookup.h"
#include "Quests/RDQuestManagerSubsystem.h"


FRDDialogueResponseOption::FRDDialogueResponseOption()
{
	//UE_LOG(LogTemp, Log, TEXT("dialogue response option default constr called"))
	//ButtonText = FText::FromString("[continue]");
}

FRDDialogueResponseOption::FRDDialogueResponseOption(FText _ButtonText)
{
	ButtonText = _ButtonText;
}

FRDDialogueSlide::FRDDialogueSlide() 
{
	UE_LOG(LogTemp, Log, TEXT("dialogue slide default constr called"))
		LeftResponse = FRDDialogueResponseOption();
	RightResponse = FRDDialogueResponseOption(FText::FromString("[continue]"));

}

UDA_RDDialogueScene::UDA_RDDialogueScene() {
	//TablePath = 

}
//
//UDA_RDDialogueScene::UDA_RDDialogueScene(const UDA_RDDialogueScene& other) {
//	this->QuestLookupRow = other.QuestLookupRow;
//	this->QuestLookupDataTable = other.QuestLookupDataTable;
//	this->Slides = other.Slides;
//
//
//}

#if WITH_EDITOR
void UDA_RDDialogueScene::PostInitProperties()
{
	Super::PostInitProperties();

	if (!HasAnyFlags(RF_ClassDefaultObject)) // avoid running for CDO
	{
		//fRegisterDataTable();
	}
}
#endif
void UDA_RDDialogueScene::PostLoad()
{
	Super::PostLoad();
#if WITH_EDITOR
	//fRegisterDataTable();
#endif


	//CTD: bring back automatic references/building of data tables, rather than leaving them manually

	// Always try to read the row, in editor or cooked builds
	//UDataTable* DataTable = LoadObject<UDataTable>(nullptr, *TablePath);
	//if (DataTable)
	//{
	//	FDialogueQuestLookup* ExistingRow = DataTable->FindRow<FDialogueQuestLookup>(RowNameInDataTable, TEXT("PostLoad"));
	//	if (ExistingRow)
	//	{
	//		QuestLookupRow = *ExistingRow;
	//	}
	//}
}

void UDA_RDDialogueScene::fRegisterDataTable()
{
	(void)FDialogueQuestLookup::StaticStruct();

	UDataTable* DataTable = LoadObject<UDataTable>(nullptr, *TablePath);

	if (!DataTable) {
		UE_LOG(LogTemp, Warning, TEXT("Failed to load data table at %s"), *TablePath);
		return;
	}

	const FName RowName = RowNameInDataTable;

	UE_LOG(LogTemp, Warning, TEXT("ctf name is %s"), *RowName.ToString());

	//FDialogueQuestLookup* ExistingRow = DataTable->FindRow<FDialogueQuestLookup>(RowName, TEXT("fRegisterDataTable()"));
	FDialogueQuestLookup* ExistingRow = DataTable->FindRow<FDialogueQuestLookup>(RowName, TEXT("MyRegisterDataTable()"));
	if (ExistingRow){
		QuestLookupRow = *ExistingRow;
		
		UE_LOG(LogTemp, Log, TEXT("row already exists %s"), *RowName.ToString());
		return ;
	} 

	//else, make a new one
	FDialogueQuestLookup NewRow;
	NewRow.DialogueScene = this;

	NewRow.QuestID = FGuid::NewGuid();

	//DataTable


	//QuestLookupRow = NewRow;

	////FDialogueQuestLookup NewRow;
	////NewRow->DialogueScene = this;
	////QuestLookupRow = FDialogueQuestLookup();
	////QuestLookupRow = NewObject<FDialogueQuestLookup>();
	//QuestLookupRow->DialogueScene = this;
	//QuestLookupRow = NewRow;

	DataTable->AddRow(RowName, NewRow);
	QuestLookupRow = NewRow;
	UE_LOG(LogTemp, Log, TEXT("Registered asset '%s' in data table '%s'"), *GetName(), *TablePath);

	
#if WITH_EDITOR
		DataTable->Modify();
	DataTable->MarkPackageDirty();
#endif
	
}

void UDA_RDDialogueScene::CloseDialogueScene()
{
	UE_LOG(LogTemp, Log, TEXT("Dialogue scene finished"))


	UDataTable* DataTable = LoadObject<UDataTable>(this, *TablePath);

	if (!DataTable) {
		UE_LOG(LogTemp, Error, TEXT("Failed to load data table at %s"), *TablePath);
		return;
	}

	const FName RowName = RowNameInDataTable;
	FDialogueQuestLookup* Row = DataTable->FindRow<FDialogueQuestLookup>(RowName, TEXT("CloseDialogueScene()"));
	//QuestLookupRow = Row;
	if (Row) {

		UE_LOG(LogTemp, Log, TEXT("row already exists %s"), *RowName.ToString());
		//return;
	}
	else {

		UE_LOG(LogTemp, Log, TEXT("row DOESN'T already exist "));
	}

	////FDialogueQuestLookup NewRow;
	//NewRow->DialogueScene = this;
	//QuestLookupRow = NewRow;

	//DataTable->AddRow(RowName, *NewRow);
	//UE_LOG(LogTemp, Log, TEXT("Registered asset '%s' in data table '%s'"), *GetName(), *TablePath);



	//if (!QuestLookupRow || !QuestLookupRow->QuestID.IsValid()) {
	//	UE_LOG(LogTemp, Log, TEXT("quest lookup not valid, registering"))

	//	fRegisterDataTable();
	//}
	if(!Row || !Row->QuestID.IsValid()) {
		UE_LOG(LogTemp, Error, TEXT("quest lookup STILL not valid, exiting"))
			return;
			//fRegisterDataTable();
	}

	GetWorld()->GetSubsystem<URDQuestManagerSubsystem>()->CheckProgression(
		EConditionType::CE_Dialogue, Row->QuestID);

}


//UDA_RDDialogueScene::UDA_RDDialogueScene()
//{
//	QuestLookupDataTable = GetAssetByObjectPath<
//}
