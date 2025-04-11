// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

#include "RD_PlayerPawn.generated.h"

class UStaticMeshComponent;
class ASpawnableTile;
class USphereComponent;
class ARD_GameMode;
class UCapsuleComponent;
class ARD_PlayerController;

UCLASS()
class RIVERDRIFT_UE_API ARD_PlayerPawn : public APawn
{
	GENERATED_BODY()

// --- FUNCTIONS ---

public:
	// Sets default values for this pawn's properties
	ARD_PlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveToTile(ASpawnableTile* tile);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// --- VARS ---

public:	

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return SpringArmComp; }

protected:

	ARD_PlayerController* PlayerController;

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* PlayerModel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USphereComponent* InteractColliderCircle;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	//USphereComponent* sphere;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float fRangeInNumOfTiles;

	ASpawnableTile* CurrentTileLocation;

private:

	const float TileSize = 512;

	ARD_GameMode* GameMode;


	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComp;
};
