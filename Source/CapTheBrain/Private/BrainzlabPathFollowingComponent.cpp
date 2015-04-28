// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlabPathFollowingComponent.h"
#include "JumpNavArea.h"


UBrainzlabPathFollowingComponent::UBrainzlabPathFollowingComponent(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{

}

void UBrainzlabPathFollowingComponent::SetMoveSegment(int32 segmentStartIndex)
{
	Super::SetMoveSegment(segmentStartIndex);

	if (CharMovementComponent != NULL)
	{
		FNavPathPoint& SegmentStart = Path->GetPathPoints()[MoveSegmentStartIndex];

		if (FNavAreaHelper::HasJumpFlag(SegmentStart))
		{
			CharMovementComponent->SetMovementMode(EMovementMode::MOVE_Flying);
		}
		else if (FNavAreaHelper::HasFallFlag(SegmentStart))
		{
			CharMovementComponent->SetMovementMode(EMovementMode::MOVE_Falling);
		}
		else
		{
			CharMovementComponent->SetMovementMode(EMovementMode::MOVE_Walking);
		}

	}
}

void UBrainzlabPathFollowingComponent::SetMovementComponent(UNavMovementComponent* MoveComp)
{
	Super::SetMovementComponent(MoveComp);

	CharMovementComponent = Cast<UCharacterMovementComponent>(MovementComp);
}
