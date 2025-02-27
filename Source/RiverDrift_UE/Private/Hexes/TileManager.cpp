// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/TileManager.h"
#include "Hexes/AA_SpawnableTile.h"
#include "Logging/StructuredLog.h"


// Sets default values
ATileManager::ATileManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATileManager::BeginPlay()
{
	Super::BeginPlay();

	UE_LOGFMT(LogTemp, Log, "tilemanager begin play called from cpp class");

	
}

void ATileManager::BuildGrid_Implementation()
{
	UE_LOGFMT(LogTemp, Log, "tilemanager build grid called from cpp class");

	if (this->TileFormat != nullptr) {
		ASpawnableTile* startTile = ASpawnableTile::CreateTile(0, 0, this->TileFormat, this);

	}
	else {
		UE_LOGFMT(LogTemp, Log, "nope the ref is borken lol");

	}

}


// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

