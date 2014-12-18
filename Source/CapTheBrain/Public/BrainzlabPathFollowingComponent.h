// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Navigation/PathFollowingComponent.h"
#include "BrainzlabPathFollowingComponent.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API UBrainzlabPathFollowingComponent : public UPathFollowingComponent
{
	GENERATED_UCLASS_BODY()
public:
	virtual void SetMoveSegment(int32 segmentStartIndex) override;

	virtual void SetMovementComponent(UNavMovementComponent* MoveComp) override;

protected: 
	UPROPERTY(transient)
		UCharacterMovementComponent* CharMovementComponent;
	
};
