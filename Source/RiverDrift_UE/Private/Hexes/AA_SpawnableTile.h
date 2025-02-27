#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../HexLibrary.h"
#include "AA_SpawnableTile.generated.h"

UCLASS()
class ASPawnableTile : public AActor
{

	GENERATED_BODY()

public:




	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	TArray<FHex> Neighbors;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	FHex HexCoord;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	FOffsetCoord offsetCoord;





	UFUNCTION()
	static ASPawnableTile* CreateTile(const FHex& h, UDA_TileBase* prefab, AActor* _owner);

	static ASPawnableTile* CreateTile(int x, int y, UDA_TileBase* prefab, AActor* _owner);


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UDA_TileBase> TileType;

};

