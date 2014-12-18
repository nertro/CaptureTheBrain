// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BrainzlapGameInstance.h"
#include <vector>

class ACapTheBrainCharacter;
/**
 * 
 */
class CAPTHEBRAIN_API ItemEffect
{
public:
	ItemEffect();
	~ItemEffect();

	virtual void Activate(ACapTheBrainCharacter*) = 0;
	virtual void Deactivate(ACapTheBrainCharacter*) = 0;

protected:
	void ChangeUI(ACapTheBrainCharacter* player);
	void MakeSound();
	void ChangeSpeed(ACapTheBrainCharacter* player, float speedChange, bool onOthers);
	void ResetSpeed(ACapTheBrainCharacter* player, float speedChange);

	bool onOthers;

	UBrainzlapGameInstance* gameInstance;
};
