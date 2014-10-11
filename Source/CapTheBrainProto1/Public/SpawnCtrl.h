

#pragma once

#include "Item.h"
#include "GameFramework/Actor.h"
#include "SpawnCtrl.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAINPROTO1_API ASpawnCtrl : public AActor
{
	GENERATED_UCLASS_BODY()

	virtual void Tick(float)override;

private:
	float delay;
	float timer;
};
