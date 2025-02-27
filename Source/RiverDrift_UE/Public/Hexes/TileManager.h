// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileManager.generated.h"

class UDA_TileBase;

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


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BuildGrid();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
