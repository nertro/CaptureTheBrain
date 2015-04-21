// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"

#include "BrainzlapGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API UBrainzlapGameInstance : public UGameInstance
{
	GENERATED_UCLASS_BODY()

	/*UFUNCTION(BlueprintCallable, Category = GameInstance)
	ASpawnPoint* GetTargetItem();*/

	UFUNCTION(BlueprintCallable, Category = GameInstance)
	void CleanUp();

	UFUNCTION(BlueprintCallable, Category = GameInstance)
	void RestartGame();

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
	TArray<UMaterialInterface*> KIMats;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	TArray<bool> maleChar;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	AActor* curCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	bool restart;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	bool introPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	bool wasInExplore;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameMode)
	bool gameStarted;
};
