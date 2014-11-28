// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "CapTheBrainCharacter.h"

/**
 * 
 */
class CAPTHEBRAIN_API ItemEffect
{
public:
	ItemEffect();
	~ItemEffect();

protected:
	virtual void Activate() = 0;

	void ChangeUI(ACapTheBrainCharacter* player);
	void MakeSound();
	void ChangeSpeed(ACapTheBrainCharacter* player, float speedChange, bool onOthers);
	void ActivateTick(ACapTheBrainCharacter* player, bool onOthers);
	void DeactivateTick(ACapTheBrainCharacter* player, bool onOther);

	bool onOthers;
private:
	void AddPlayer(ACapTheBrainCharacter* player);
	void RemovePlayer(ACapTheBrainCharacter* player);
};
