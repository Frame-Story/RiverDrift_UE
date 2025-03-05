// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileManager.generated.h"

struct FTileData;
class ASpawnableTile;
struct FHex;
struct FOffsetCoord;

UCLASS()
class RIVERDRIFT_UE_API ATileManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileManager();

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> TileDataTable;
	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	//UDA_TileBase* TileFormat;

protected:


	//variables

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FVector3f, ASpawnableTile* > RD_TileMap; //I think this is actually unneeded?

	
	//functions
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	static ASpawnableTile* dummy_tile;
	bool tileExists(FHex hex, ASpawnableTile* &tile); //expose - change to isFilled
	void InsertIntoMap(int q, int r, int s, ASpawnableTile* tile); //expose - change to hex


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BuildGrid(); //remove

	UFUNCTION(BlueprintCallable) 
	void PlaceTile_XY(FOffsetCoord offsetCoord, FTileData format); //c++ func is PlaceTile_XY_Implementation
	UFUNCTION(BlueprintCallable)
	ASpawnableTile* PlaceTile_QRS(FHex hexCoord, FTileData format);
	ASpawnableTile* CreateBlankTile(FHex hexCoord);

	void PlaceNeighbors(ASpawnableTile* tile);

public:	
	FTileData SelectRandomTile(bool* valid);//change to selectRandomTileFormat
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
