// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RD_PlayerController.h"
#include "GameFramework/Pawn.h"
//#include "Blueprint/AIBlueprintHelperLibrary.h"
//#include "TopDownRefCharacter.h"//change to RD player character when we have it
#include "Engine/World.h"
#include "Logging/StructuredLog.h"
#include "Hexes/AA_SpawnableTile.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

ARD_PlayerController::ARD_PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ARD_PlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
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

	//from this point, try to deproject mouse to world and translate that into a hex coord
	FVector WorldLocation;
	FVector WorldDirection;

	ECollisionChannel traceChannel = ECollisionChannel::ECC_GameTraceChannel1;
	FHitResult HitResult;
	GetHitResultUnderCursor(traceChannel, false, HitResult);
	if (HitResult.bBlockingHit) {
		ASpawnableTile* tile;
		tile = Cast<ASpawnableTile>(HitResult.GetActor());
		if (IsValid(tile)) {
			UE_LOGFMT(LogTemp, Log, "we got a hit, pos is {0}", tile->HexCoord.ToString());

		}
	}



	if (DeprojectMousePositionToWorld(WorldLocation, WorldDirection)) {
		UE_LOGFMT(LogTemp, Log, "mouse click pos is {0}, direction is {1}", WorldLocation.ToString(), WorldDirection.ToString());

	}
	else {
		UE_LOGFMT(LogTemp, Warning, "Unable to find mouse pos");

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
