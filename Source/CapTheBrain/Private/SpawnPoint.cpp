// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnPoint.h"

#include "CollectableItem.h"


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
		ACollectableItem* SpawnItem = (ACollectableItem*)World->SpawnActor(ItemBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->SetActorTransform(this->GetTransform());
		SpawnItem->MySpawnPoint = this;
	}
	else if (BrainBP)
	{
		occupied = true;
		UWorld* const World = GetWorld();
		ACollectableItem* SpawnItem = (ACollectableItem*)World->SpawnActor(BrainBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->SetActorTransform(this->GetTransform());
		SpawnItem->MySpawnPoint = this;
	}
}


