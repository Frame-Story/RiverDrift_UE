// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tiledata.h"
#include "RDPotentialLandmark.generated.h"

struct FLandmarkData;
class ASpawnableTile;
class UPaperSpriteComponent;

UCLASS()
class RIVERDRIFT_UE_API ARDPotentialLandmark : public AActor
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



	// --- FUNCS ---
public:	
	// Sets default values for this actor's properties
	ARDPotentialLandmark();
	void InitializeLandmark(TArray<ASpawnableTile*> _ComposingTiles, FLandmarkData _LandmarkData);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
