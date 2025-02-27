// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/TileManager.h"
#include "Hexes/AA_SpawnableTile.h"
#include "HexLibrary.h"
#include "Rendering/RenderingSpatialHash.h"
#include "Math/MathFwd.h"
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

void ATileManager::PlaceTile_XY_Implementation(FPoint point)
{
	UE_LOGFMT(LogTemp, Log, "placing tile with xy coords x {0} y {1}", point.x, point.y);

}



void ATileManager::PlaceTile_QRS_Implementation(FHex hexCoord)
{
	UE_LOGFMT(LogTemp, Log, "placing tile with hex coords q {0} r {1} s {2} ", hexCoord.q, hexCoord.r, hexCoord.s);
}

// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

