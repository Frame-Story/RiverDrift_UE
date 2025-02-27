#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../HexLibrary.h"
#include "AA_SpawnableTile.generated.h"

UCLASS()
class ASpawnableTile : public AActor
{

	GENERATED_BODY()

public:


	ASpawnableTile();


	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	TArray<FHex> Neighbors;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	FHex HexCoord;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
	FOffsetCoord offsetCoord;





	UFUNCTION()
	static ASpawnableTile* CreateTile(const FHex& h, UDA_TileBase* prefab, AActor* _owner);

	static ASpawnableTile* CreateTile(int x, int y, UDA_TileBase* prefab, AActor* _owner);


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UDA_TileBase> TileType;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

