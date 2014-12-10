// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnPoint.h"
#include "ActorAdministrator.h"
#include "CollectableItem.h"


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
		ActorAdministrator::GetInstance()->itemSpawnPoints.push_back(this);
	}
	else if (BrainBaseBP)
	{
		ActorAdministrator::GetInstance()->brainBases.push_back(this);
	}
	else if (BrainBP)
	{
		ActorAdministrator::GetInstance()->BrainSpawnPoint = this;
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
		ActorAdministrator::GetInstance()->brainBase = (ABrainBase*)SpawnItem;
	}
}


