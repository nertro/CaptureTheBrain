// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BrainBase.h"

#include "Arrow.generated.h"

class ACapTheBrainCharacter;
/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API AArrow : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
	TSubobjectPtr<class UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UStaticMesh* StaticMesh;

	void PointToTarget(AActor*);
};
