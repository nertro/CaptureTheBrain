// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnCtrl.h"

#include "SpawnPoint.h"
#include "EngineUtils.h"


ASpawnCtrl::ASpawnCtrl(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	delay = 4.5f;
	timer = 0;
	brainBaseSet = false;
}

void ASpawnCtrl::BeginPlay()
{
	Super::BeginPlay();
	this->SpawnBrain();

	for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
	{
		if (SpawnItr->GetName().Compare("SpawnPoint") == 1)
		{
			itemSpawnPoints.push_back(*SpawnItr);
		}
	}

	for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
	{
		if (SpawnItr->GetName().Compare("BrainBase") == 1)
		{
			brainBases.push_back(*SpawnItr);
		}
	}

	for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
	{
		if (SpawnItr->GetName().Compare("BrainSpawnPoint") == 0)
		{
			BrainSpawnPoint = *SpawnItr;
		}
	}
}

void ASpawnCtrl::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	timer += DeltaSeconds;
	if (timer > delay)
	{
		UWorld* World = GetWorld();
		float pointNo = FMath::FRandRange(1, 4);
		int newPoint = (int)pointNo;
		FString name = "SpawnPoint";
		name.AppendInt(newPoint);
		for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
		{
			int32 comp = SpawnItr->GetName().Compare(name);
			if (SpawnItr->GetName().Compare(name) == 0 && !SpawnItr->occupied)
			{
				SpawnItr->SpawnNewItem();
			}
		}

		timer = 0;
	}
}

void ASpawnCtrl::SpawnBrain()
{
	UWorld* World = GetWorld();
	FString name = "BrainSpawnPoint";
	for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
	{
		int32 comp = SpawnItr->GetName().Compare(name);
		if (SpawnItr->GetName().Compare(name) == 0 && !SpawnItr->occupied)
		{
			SpawnItr->SpawnNewItem();
		}
	}
}

void ASpawnCtrl::SpawnBrainBase()
{
	UWorld* World = GetWorld();
	float pointNo = FMath::FRandRange(1, 3);
	int newPoint = (int)pointNo;
	FString name = "BrainBase";
	name.AppendInt(newPoint);
	for (TActorIterator<ASpawnPoint>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
	{
		int32 comp = SpawnItr->GetName().Compare(name);
		if (SpawnItr->GetName().Compare(name) == 0 && !SpawnItr->occupied)
		{
			currentSpawn = newPoint;
			SpawnItr->SpawnNewItem();
		}
	}
}

