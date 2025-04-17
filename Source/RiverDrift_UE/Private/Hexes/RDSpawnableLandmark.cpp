// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/RDSpawnableLandmark.h"
#include "Hexes/RDPotentialLandmark.h"
#include "Hexes/SpawnableTile.h"
#include "PaperSpriteComponent.h"

// Sets default values
ARDSpawnableLandmark::ARDSpawnableLandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARDSpawnableLandmark::InitializeLandmark(ARDPotentialLandmark* PotentialLandmark)
{
	SetActorLocation(PotentialLandmark->GetActorLocation());
	ComposingTiles = PotentialLandmark->ComposingTiles;

	LandmarkData = PotentialLandmark->LandmarkData;

	Sprite->SetSprite(LandmarkData.Sprite);
}

// Called when the game starts or when spawned
void ARDSpawnableLandmark::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARDSpawnableLandmark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

