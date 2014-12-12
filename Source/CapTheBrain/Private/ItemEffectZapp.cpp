// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectZapp.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"
#include "BrainPickup.h"

ItemEffectZapp::ItemEffectZapp()
{
}

ItemEffectZapp::~ItemEffectZapp()
{
}

void ItemEffectZapp::Activate(ACapTheBrainCharacter* player)
{
	player->hasItem = false;
	this->ChangeUI(player);
	Zapp(player);
}

void ItemEffectZapp::Deactivate(ACapTheBrainCharacter* player)
{}

void ItemEffectZapp::Zapp(ACapTheBrainCharacter* player)
{
	gameInstance = Cast<UBrainzlapGameInstance>(player->GetGameInstance());
	for (std::vector<ACapTheBrainCharacter*>::iterator itr = gameInstance->players.begin(); itr != gameInstance->players.end(); itr++)
	{
		if (!(*itr)->hasShield && (*itr)->hasBrain)
		{
			(*itr)->GotHit = true;
			gameInstance->arrow->Destroy();
			(*itr)->hasBrain = false;
		}
	}
}
