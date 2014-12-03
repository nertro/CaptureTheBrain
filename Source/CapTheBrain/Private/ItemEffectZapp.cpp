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
			FVector newBrainLocation = (*itr)->GetActorLocation();
			(*itr)->SetActorLocation((*itr)->startPosition);
			(*itr)->SetActorRotation((*itr)->startRotation);
			ActorAdministrator::GetInstance()->brain->Destroy();
			(*itr)->hasBrain = false;

			UWorld* const World = player->GetWorld();
			ACollectableItem* Brain = (ACollectableItem*)World->SpawnActor(player->BrainBP);
			Brain->SetActorLocation(newBrainLocation);
		}
	}
}
