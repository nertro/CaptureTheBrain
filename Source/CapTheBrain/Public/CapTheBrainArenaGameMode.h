// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CapTheBrainArenaGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ACapTheBrainArenaGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	void GameOver();

	UFUNCTION(BlueprintCallable, Category = GameMode)
	void SetPlayerMaterial(APawn* pawn, UMaterialInterface* newMaterial);
/*
	virtual void StartNewPlayer(APlayerController*) override;
	
	virtual void BeginPlay() override;*/
};
