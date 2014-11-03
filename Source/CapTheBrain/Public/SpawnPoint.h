// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Actor.h"
#include "SpawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ASpawnPoint : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Spawn)
	TSubobjectPtr<class UBoxComponent> SpawnBox;

	void SpawnNewItem();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn)
		TSubclassOf<class ACollectableItem> ItemBP;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Spawn)
		bool occupied;


private:
	bool bfirst;
	
};