#pragma once

#include "CoreMinimal.h"
//#include "../HexLibrary.h"
#include "TileData.generated.h"
/**
 *
 */

class UPaperSprite;

UENUM(BlueprintType)
enum class ETileType : uint8
{
	TE_Blank UMETA(DisplayName = "Blank"),
	TE_field UMETA(DisplayName = "field"),
	TE_forest UMETA(DisplayName = "forest"),
	TE_mountain UMETA(DisplayName = "mountain"),
	TE_river UMETA(DisplayName = "river"),
	TE_town UMETA(DisplayName = "town"),
	TE_mystery UMETA(DisplayName = "mystery"),
};

USTRUCT()
struct RIVERDRIFT_UE_API FTileData : public FTableRowBase
{
	GENERATED_BODY()


public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	UPaperSprite* sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	ETileType ETileType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	bool bIsPlayerTraversible;


	UPROPERTY(BlueprintReadWrite)
	float cellSize = 250.0f;

	float cellWidth = cellSize;
	float cellHeight = cellSize;

};