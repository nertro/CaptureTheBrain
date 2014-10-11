

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnPoint.generated.h"

/**
 * Class of Spawnpoints, checks if the Point is activated and spawns new Item
 */
UCLASS()
class CAPTHEBRAINPROTO1_API ASpawnPoint : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Spawn)
	TSubobjectPtr<class UBoxComponent> SpawnBox;

	void SpawnNewItem();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn)
	TSubclassOf<class AItem> ItemBP;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Spawn)
	bool occupied;


private:
	bool bfirst;
};
