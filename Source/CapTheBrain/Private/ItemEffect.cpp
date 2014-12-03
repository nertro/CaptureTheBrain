// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffect.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"

ItemEffect::ItemEffect()
{
}

ItemEffect::~ItemEffect()
{
}

void ItemEffect::ChangeUI(ACapTheBrainCharacter* player)
{
	player->myControllerHUD->PlayerHasItem = false;
	player->hasItem = false;
}

void ItemEffect::MakeSound()
{}

void ItemEffect::ChangeSpeed(ACapTheBrainCharacter* player, float speedChange, bool onOthers)
{
	if (onOthers)
	{
		for (std::vector<ACapTheBrainCharacter*>::iterator itr = ItemManager::GetInstance()->players.begin(); itr != ItemManager::GetInstance()->players.end(); itr++)
		{
			if (*itr != player)
			{
				(*itr)->SpeedBuffer *= speedChange;
				(*itr)->isSlow = true;
			}
		}
	}
	else
	{
		player->SpeedBuffer *= speedChange;
		player->isFast = true;
	}
}