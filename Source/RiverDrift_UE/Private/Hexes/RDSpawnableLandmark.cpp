// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/RDSpawnableLandmark.h"
#include "Hexes/AA_SpawnableTile.h"
#include "TileManager.cpp"

// Sets default values
ARDSpawnableLandmark::ARDSpawnableLandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

