// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectZapp.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"
#include "BrainPickup.h"
#include "ActorAdministrator.h"

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
	for (std::vector<ACapTheBrainCharacter*>::iterator itr = ActorAdministrator::GetInstance()->players.begin(); itr != ActorAdministrator::GetInstance()->players.end(); itr++)
	{
		if (!(*itr)->hasShield && (*itr)->hasBrain)
		{
			(*itr)->GotHit = true;
			ActorAdministrator::GetInstance()->arrow->Destroy();
			(*itr)->hasBrain = false;
		}
	}
}
