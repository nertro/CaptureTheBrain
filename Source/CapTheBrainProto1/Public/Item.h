

#pragma once

#include "SpawnPoint.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAINPROTO1_API AItem : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Item)
	TSubobjectPtr<class UCapsuleComponent> Capsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
	TSubobjectPtr<class USkeletalMeshComponent> MeshComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Item)
	ASpawnPoint* MySpawnPoint;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	UAnimationAsset* MyAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	USkeletalMesh* SkeletalMesh;
};
