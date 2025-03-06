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

	ASpawnableTile* tile = CreateTile( offset, prefab, _owner);

	return tile;
}

//should standardize your calls
ASpawnableTile* ASpawnableTile::CreateTile(FOffsetCoord c, FTileData prefab, AActor* _owner)
{
	//UE_LOGFMT(LogTemp, Log, "Creat tile gets called");

	ASpawnableTile* tile;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = _owner;
	SpawnInfo.ObjectFlags |= RF_Transient;


	FVector worldPos;
	
	worldPos.X = (((c.x - abs(c.y) * 0.5f) + abs(c.y) / 2) * (prefab.cellSize * 2.0f)) ;//currently hard coded for even-r offsetting

	worldPos.Y = (c.y * (prefab.cellWidth * 1.5f));
	worldPos.Z = 0.0f;

	//worldPos.X = c.y < 0 ? worldPos.X: worldPos.X *-1;

	FTransform transform;

	
	tile = _owner->GetWorld()->SpawnActor<ASpawnableTile>(
		ASpawnableTile::StaticClass(), worldPos, FRotator::ZeroRotator, SpawnInfo);
	
	tile->TileType = prefab;
	//tile->TileType = prefab.ETileType;



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
		//UE_LOGFMT(LogTemp, Log, "Sprite for the {0} Data Asset HAS been set ", UEnum::GetValueAsString(prefab.ETileType));

		tile->SpriteComponent->SetSprite(prefab.sprite);
	}
	else {
		UE_LOGFMT(LogTemp, Error, "Sprite for the {0} Data Asset HAS NOT been set ", UEnum::GetValueAsString(prefab.ETileType));
	}
	tile->SpriteComponent->SetWorldRotation(FRotator(0, 0, -90));

	tile->offsetCoord = FOffsetCoord::FOffsetCoord(c.x/*-c.y/2*/, c.y);//-c.y/2 from catlike

	//set tile's coordinates
	tile->HexCoord = UHexLibrary::offset_to_cube(tile->offsetCoord);

	

	//prefab.sprite

	return tile;
}

void ASpawnableTile::UpgradeTile(FTileData NewType)
{
	this->TileType = NewType;
	SpriteComponent->SetSprite(NewType.sprite);

	
}


// Sets default values
ASpawnableTile::ASpawnableTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOGFMT(LogTemp, Log, "ASPawnableTile constr called");

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

