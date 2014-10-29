// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnCtrl.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ASpawnCtrl : public AActor
{
	GENERATED_UCLASS_BODY()

	virtual void Tick(float)override;

private:
	float delay;
	float timer;
	
};
