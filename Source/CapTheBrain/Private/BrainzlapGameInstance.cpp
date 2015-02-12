// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlapGameInstance.h"


UBrainzlapGameInstance::UBrainzlapGameInstance(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	gameOver = false;
}


ASpawnPoint* UBrainzlapGameInstance::GetTargetItem()
{
	for (std::vector<ASpawnPoint*>::iterator itr = itemSpawnPoints.begin(); itr != itemSpawnPoints.end(); itr++)
	{
		if ((*itr)->occupied)
		{
			return (*itr);
		}
	}

	return itemSpawnPoints[0];
}


void UBrainzlapGameInstance::CleanUp()
{
	std::vector<ACapTheBrainCharacter*> players;

	brain = nullptr;

	brainBase = nullptr;

	spawnCtrl = nullptr;

	std::vector<ASpawnPoint*> itemSpawnPoints;

	std::vector<ASpawnPoint*> brainBases;
	BrainSpawnPoint = nullptr;

	for (std::vector<ACapTheBrainCharacter*>::iterator itr = players.begin(); itr != players.end(); itr++)
	{
		(*itr) = nullptr;
	}

	for (std::vector<AArrow*>::iterator itr = arrows.begin(); itr != arrows.end(); itr++)
	{
		(*itr) = nullptr;
	}

	for (std::vector<ASpawnPoint*>::iterator itr = itemSpawnPoints.begin(); itr != itemSpawnPoints.end(); itr++)
	{
		(*itr) = nullptr;
	}

	for (std::vector<ASpawnPoint*>::iterator itr = brainBases.begin(); itr != brainBases.end(); itr++)
	{
		(*itr) = nullptr;
	}
}
