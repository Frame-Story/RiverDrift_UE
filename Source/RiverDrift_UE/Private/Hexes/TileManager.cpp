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

	UE_LOGFMT(LogTemp, Log, "tilemanager begin play started from cpp class size of map is {0}", RD_HexMap.IsEmpty());

	BuildGrid();
	UE_LOGFMT(LogTemp, Log, "tilemanager begin play called from cpp class");

}

void ATileManager::InsertIntoMap(int q, int r, int s, ASpawnableTile* tile)
{
	RD_HexMap.Add(FVector3f(q, r, s), tile);
}


void ATileManager::PlaceTile_XY(int x, int y, UDA_TileBase* format) {
	FHex cubicCoord = UHexLibrary::offset_to_cube(FOffsetCoord(x, y));

	ASpawnableTile* tile = ASpawnableTile::CreateTile(x, y, this->TileFormat, this);
	
	UE_LOGFMT(LogTemp, Log, "placetile called || offset coords x {0} y {1} || cubic coords q {2} r {3} s {4} ", x, y, cubicCoord.q, cubicCoord.r, cubicCoord.s);
	this->InsertIntoMap(cubicCoord.q , cubicCoord.r, cubicCoord.s, tile);
	
}

void ATileManager::PlaceTile_QRS(FVector3f hexCoord)
{
}

void ATileManager::BuildGrid_Implementation()
{
	UE_LOGFMT(LogTemp, Log, "tilemanager build grid called from cpp class");

	if (this->TileFormat != nullptr) {
		ATileManager::PlaceTile_XY(0, 0, this->TileFormat);
		ATileManager::PlaceTile_XY(0, 1, this->TileFormat);
		ATileManager::PlaceTile_XY(1, 0, this->TileFormat);
		ATileManager::PlaceTile_XY(1, 1, this->TileFormat);

	}
	else {
		UE_LOGFMT(LogTemp, Log, "nope the ref is borken lol");

	}

}


//void ATileManager::PlaceTile_XY_Implementation(FPoint point)
//{
//	UE_LOGFMT(LogTemp, Log, "placing tile with xy coords x {0} y {1}", point.x, point.y);
//
//}
//
//
//
//void ATileManager::PlaceTile_QRS_Implementation(FVector3f hexCoord)
//{
//	UE_LOGFMT(LogTemp, Log, "placing tile with hex coords q {0} r {1} s {2} ", hexCoord.X, hexCoord.Y, hexCoord.Z);
//}

// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

