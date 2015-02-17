// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffect.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"
#include "PlayerCharacter.h"

ItemEffect::ItemEffect()
{
}

ItemEffect::~ItemEffect()
{
}

void ItemEffect::ChangeUI(ACapTheBrainCharacter* player)
{
	if (player->IsA(APlayerCharacter::StaticClass()))
	{
		player->myControllerHUD->PlayerHasItem = false;
	}
}

void ItemEffect::MakeSound()
{}

void ItemEffect::ChangeSpeed(ACapTheBrainCharacter* player, float speedChange, bool onOthers)
{
	gameInstance = Cast<UBrainzlapGameInstance>(player->GetGameInstance());
	if (onOthers)
	{
		for (int i = 0; i < gameInstance->players.Num(); i++)
		{
			if (gameInstance->players[i] != player && !gameInstance->players[i]->hasShield && !gameInstance->players[i]->isSlow)
			{
				gameInstance->players[i]->SpeedBuffer *= speedChange;
				gameInstance->players[i]->isSlow = true;
			}
		}
	}
	else
	{
		if (!player->isFast)
		{
			player->SpeedBuffer /= speedChange;
			player->isFast = true;
		}
	}
}

void ItemEffect::ResetSpeed(ACapTheBrainCharacter* player, float speedChange)
{
	if (player->isSlow)
	{
		player->SpeedBuffer /= speedChange;
		player->isSlow = false;
	}
	else
	{
		player->SpeedBuffer *= speedChange;
		player->isFast = false;
	}
}