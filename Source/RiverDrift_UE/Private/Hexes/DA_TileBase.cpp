// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/DA_TileBase.h"
#include "./HexLibrary.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet//KismetMathLibrary.h"
#include "Engine/World.h"

UDA_TileBase* UDA_TileBase::CreateTile(const FHex& h, UDA_TileBase* prefab, AActor* owner)
{
	FOffsetCoord offset = UHexLibrary::offset_from_cube(h);

	UDA_TileBase* tile = CreateTile(offset.col, offset.row, prefab, owner);

	return tile;

}


UDA_TileBase* UDA_TileBase::CreateTile(int x, int y, UDA_TileBase* prefab, AActor* owner)
{
	
	UDA_TileBase* tile;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = owner;
	SpawnInfo.ObjectFlags |= RF_Transient;


	
	FVector worldPos;
	worldPos.X = (x + y * 0.5f - y / 2) * (prefab->cellSize * 2.0f);
	worldPos.Y = y * (prefab->cellWidth * 1.5f);
	worldPos.Z = 0.0f;

	FTransform transform;

	tile = owner->GetWorld()->SpawnActor<UDA_TileBase>(prefab->GetClass(), worldPos, FRotator::ZeroRotator , SpawnInfo);


	//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


	//tile.offsetCoord = new OffsetCoord(x, y);
	//tile.hexCoord = OffsetCoord.OffsetToCube(new OffsetCoord(x, y));
	//tile.SetHexCoord();
	//tile.SetOffsetCoord();

	tile->offsetCoord = new FOffsetCoord(x, y);
		 
	tile->HexCoord = &UHexLibrary::offset_to_cube(x, y);
		//FOffsetCoord.OffsetToCube(new FOffsetCoord(x, y));

	tile->Neighbors = new TArray<FHex>();

	for (FHex direction : UHexLibrary::hex_directions) {

		FHex neighbor = UHexLibrary::hex_add(* tile->HexCoord , direction);

		tile->Neighbors->Add(neighbor);

	return tile;
}

