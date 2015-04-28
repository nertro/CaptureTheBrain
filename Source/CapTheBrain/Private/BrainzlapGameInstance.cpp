// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlapGameInstance.h"
#include "PlayerCharacter.h"


UBrainzlapGameInstance::UBrainzlapGameInstance(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	gameOver = false;
}


//ASpawnPoint* UBrainzlapGameInstance::GetTargetItem()
//{
//	for (std::vector<ASpawnPoint*>::iterator itr = itemSpawnPoints.begin(); itr != itemSpawnPoints.end(); itr++)
//	{
//		if ((*itr)->occupied)
//		{
//			return (*itr);
//		}
//	}
//
//	return itemSpawnPoints[0];
//}


void UBrainzlapGameInstance::CleanUp()
{
	playerMats.Reset();
	KIMats.Reset();
	gameStarted = false;
}

void UBrainzlapGameInstance::RestartGame()
{
	gameOver = false;
	loadCredits = false;
	minutes = 3;
	playerCount = 0;
	playersSet = 0;
	maleChar.Reset();
	restart = false;
}
