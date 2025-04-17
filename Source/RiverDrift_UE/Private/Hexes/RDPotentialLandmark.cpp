// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/RDPotentialLandmark.h"
#include "Hexes/TileData.h"
#include "Hexes/SpawnableTile.h"
#include "PaperSpriteComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ARDPotentialLandmark::ARDPotentialLandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	this->SetRootComponent(this->CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));
	Sprite = this->CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundPaperSpriteComponent"));
	Sprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);


}

void ARDPotentialLandmark::InitializeLandmark(TArray<ASpawnableTile*> _ComposingTiles, FLandmarkData _LandmarkData)
{
	//UE_LOGFMT(LogTemp, Fatal, "1");

	this->ComposingTiles = _ComposingTiles;
	LandmarkData = _LandmarkData;

	Sprite->SetSprite(LandmarkData.Sprite);

	//set the location to the average of each other location (i.e. the middle point between each vec)
	TArray<FVector> locations;
	for (ASpawnableTile* tile : ComposingTiles) {
		locations.Add(tile->GetActorLocation());
	}
	SetActorLocation(UKismetMathLibrary::GetVectorArrayAverage(locations));

	
}

// Called when the game starts or when spawned
void ARDPotentialLandmark::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARDPotentialLandmark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

