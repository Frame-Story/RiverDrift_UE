// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../HexLibrary.h"
#include "../Hexes/AA_SpawnableTile.h"
#include "TileManager.generated.h"


class ASpawnableTile;
struct FHex;
struct FOffsetCoord;
enum TileType;
class ARD_GameMode;
//struct FTileData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTilePlacedSignature, ETileType, NextTile);

UCLASS()
class RIVERDRIFT_UE_API ATileManager : public AActor
{
	GENERATED_BODY()


	// --  VARS ---

public:	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> TileDataTable;

	static ASpawnableTile* dummy_tile;

	UPROPERTY(BlueprintReadOnly)
	FOnTilePlacedSignature D_OnTilePlacedDelegate;


protected:
	UPROPERTY(VisibleInstanceOnly)
	FTileData NextTileToPlace; //needs to be a pointer as c++ can't tell how to allocate its size

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FVector3f, ASpawnableTile* > RD_TileMap; //I think this is actually unneeded?


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpawnableTile> DefaultSpawnableTileBP;


	int fTotalRowsWeight;

private:
	TObjectPtr<ARD_GameMode> GameMode;
	
	// --  FUNCS ---


public:

	// Sets default values for this actor's properties
	ATileManager();

	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	//UDA_TileBase* TileFormat;

	UFUNCTION(BlueprintCallable)
	bool TileIsFilled(FHex hex, ASpawnableTile*& tile); //expose - change to isFilled
	

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FTileData SelectRandomTileType( /*bool& valid*/);//change to selectRandomTileFormat
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	//returns the tile that the tilemanager is currently going to return next. defaults to generating a new one first
	FTileData GetNextTileToPlace(bool generateNew = true);

	void UpgradeTile(FTileData format, ASpawnableTile* tile);

	FTileData LookupTileType(ETileType tileType, FString contextMessage);

	UFUNCTION()
	void SetTileWeights();

protected:
	//variables
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BuildGrid(); //implemented in c++ as BuildGrid_Implementation - able to be overriden by blueprints - largely placeholder until player input is working

	//private backend to initialize tile
	ASpawnableTile* SpawnTile(FHex hexCoord, FTileData format);

	UFUNCTION(BlueprintCallable) 
	ASpawnableTile* PlaceTile_XY(FOffsetCoord offsetCoord, FTileData format);
	UFUNCTION(BlueprintCallable)
	ASpawnableTile* PlaceTile_QRS(FHex hexCoord, FTileData format);

	//arguably unecessary wrapper function, just calls spawnTile and looks up blank format
	ASpawnableTile* CreateBlankTile(FHex hexCoord);

	void PlaceNeighbors(ASpawnableTile* tile);

};
