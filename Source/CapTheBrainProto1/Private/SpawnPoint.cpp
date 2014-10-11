

#include "CapTheBrainProto1.h"
#include "SpawnPoint.h"
#include "SpawnCtrl.h"
#include "Item.h"


ASpawnPoint::ASpawnPoint(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	occupied = false;
	SpawnBox = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SpawnPoint"));
	RootComponent = SpawnBox;
}

void ASpawnPoint::SpawnNewItem()
{
	if (ItemBP)
	{
		occupied = true;
		UWorld* const World = GetWorld();
		AItem* SpawnItem = (AItem*)World->SpawnActor(ItemBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->MySpawnPoint = this;
	}
}


