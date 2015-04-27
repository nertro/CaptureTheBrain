// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "SpawnCtrl.h"
#include "SpawnPoint.h"
#include "CapTheBrainCharacter.h"

#include "BrainzlabGameState.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ABrainzlabGameState : public AGameState
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
		TArray<TWeakObjectPtr<ACapTheBrainCharacter>> characters;

	UPROPERTY()
		TArray<TWeakObjectPtr<AArrow>> arrows;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
		ABrainPickup* brain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
		ABrainBase* brainBase;

	UPROPERTY()
		ASpawnCtrl* spawnCtrl;

	UPROPERTY()
		TArray<ASpawnPoint*> itemSpawnPoints;

	UPROPERTY()
		TArray<ASpawnPoint*> brainBases;

	UPROPERTY()
		ASpawnPoint* BrainSpawnPoint;

	TWeakObjectPtr<ACapTheBrainCharacter> playerWithBrain;

	void DisableActorInScene(AActor* actor);

	void EnableActorInScene(AActor* actor);
};
