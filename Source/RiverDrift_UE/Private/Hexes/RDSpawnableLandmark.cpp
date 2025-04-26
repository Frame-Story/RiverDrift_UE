// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/RDSpawnableLandmark.h"
#include "Kismet/KismetMathLibrary.h"
#include "Hexes/SpawnableTile.h"
#include "PaperSpriteComponent.h"

// Sets default values
ARDSpawnableLandmark::ARDSpawnableLandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->SetRootComponent(this->CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));
	Sprite = this->CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundPaperSpriteComponent"));
	Sprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
}

void ARDSpawnableLandmark::InitializeLandmark(TArray<ASpawnableTile*> _ComposingTiles, FLandmarkData _LandmarkData, bool _bIsPotential)
{
	this->ComposingTiles = _ComposingTiles;
	LandmarkData = _LandmarkData;

	Sprite->SetSprite(LandmarkData.Sprite);

	bIsPotential = _bIsPotential;
	if(_bIsPotential) {
		SetSpriteAlpha(Sprite, .75);
	}

	//set the location to the average of each other location (i.e. the middle point between each vec)
	TArray<FVector> locations;
	for (ASpawnableTile* tile : ComposingTiles) {
		locations.Add(tile->GetActorLocation());
	}
	SetActorLocation(UKismetMathLibrary::GetVectorArrayAverage(locations));

	Sprite->SetSprite(LandmarkData.Sprite);
}

void ARDSpawnableLandmark::SetIsPotential(bool b)
{
	SetSpriteAlpha(Sprite, 1);
	bIsPotential = b;
}

// Called when the game starts or when spawned
void ARDSpawnableLandmark::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARDSpawnableLandmark::SetSpriteAlpha(UPaperSpriteComponent* _Sprite, float alpha)
{
	FLinearColor NewColor = Sprite->GetSpriteColor();
	NewColor.A = 1;
	_Sprite->SetSpriteColor(NewColor);
}

// Called every frame
void ARDSpawnableLandmark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

