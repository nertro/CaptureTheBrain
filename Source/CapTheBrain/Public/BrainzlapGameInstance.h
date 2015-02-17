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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	TArray<ACapTheBrainCharacter*> players;

	std::vector<AArrow*> arrows;

	UFUNCTION(BlueprintCallable, Category = GameInstance)
	ASpawnPoint* GetTargetItem();

	UFUNCTION(BlueprintCallable, Category = GameInstance)
	void CleanUp();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
	ABrainPickup* brain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
	ABrainBase* brainBase;

	ASpawnCtrl* spawnCtrl;

	std::vector<ASpawnPoint*> itemSpawnPoints;

	std::vector<ASpawnPoint*> brainBases;
	ASpawnPoint* BrainSpawnPoint;

	ACapTheBrainCharacter* playerWithBrain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameInstance)
	bool gameOver;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameMode)
	bool loadCredits;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
    int32 minutes;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	int32 playerCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	int32 playersSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	TArray<UMaterialInterface*> playerMats;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	TArray<bool> maleChar;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	AActor* curCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	bool restart;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	bool introPlayed;
};
