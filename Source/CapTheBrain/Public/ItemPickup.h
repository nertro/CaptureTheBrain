// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CollectableItem.h"
#include "ItemPickup.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API AItemPickup : public ACollectableItem
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		TSubobjectPtr<class UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UStaticMesh* StaticMesh;
	
};
