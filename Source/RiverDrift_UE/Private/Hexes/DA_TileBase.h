// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../HexLibrary.h"
#include "DA_TileBase.generated.h"

/**
 * 
 */

struct FOffsetCoord;

UENUM(BlueprintType)
enum class ETileType : uint8
{
	TE_Blank UMETA(DisplayName="Blank"),
	TE_field UMETA(DisplayName="field"),
	TE_forest UMETA(DisplayName="forest"),
	TE_mountain UMETA(DisplayName="mountain"),
	TE_river UMETA(DisplayName="river"),
	TE_town UMETA(DisplayName="town"),
	TE_mystery UMETA(DisplayName="mystery"),
};

UCLASS()
class UDA_TileBase : public UDataAsset
{
	GENERATED_BODY()


public:

	UPROPERTY(BlueprintReadWrite)
	float cellSize = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	ETileType ETileType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	bool bIsPlayerTraversible;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	TArray<FHex> Neighbors;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	FHex HexCoord;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	FOffsetCoord offsetCoord;


	float cellWidth = cellSize;
	float cellHeight = cellSize;

private:



	//functions

public:

	UFUNCTION()
	static UDA_TileBase* CreateTile(const FHex& h, UDA_TileBase* prefab, AActor* owner);

	static UDA_TileBase* CreateTile(int x, int y, UDA_TileBase* prefab, AActor* owner);

};
