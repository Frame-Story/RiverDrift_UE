// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/TileManager.h"
#include "Hexes/AA_SpawnableTile.h"
#include "HexLibrary.h"
#include "Hexes/TileData.h"
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

	//UE_LOGFMT(LogTemp, Log, "tilemanager begin play started from cpp class size of map is {0}", RD_HexMap.IsEmpty());

	BuildGrid();
	UE_LOGFMT(LogTemp, Log, "tilemanager begin play called from cpp class");

}

void ATileManager::InsertIntoMap(int q, int r, int s, ASpawnableTile* tile)
{
	//RD_HexMap.Add(FVector3f(q, r, s), tile); //removing hexmap for now
}


void ATileManager::PlaceTile_XY(FOffsetCoord offsetCoord, FTileData format) {

	UE_LOGFMT(LogTemp, Log, "placetile_XY called || offset coords x {0} y {1} ", offsetCoord.col, offsetCoord.row);
	//FTileData tileData = format.GetRow<FTileData>("");
	FHex cubicCoord = UHexLibrary::offset_to_cube(offsetCoord); //static instantiation of FHex? Dunaganq

	ATileManager::PlaceTile_QRS(cubicCoord, format);

	//ASpawnableTile* tile = ASpawnableTile::CreateTile(x, y, format, this);
	
	
}

void ATileManager::PlaceTile_QRS(FHex hexCoord, FTileData format)
{

	UE_LOGFMT(LogTemp, Log, "placetile_QRS called ||  cubic coords q {0} r {1} s {2} ", hexCoord.q, hexCoord.r, hexCoord.s);

	ASpawnableTile* tile = ASpawnableTile::CreateTile(hexCoord, format, this);

}

void ATileManager::BuildGrid_Implementation()
{
	UE_LOGFMT(LogTemp, Log, "tilemanager build grid called from cpp class");
	
	if (this->TileDataTable) {

		FPermissionListOwners names =  this->TileDataTable->GetRowNames();



		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				bool bTileIsValid = false;
				FTileData f = this->SelectRandomTile(&bTileIsValid);

				if (bTileIsValid) {
					this->PlaceTile_XY(FOffsetCoord(i,j), f);
				}
				else {
					UE_LOGFMT(LogTemp, Log, "bTileIsValid false, didn't place");

				}


			}
		}



	}
	else {
		UE_LOGFMT(LogTemp, Log, "tile data table ref not set");

	}
}


FTileData ATileManager::SelectRandomTile(bool* valid)
{
	FTileData tile;
	if (this->TileDataTable) {


		FPermissionListOwners names = this->TileDataTable->GetRowNames();
		int rand = FMath::RandRange(0, names.Num() - 1);
		FName name = names[rand];
		//auto temp = 
		UE_LOGFMT(LogTemp, Log, "randomly selected tile from row {0} ", name);

		tile = *this->TileDataTable->FindRow<FTileData>(name, "");//is this a dynamic instance of FTileData because it's returning a pointer? Dunaganq
		*valid = true;
		return tile;
	}
	else {
		UE_LOGFMT(LogTemp, Error, "ERROR: TileManager.TileDataTable ref not valid, make sure you set it");
		return tile;

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

