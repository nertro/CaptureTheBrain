// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlapGameInstance.h"
#include "SpawnPoint.h"
#include "CollectableItem.h"

#define GameInstance Cast<UBrainzlapGameInstance>(GetGameInstance())

ASpawnPoint::ASpawnPoint(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	occupied = false;
	SpawnBox = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SpawnPoint"));
	RootComponent = SpawnBox;
}

void ASpawnPoint::BeginPlay()
{
	if (ItemBP)
	{
		GameInstance->itemSpawnPoints.push_back(this);
	}
	else if (BrainBaseBP)
	{
		GameInstance->brainBases.push_back(this);
	}
	else if (BrainBP)
	{
		GameInstance->BrainSpawnPoint = this;
		MeshComponent->AttachTo(RootComponent);
	}
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
}

void ASpawnPoint::SpawnNewBrain()
{
	if (BrainBP)
	{
		occupied = true;
		UWorld* const World = GetWorld();
		ACollectableItem* SpawnItem = (ACollectableItem*)World->SpawnActor(BrainBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->SetActorTransform(this->GetTransform());
		SpawnItem->MySpawnPoint = this;
		GameInstance->brain = (ABrainPickup*)SpawnItem;
	}
}

void ASpawnPoint::SpawnNewBase()
{
	if (BrainBaseBP)
	{
		occupied = true;
		UWorld* const World = GetWorld();
		ACollectableItem* SpawnItem = (ACollectableItem*)World->SpawnActor(BrainBaseBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->SetActorTransform(this->GetTransform());
		SpawnItem->MySpawnPoint = this;
		GameInstance->brainBase = (ABrainBase*)SpawnItem;
	}
}


