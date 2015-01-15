// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CapTheBrainCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API APlayerCharacter : public ACapTheBrainCharacter
{
	GENERATED_UCLASS_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		TSubobjectPtr<class UCameraComponent> FollowCamera;

	void OrbitCamera();

protected:
	void BeginPlay() override;

	void Tick(float deltaSeconds) override;

	float step;
};
