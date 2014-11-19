// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnCtrl.h"

#include "CollectableItem.h"
#include "SpawnPoint.h"
#include "EngineUtils.h"


ASpawnCtrl::ASpawnCtrl(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	delay = 4.5f;
	timer = 0;
	brainBaseSet = false;
	beginPlayReady = false;
	currentSpawn = 300;
}

void ASpawnCtrl::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
	{
		if (SpawnItr->ItemBP)
		{
			itemSpawnPoints.push_back(*SpawnItr);
		}
		else if (SpawnItr->BrainBaseBP)
		{
			brainBases.push_back(*SpawnItr);
		}
		else if (SpawnItr->BrainBP)
		{
			BrainSpawnPoint = *SpawnItr;
		}
	}

	this->SpawnBrain();

	beginPlayReady = true;
}

void ASpawnCtrl::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (beginPlayReady)
	{
		timer += DeltaSeconds;
		if (timer > delay)
		{
			float pointNo = FMath::FRandRange(0, itemSpawnPoints.size());
			int newPoint = (int)pointNo;
			if (!itemSpawnPoints[newPoint]->occupied)
			{
				itemSpawnPoints[newPoint]->SpawnNewItem();
			}
			timer = 0;
		}
	}
}

void ASpawnCtrl::SpawnBrain()
{
	BrainSpawnPoint->SpawnNewBrain();
}

void ASpawnCtrl::SpawnBrainBase()
{
	float pointNo = FMath::FRandRange(0, brainBases.size());
	int newPoint = (int)pointNo;
	if (currentSpawn != newPoint)
	{
		currentSpawn = newPoint;
		brainBases[newPoint]->SpawnNewBase();
		brainBaseSet = true;
	}
	else
	{
		SpawnBrainBase();
	}
}

