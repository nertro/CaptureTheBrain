// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SpawnPoint.h"

#include "GameFramework/Actor.h"
#include "CollectableItem.generated.h"

/**
 * 
 */

class UBrainzlapGameInstance;

UCLASS()
class CAPTHEBRAIN_API ACollectableItem : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Item)
		TSubobjectPtr<class UCapsuleComponent> Capsule;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Item)
		ASpawnPoint* MySpawnPoint;
	
protected:
	UBrainzlapGameInstance* gameInstance;

	void BeginPlay() override;
};
