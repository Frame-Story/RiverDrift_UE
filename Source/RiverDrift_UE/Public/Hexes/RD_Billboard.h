// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "RD_Billboard.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class RIVERDRIFT_UE_API URD_Billboard : public UPaperSpriteComponent
{
	GENERATED_BODY()

	// --- VARS ---

protected: 
	APlayerCameraManager* CameraManager;
	FRotator lookRotation;

private:

	URD_Billboard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	FRotator applyRot;
};
