// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "SpawnCtrl.h"
#include "SpawnPoint.h"
#include "CapTheBrainCharacter.h"

#include "BrainzlapGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API UBrainzlapGameInstance : public UGameInstance
{
	GENERATED_UCLASS_BODY()

	std::vector<ACapTheBrainCharacter*> players;

	UFUNCTION(BlueprintCallable, Category = GameInstance)
	ASpawnPoint* GetTargetItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
	ABrainPickup* brain;

	AArrow* arrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
	ABrainBase* brainBase;

	ASpawnCtrl* spawnCtrl;

	std::vector<ASpawnPoint*> itemSpawnPoints;

	std::vector<ASpawnPoint*> brainBases;
	ASpawnPoint* BrainSpawnPoint;

	int32 playerCount;
	
};
