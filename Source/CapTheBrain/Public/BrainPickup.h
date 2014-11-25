// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CollectableItem.h"
#include "CapTheBrainCharacter.h"

#include "BrainPickup.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ABrainPickup : public ACollectableItem
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		TSubobjectPtr<class USkeletalMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		USkeletalMesh* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		bool GotCollected;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		ACapTheBrainCharacter* myPlayer;
	
	void AttachToHead(ACapTheBrainCharacter* player);
};
