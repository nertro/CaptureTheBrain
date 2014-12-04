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
}

void ItemEffect::MakeSound()
{}

void ItemEffect::ChangeSpeed(ACapTheBrainCharacter* player, float speedChange, bool onOthers)
{
	if (onOthers)
	{
		for (std::vector<ACapTheBrainCharacter*>::iterator itr = ActorAdministrator::GetInstance()->players.begin(); itr != ActorAdministrator::GetInstance()->players.end(); itr++)
		{
			if ((*itr) != player && !(*itr)->hasShield && !(*itr)->isSlow)
			{
				(*itr)->SpeedBuffer *= speedChange;
				(*itr)->isSlow = true;
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