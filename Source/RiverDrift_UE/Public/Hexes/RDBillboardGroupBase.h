// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RDBillboardGroupBase.generated.h"

class UPaperSpriteComponent;

UCLASS()
class RIVERDRIFT_UE_API ARDBillboardGroupBase : public AActor
{
	GENERATED_BODY()
	
	// -- FUNCS --

public:	
	// Sets default values for this actor's properties
	ARDBillboardGroupBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// -- VARS --

public:	

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "tiles")
	TObjectPtr<UPaperSpriteComponent> ReferenceTile;

};
