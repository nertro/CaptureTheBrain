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
		if (!player->myControllerHUD)
		{
			player->myControllerHUD = Cast<ACharacterHUD>(Cast<APlayerController>(player->Controller)->GetHUD());
		}
		player->myControllerHUD->PlayerHasItem = false;
	}
}

void ItemEffect::MakeSound()
{}

void ItemEffect::ChangeSpeed(ACapTheBrainCharacter* player, float speedChange, bool onOthers)
{
	ABrainzlabGameState* gameState = Cast<ABrainzlabGameState>(player->GetWorld()->GameState);
	if (onOthers)
	{
		for (int i = 0; i < gameState->characters.Num(); i++)
		{
			if (gameState->characters[i] != player && !gameState->characters[i]->hasShield && !gameState->characters[i]->isSlow)
			{
				gameState->characters[i]->SpeedBuffer *= speedChange;
				gameState->characters[i]->isSlow = true;
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