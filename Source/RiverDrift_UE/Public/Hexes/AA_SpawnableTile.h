#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TileData.h"
#include "../HexLibrary.h"
#include "AA_SpawnableTile.generated.h"

class UPaperSpriteComponent;
struct FTileData;
UCLASS()
class ASpawnableTile : public AActor
{

	GENERATED_BODY()

public:


	ASpawnableTile();


	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Tiles")
	TArray<FHex> Neighbors;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Tiles")
	FHex HexCoord;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Tiles")
	FOffsetCoord offsetCoord;





	UFUNCTION()
	static ASpawnableTile* CreateTile(const FHex& h, FTileData prefab, AActor* _owner);

	static ASpawnableTile* CreateTile(int x, int y, FTileData prefab, AActor* _owner);


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTileData TileType;


	UPaperSpriteComponent* SpriteComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

