// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RD_PlayerController.h"
#include "Logging/StructuredLog.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"
#include "HexLibrary.h"
#include "Hexes/AA_SpawnableTile.h"
#include "Core/RD_GameMode.h"
#include "Hexes/TileManager.h"

ARD_PlayerController::ARD_PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ARD_PlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();


	GameMode = Cast<ARD_GameMode>(GetWorld()->GetAuthGameMode());
	TileManager = GameMode->TileManager;
	if (IsValid(GameMode)) {
		UE_LOGFMT(LogTemp, Log, "gamemode is properly set");
	}
	else {
		UE_LOGFMT(LogTemp, Warning, "gamemode is properly INVALID");

	}
	if (IsValid(TileManager)) {
		UE_LOGFMT(LogTemp, Log, "TileManager is properly set");
	}
	else {
		UE_LOGFMT(LogTemp, Warning, "TileManager is properly INVALID");		
	}
}

void ARD_PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SelectTileClickAction, ETriggerEvent::Started, this, &ARD_PlayerController::OnInputStarted);
		//EnhancedInputComponent->BindAction(SelectTileClickAction, ETriggerEvent::Triggered, this, &ARD_PlayerController::OnSelectTileTriggered);

		// Setup touch input events
		EnhancedInputComponent->BindAction(SelectTileTouchAction, ETriggerEvent::Started, this, &ARD_PlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SelectTileTouchAction, ETriggerEvent::Triggered, this, &ARD_PlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(SelectTileTouchAction, ETriggerEvent::Completed, this, &ARD_PlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(SelectTileTouchAction, ETriggerEvent::Canceled, this, &ARD_PlayerController::OnTouchReleased);
	}
	else
	{
		UE_LOGFMT(LogTemp, Log, "{0} Failed to find an Enhanced Input Component!This template is built to use the Enhanced Input system.If you intend to use the legacy system, then you will need to update this C++ file.", * GetNameSafe(this));
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ARD_PlayerController::OnInputStarted()
{
	OnSelectTileTriggered();
}

void ARD_PlayerController::OnSelectTileTriggered()
{
	UE_LOGFMT(LogTemp, Log, "Player input detected");

	//raytracing method, works but feels needlessly expensive
	ETraceTypeQuery traceChannel = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1);
	FHitResult HitResult;
	GetHitResultUnderCursorByChannel(traceChannel, false, HitResult);

	if (HitResult.bBlockingHit) {
		ASpawnableTile* tile;

		tile = Cast<ASpawnableTile>(HitResult.GetActor());
		if (IsValid(tile)) {//ensure that the actor we found was correctly cast to a tile - theoretically once I tweak trace channels this shouldn't ever return false, but I always cast on the side of caution
			UE_LOGFMT(LogTemp, Log, "we got a hit, pos is {0} channel was {1}", tile->HexCoord.ToString(), ECollisionChannel::ECC_GameTraceChannel2);


			//TODO: check whether the tile is "in range" of player - will we still be using the interaction box?
			if (IsValid(CurrentSelectedTile)) {
				if (CurrentSelectedTile == tile) {
					UE_LOGFMT(LogTemp, Log, "player has clicked current tile twice over. activating that tile");
					
					ActivateTile();
				}
				else {
					UE_LOGFMT(LogTemp, Log, "player has clicked a tile other than the currently selected tile. selecting that tile");
					CurrentSelectedTile = tile;
				}
			}
			else {
				UE_LOGFMT(LogTemp, Log, "player has clicked a new tile for the very first time. selecting that tile");
				CurrentSelectedTile = tile;
			}
		}
		else {
			UE_LOGFMT(LogTemp, Warning, "player tile raycast somehow returned an actor that isn't a tile. something is wrong with your collisions");
		}
	}
	else {
		UE_LOGFMT(LogTemp, Log, "player has clicked into the void or somehow hit something that wasn't a tile. should we unset the currently selected tile?");

	}
}


void ARD_PlayerController::OnTouchTriggered()
{
	UE_LOGFMT(LogTemp, Log, "Player selected a tile through a screen touch rather than a click, do we need to do anything differently here?");
	OnSelectTileTriggered();
}

void ARD_PlayerController::OnTouchReleased()
{
}

void ARD_PlayerController::ActivateTile()
{
	
	if (!IsValid(GameMode)) {
		GameMode = Cast<ARD_GameMode>(GetWorld()->GetAuthGameMode());
	}
	if (!IsValid(TileManager)) {
		TileManager = GameMode->TileManager;
	}

	switch (CurrentSelectedTile->TileType.ETileType) {
	case(ETileType::TE_Blank):

		CurrentSelectedTile->UpgradeTile(TileManager->GetNextTileToPlace());
		UE_LOGFMT(LogTemp, Log, "player activated blank tile, time to upgrade it");
		break;
	case(ETileType::TE_River):
		//need to implement boat movement :)
		UE_LOGFMT(LogTemp, Log, "player activated River tile, move to tile");
		break;
	default:
		UE_LOGFMT(LogTemp, Log,
			"player activated a different tile (tiletype {0}, do we want to do something different here? should it be interactable?",
			UEnum::GetValueAsString(CurrentSelectedTile->TileType.ETileType));
		break;
	}
}
