// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "../HexLibrary.h"
#include "RD_PlayerController.generated.h"

class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;
class ASpawnableTile;
class ATileManager;
class ARD_GameMode;

/**
 * 
 */
UCLASS()
class RIVERDRIFT_UE_API ARD_PlayerController : public APlayerController
{
	GENERATED_BODY()

	// --- VARIABLES ---

public:

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SelectTileClickAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SelectTileTouchAction;


	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, category = "Tiles")
	ASpawnableTile* CurrentSelectedTile;


	///TODO: add input actions for move to tile and place tile
	///** Jump Input Action */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* SelectTileClickAction;

	///** Jump Input Action */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* SelectTileTouchAction;

	///** Jump Input Action */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* SelectTileClickAction;

	///** Jump Input Action */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* SelectTileTouchAction;


	// --- FUNCTIONS
public:
	ARD_PlayerController();



protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	//uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;

	// To add mapping context
	virtual void BeginPlay();

	/** Input handlers for SetDestination action. */
	void OnInputStarted();
	void OnSelectTileTriggered();
	void OnTouchTriggered();
	void OnTouchReleased();

	UFUNCTION(BlueprintImplementableFunction, BlueprintCallable )
	bool CheckIfTileInRange(ASpawnableTile* tile);//no C++ implementation (yet?), likely for designers 

	void ActivateTile();

	TObjectPtr<ARD_GameMode> GameMode;

private:

	bool bPlayerIsTouchingScreen; // Is it a touch device


};
