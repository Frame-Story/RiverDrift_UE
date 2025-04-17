// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/PotentialLandmark.h"

// Sets default values
APotentialLandmark::APotentialLandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APotentialLandmark::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APotentialLandmark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

