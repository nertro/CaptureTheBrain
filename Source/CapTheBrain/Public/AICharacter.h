// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CapTheBrainCharacter.h"
#include "CTBAIController.h"

#include "AICharacter.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API AAICharacter : public ACapTheBrainCharacter
{
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = BlueprintDefaults)
		FVector startLocation;

	UFUNCTION(BlueprintCallable, Category = AICharacter)
		bool GetHasBrain();

	virtual void Tick(float deltaSeconds) override;

	bool hasNoGoal;
	
protected:
	virtual void BeginPlay() override;
};
