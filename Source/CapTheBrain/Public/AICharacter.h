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
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = BlueprintDefaults)
		FVector startLocation;

	UFUNCTION(BlueprintCallable, Category = Hit)
	void CollectSphereReceiveHit(
	class UPrimitiveComponent * MyComp,
	class AActor * Other,
	class UPrimitiveComponent * OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult & Hit);

	virtual void Tick(float deltaSeconds) override;

	bool hasNoGoal;
	
};
