// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileManager.generated.h"

class UDA_TileBase;
class ASpawnableTile;
struct FHex;

UCLASS()
class RIVERDRIFT_UE_API ATileManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileManager();
	UPROPERTY(BlueprintReadWrite)
	UDA_TileBase* TileFormat;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FVector3f , ASpawnableTile* > RD_HexMap;

	void InsertIntoMap(int q, int r, int s, ASpawnableTile* tile);


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BuildGrid();

	UFUNCTION(BlueprintCallable) 
	void PlaceTile_XY(int x, int y, UDA_TileBase* format); //c++ func is PlaceTile_XY_Implementation
	UFUNCTION(BlueprintCallable)
	void PlaceTile_QRS(FVector3f hexCoord);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
