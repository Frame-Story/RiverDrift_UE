#pragma once

#include "CoreMinimal.h"
//#include "../HexLibrary.h"
#include "RDBillboardGroupBase.h"
#include "TileData.generated.h"
/**
 *
 */

class UPaperSprite;
class ARDBillboardGroupBase;

UENUM(BlueprintType)
enum class ETileType : uint8
{
	TE_Blank UMETA(DisplayName = "Blank"),
	TE_River UMETA(DisplayName = "river"),
	TE_Field UMETA(DisplayName = "field"),
	TE_Forest UMETA(DisplayName = "forest"),
	TE_Mountain UMETA(DisplayName = "mountain"),
	TE_Town UMETA(DisplayName = "town"),
	TE_Mystery UMETA(DisplayName = "mystery"),
};

USTRUCT()
struct RIVERDRIFT_UE_API FTileData : public FTableRowBase
{
	GENERATED_BODY()


public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	UPaperSprite* Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	TSubclassOf<ARDBillboardGroupBase> Billboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	ETileType ETileType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	bool bIsPlayerTraversible;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float cellSize = 256.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float weight = 16.0f; //can we use non-whole ints?

	float cellWidth = cellSize;
	float cellHeight = cellSize;

};

USTRUCT()
struct RIVERDRIFT_UE_API FLandmarkKey : public FTableRowBase
{
	GENERATED_BODY()


public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	TArray<ETileType> Key;


};

USTRUCT()
struct RIVERDRIFT_UE_API FLandmarkData : public FTableRowBase
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	FLandmarkKey Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	UPaperSprite* Sprite;



};

