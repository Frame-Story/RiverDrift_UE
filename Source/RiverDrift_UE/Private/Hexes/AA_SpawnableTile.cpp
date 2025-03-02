#include "Hexes/AA_SpawnableTile.h"
#include "Hexes/TileData.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"
#include "RiverDrift_UE/RiverDrift_UE.h"
#include "Kismet//KismetMathLibrary.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
//#include
// "PaperSprite.h"
#include "Engine/World.h"


ASpawnableTile* ASpawnableTile::CreateTile(const FHex& h, FTileData prefab, AActor* _owner)
{

	FOffsetCoord offset = UHexLibrary::offset_from_cube(h);

	ASpawnableTile* tile = CreateTile(offset.col, offset.row, prefab, _owner);

	return tile;

}


ASpawnableTile* ASpawnableTile::CreateTile(int x, int y, FTileData prefab, AActor* _owner)
{
	//UE_LOGFMT(LogTemp, Log, "Creat tile gets called");

	ASpawnableTile* tile;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = _owner;
	SpawnInfo.ObjectFlags |= RF_Transient;



	FVector worldPos;
	worldPos.X = (x + y * 0.5f - y / 2) * (prefab.cellSize * 2.0f);
	worldPos.Y = y * (prefab.cellWidth * 1.5f);
	worldPos.Z = 0.0f;

	FTransform transform;

	tile = _owner->GetWorld()->SpawnActor<ASpawnableTile>(
		ASpawnableTile::StaticClass(), worldPos, FRotator::ZeroRotator, SpawnInfo);
	
	tile->TileType = prefab;
	//tile->TileType = prefab.ETileType;

	UE_LOGFMT(LogTemp, Log, "worldpos is: {0}", worldPos.ToString());


	//UPaperSpriteComponent* SpriteComponent = NewObject<UPaperSpriteComponent>(tile, UPaperSpriteComponent::StaticClass());
	//
	//if (SpriteComponent) {

	//	SpriteComponent->RegisterComponent();
	//	SpriteComponent->AttachToComponent(tile->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
	//}
	//else {
	//	UE_LOGFMT(LogTemp, Error, "NOt valid");

	//}


	if (IsValid(prefab.sprite)) {
		UE_LOGFMT(LogTemp, Log, "Sprite for the {0} Data Asset HAS been set ", UEnum::GetValueAsString(prefab.ETileType));

		tile->SpriteComponent->SetSprite(prefab.sprite);
	}
	else {
		UE_LOGFMT(LogTemp, Error, "Sprite for the {0} Data Asset HAS NOT been set ", UEnum::GetValueAsString(prefab.ETileType));
	}
	tile->SpriteComponent->SetWorldRotation(FRotator(0, 0, -90));

	tile->offsetCoord = FOffsetCoord::FOffsetCoord(x, y);

	//set tile's coordinates
	tile->HexCoord = UHexLibrary::offset_to_cube(tile->offsetCoord);

	//prefab.sprite

	return tile;
}

// Sets default values
ASpawnableTile::ASpawnableTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOGFMT(LogTemp, Log, "constr does get called");

	this->SetRootComponent(this->CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));
	SpriteComponent = this->CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteComponent"));
	SpriteComponent->AttachToComponent(this->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);

}

// Called when the game starts or when spawned
void ASpawnableTile::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOGFMT(LogTemp, Log, "Yeah it gets called");

}

// Called every frame
void ASpawnableTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOGFMT(LogTemp, Log, "Yeah it gets called");


}

