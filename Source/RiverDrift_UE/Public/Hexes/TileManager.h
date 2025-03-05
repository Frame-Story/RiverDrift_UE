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
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> TileDataTable;



	// Sets default values for this actor's properties
	ATileManager();

	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	//UDA_TileBase* TileFormat;

	static ASpawnableTile* dummy_tile;
	UFUNCTION(BlueprintCallable)
	bool TileIsFilled(FHex hex, ASpawnableTile*& tile); //expose - change to isFilled
	UFUNCTION(BlueprintCallable)
	void InsertIntoMap(int q, int r, int s, ASpawnableTile* tile); //expose - change to hex

	UFUNCTION(BlueprintCallable)
	FTileData SelectRandomTileType(bool& valid);//change to selectRandomTileFormat
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//variables

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FVector3f, ASpawnableTile* > RD_TileMap; //I think this is actually unneeded?

	
	//functions
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BuildGrid(); //implemented in c++ as BuildGrid_Implementation - able to be overriden by blueprints - largely placeholder until player input is working

	UFUNCTION(BlueprintCallable) 
	void PlaceTile_XY(FOffsetCoord offsetCoord, FTileData format);
	UFUNCTION(BlueprintCallable)
	ASpawnableTile* PlaceTile_QRS(FHex hexCoord, FTileData format);
	ASpawnableTile* CreateBlankTile(FHex hexCoord);

	void PlaceNeighbors(ASpawnableTile* tile);

};
