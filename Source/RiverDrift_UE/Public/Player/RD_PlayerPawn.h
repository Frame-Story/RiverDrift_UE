// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RD_PlayerPawn.generated.h"

class UStaticMeshComponent;
class ASpawnableTile;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FTransform ZeroTransform;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* PlayerModel;


private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComp;
};
