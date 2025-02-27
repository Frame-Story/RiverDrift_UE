// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/DA_TileBase.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Hexes/AA_SpawnableTile.h"
#include "Kismet//KismetMathLibrary.h"
#include "Engine/World.h"

//
//AA_SpawnableTile* AA_SpawnableTile::CreateTile(int x, int y, UDA_TileBase* prefab, AActor* _owner)
//{
//
//	AA_SpawnableTile* tile;
//
//	FActorSpawnParameters SpawnInfo;
//	SpawnInfo.Owner = _owner;
//	SpawnInfo.ObjectFlags |= RF_Transient;
//
//
//
//	FVector worldPos;
//	worldPos.X = (x + y * 0.5f - y / 2) * (prefab->cellSize * 2.0f);
//	worldPos.Y = y * (prefab->cellWidth * 1.5f);
//	worldPos.Z = 0.0f;
//
//	FTransform transform = new FTRansfor;
//
//	tile = _owner->GetWorld()->SpawnActor()
//
//	UDA_TileBase* nTile;
//	nTile = NewObject<UDA_TileBase>();
//
//		//tile = _owner->GetWorld()->SpawnActor<AA_SpawnableTile>(AA_SpawnableTile:: , worldPos, FRotator::ZeroRotator, SpawnInfo);
//
//		////SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
//
//
//		////tile.offsetCoord = new OffsetCoord(x, y);
//		////tile.hexCoord = OffsetCoord.OffsetToCube(new OffsetCoord(x, y));
//		////tile.SetHexCoord();
//		////tile.SetOffsetCoord();
//
//		//FOffsetCoord* ptr = new FOffsetCoord(x, y);
//
//		//tile->offsetCoord = *(new FOffsetCoord(x, y));
//
//		//tile->HexCoord = UHexLibrary::offset_to_cube(FOffsetCoord(x, y));
//		////FOffsetCoord.OffsetToCube(new FOffsetCoord(x, y));
//
//		//tile->Neighbors = *new TArray<FHex>();
//
//		//for (FHex direction : UHexLibrary::hex_directions) {
//
//		//	FHex neighbor = UHexLibrary::hex_add(tile->HexCoord, direction);
//
//		//	tile->Neighbors.Emplace(neighbor);
//		//}
//		return tile;
//}