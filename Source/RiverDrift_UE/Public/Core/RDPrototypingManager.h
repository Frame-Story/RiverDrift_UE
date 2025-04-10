// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RDPrototypingManager.generated.h"

UCLASS()
class RIVERDRIFT_UE_API ARDPrototypingManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARDPrototypingManager();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bAllowOverridingWater;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
