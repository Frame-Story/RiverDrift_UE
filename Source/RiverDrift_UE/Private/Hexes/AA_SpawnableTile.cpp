#include "Hexes/AA_SpawnableTile.h"
#include "Hexes/DA_TileBase.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"
#include "Kismet//KismetMathLibrary.h"
#include "Engine/World.h"


ASpawnableTile* ASpawnableTile::CreateTile(const FHex& h, UDA_TileBase* prefab, AActor* _owner)
{

	FOffsetCoord offset = UHexLibrary::offset_from_cube(h);

	ASpawnableTile* tile = CreateTile(offset.col, offset.row, prefab, _owner);

	return tile;

}


ASpawnableTile* ASpawnableTile::CreateTile(int x, int y, UDA_TileBase* prefab, AActor* _owner)
{
	//UE_LOGFMT(LogTemp, Log, "Creat tile gets called");

	ASpawnableTile* tile;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = _owner;
	SpawnInfo.ObjectFlags |= RF_Transient;



	FVector worldPos;
	worldPos.X = (x + y * 0.5f - y / 2) * (prefab->cellSize * 2.0f);
	worldPos.Y = y * (prefab->cellWidth * 1.5f);
	worldPos.Z = 0.0f;

	FTransform transform;
	

	UDA_TileBase* nTile;
	nTile = NewObject<UDA_TileBase>();


	tile = _owner->GetWorld()->SpawnActor<ASpawnableTile>(
		ASpawnableTile::StaticClass(), worldPos, FRotator::ZeroRotator, SpawnInfo);
	//tile = _owner->GetWorld()->SpawnActor<AA_SpawnableTile>(AA_SpawnableTile:: , worldPos, FRotator::ZeroRotator, SpawnInfo);

	////SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


	////tile.offsetCoord = new OffsetCoord(x, y);
	////tile.hexCoord = OffsetCoord.OffsetToCube(new OffsetCoord(x, y));
	////tile.SetHexCoord();
	////tile.SetOffsetCoord();

	//FOffsetCoord* ptr = new FOffsetCoord(x, y);

	//tile->offsetCoord = *(new FOffsetCoord(x, y));

	//tile->HexCoord = UHexLibrary::offset_to_cube(FOffsetCoord(x, y));
	////FOffsetCoord.OffsetToCube(new FOffsetCoord(x, y));

	//tile->Neighbors = *new TArray<FHex>();

	//for (FHex direction : UHexLibrary::hex_directions) {

	//	FHex neighbor = UHexLibrary::hex_add(tile->HexCoord, direction);

	//	tile->Neighbors.Emplace(neighbor);
	//}
	return tile;
}

// Sets default values
ASpawnableTile::ASpawnableTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

