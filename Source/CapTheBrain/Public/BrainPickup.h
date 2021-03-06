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

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		USkeletalMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		USkeletalMesh* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		bool GotCollected;
	
	//used in animation blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		ACapTheBrainCharacter* myPlayer;
	
	void AttachToHead(ACapTheBrainCharacter* player);
	void DetachFromHead(ACapTheBrainCharacter* player, FVector newLocation);
};
