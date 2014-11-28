// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffect.h"

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

void ItemEffect::ChangeSpeed(ACapTheBrainCharacter* player, int speedChange, bool onOthers)
{}

void ItemEffect::ActivateTick(ACapTheBrainCharacter* player, bool onOthers)
{}

void ItemEffect::DeactivateTick(ACapTheBrainCharacter* player, bool onOthers)
{}

void ItemEffect::AddPlayer(ACapTheBrainCharacter* player)
{}

void ItemEffect::RemovePlayer(ACapTheBrainCharacter* player)
{}