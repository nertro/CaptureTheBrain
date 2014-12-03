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
	for (std::vector<ACapTheBrainCharacter*>::iterator itr = ItemManager::GetInstance()->players.begin(); itr != ItemManager::GetInstance()->players.end(); itr++)
	{
		if (!(*itr)->hasShield && (*itr)->hasBrain)
		{
			FVector newBrainLocation = (*itr)->GetActorLocation();
			(*itr)->SetActorLocation((*itr)->startPosition);
			(*itr)->SetActorRotation((*itr)->startRotation);
			(*itr)->DestroyArrowPointer();
			(*itr)->brain->Destroy();
			(*itr)->hasBrain = false;

			UWorld* const World = player->GetWorld();
			ACollectableItem* Brain = (ACollectableItem*)World->SpawnActor(player->BrainBP);
			Brain->SetActorLocation(newBrainLocation);
		}
	}
}
