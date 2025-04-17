// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tiledata.h"
#include "RDSpawnableLandmark.generated.h"

struct FLandmarkData;
class UPaperSpriteComponent;
class ASpawnableTile;
class ARDPotentialLandmark;

UCLASS()
class RIVERDRIFT_UE_API ARDSpawnableLandmark : public AActor
{
	GENERATED_BODY()
	// --- VARS ---


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	TArray<ASpawnableTile*> ComposingTiles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	FLandmarkData LandmarkData;


//protected:
//
//
//
//public:

	// --- FUNCS
	
public:	
	// Sets default values for this actor's properties
	ARDSpawnableLandmark();

	void InitializeLandmark(ARDPotentialLandmark* PotentialLandmark);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
