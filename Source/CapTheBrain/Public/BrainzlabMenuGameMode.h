// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BrainPickup.h"

#include "GameFramework/GameMode.h"
#include "BrainzlabMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ABrainzlabMenuGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = GameMode)
	void StartNewGame();

	UFUNCTION(BlueprintCallable, Category = GameMode)
	void DisableController(APlayerController* ctrl);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	TArray<UMaterialInterface*> profMats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	TArray<UMaterialInterface*> profInMats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	USkeletalMesh* prof;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	USkeletalMesh* profIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	USkeletalMesh* brain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameMode)
	FVector actorPos;
};
