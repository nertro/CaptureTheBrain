// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"

#include "CTBAIController.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ACTBAIController : public AAIController
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AIController)
		UBlackboardData* Blackboard;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AIController)
		UBehaviorTree* BehaviorTree;

protected:
	void BeginPlay() override;
};
