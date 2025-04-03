// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/RDBillboardGroupBase.h"
#include "PaperSpriteComponent.h"

// Sets default values
ARDBillboardGroupBase::ARDBillboardGroupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->SetRootComponent(this->CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));
	ReferenceTile = this->CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteComponent"));
	ReferenceTile->AttachToComponent(this->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);

}

// Called when the game starts or when spawned
void ARDBillboardGroupBase::BeginPlay()
{
	Super::BeginPlay();

	ReferenceTile->DestroyComponent();

}

// Called every frame
void ARDBillboardGroupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

