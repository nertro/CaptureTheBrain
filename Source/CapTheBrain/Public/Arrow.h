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
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UMaterialInterface* redMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UMaterialInterface* blueMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UMaterialInterface* greenMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UStaticMesh* StaticMesh;

	void PointToTarget(AActor*);

	void ChangeMaterial(bool red, bool green, bool blue);
};
