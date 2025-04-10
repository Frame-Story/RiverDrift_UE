// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RD_GameMode.h"
#include "Player/RD_PlayerController.h"
#include "Hexes/TileManager.h"
#include "Core/RDPrototypingManager.h"
#include "UObject/ConstructorHelpers.h"

ARD_GameMode::ARD_GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARD_PlayerController::StaticClass();

	 //set default pawn class to our Blueprinted character
	
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Player/BP_RDPlayerPawn")); //TODO
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/Player/BP_RDPlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}


}

void ARD_GameMode::BeginPlay()
{
	PrototypingManagerInstance =  GetWorld()->SpawnActor<ARDPrototypingManager>(PrototypingManagerFormat);
}


