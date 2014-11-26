// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CapTheBrainCharacter.h"
#include <vector>
/**
 * 
 */
class CAPTHEBRAIN_API UsableItem
{
public:
	UsableItem();
	~UsableItem();

	virtual void Use(ACapTheBrainCharacter* player){}
	virtual void Use(std::vector<ACapTheBrainCharacter*> otherPlayers){}
	virtual void Tick(ACapTheBrainCharacter* player){}
	virtual void Tick(std::vector<ACapTheBrainCharacter*> otherPlayers){}
	virtual void ResetState(ACapTheBrainCharacter* player){}
	virtual void ResetState(std::vector<ACapTheBrainCharacter*> otherPlayers){}

	bool canTick;
	bool effectOnMultiblePlayers;
};
