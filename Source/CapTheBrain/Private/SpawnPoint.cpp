// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnPoint.h"
#include "BrainzlabGameState.h"
#include "CollectableItem.h"
#include "BrainPickup.h"


ASpawnPoint::ASpawnPoint(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	occupied = false;
	SpawnBox = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SpawnPoint"));
	RootComponent = SpawnBox;
}

void ASpawnPoint::BeginPlay()
{
	gameState = Cast<ABrainzlabGameState>(GetWorld()->GetGameState());

	if (ItemBP)
	{
		gameState->itemSpawnPoints.Add(this);
	}
	else if (BrainBaseBP)
	{
		gameState->brainBases.Add(this);
	}
	else if (BrainBP)
	{
		gameState->BrainSpawnPoint = this;
	}
}

void ASpawnPoint::SpawnNewItem()
{
	if (ItemBP)
	{
		occupied = true;
		ACollectableItem* SpawnItem = (ACollectableItem*)GetWorld()->SpawnActor(ItemBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->SetActorTransform(this->GetTransform());
		SpawnItem->MySpawnPoint = this;
	}
}

void ASpawnPoint::SpawnNewBrain()
{
	if (BrainBP && gameState)
	{
		occupied = true;

		//Instantiate Brain
		if (!gameState->brain)
		{
			ACollectableItem* SpawnItem = (ACollectableItem*)GetWorld()->SpawnActor(BrainBP);
			SpawnItem->Capsule->AttachTo(RootComponent);
			SpawnItem->SetActorTransform(this->GetTransform());
			SpawnItem->MySpawnPoint = this;
			gameState->brain = (ABrainPickup*)SpawnItem;
		}

		//Detach from Player
		if (gameState->brain->GotCollected)
		{
			gameState->brain->GetRootComponent()->DetachFromParent();
			gameState->brain->GotCollected = false;
			gameState->brain->myPlayer = nullptr;

			if (!gameState->brain->Capsule->IsActive())
			{
				gameState->brain->Capsule->Activate();
			}
		}
		
		//Collision and position Setup
		gameState->brain->Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		gameState->brain->SetRootComponent(gameState->brain->Capsule);
		gameState->brain->MeshComponent->AttachTo(gameState->brain->Capsule);

		gameState->brain->MeshComponent->SetRelativeLocation(FVector(0, 0, -20));

		gameState->brain->SetActorTransform(this->GetTransform());
	}
}

void ASpawnPoint::SpawnNewBase()
{
	if (BrainBaseBP)
	{
		occupied = true;
		ACollectableItem* SpawnItem = (ACollectableItem*)GetWorld()->SpawnActor(BrainBaseBP);
		SpawnItem->Capsule->AttachTo(RootComponent);
		SpawnItem->SetActorTransform(this->GetTransform());
		SpawnItem->MySpawnPoint = this;
		gameState->brainBase = (ABrainBase*)SpawnItem;
	}
}


