// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlapGameInstance.h"


UBrainzlapGameInstance::UBrainzlapGameInstance(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	playerCount = 3;
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

