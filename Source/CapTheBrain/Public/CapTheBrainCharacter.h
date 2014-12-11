// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "CharacterHUD.h"
#include "GameFramework/Character.h"
#include "SpawnCtrl.h"
#include "Arrow.h"
#include <vector>

#include "CapTheBrainCharacter.generated.h"

class ABrainPickup;
class ItemEffect;

UCLASS(config=Game)
class ACapTheBrainCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		TSubobjectPtr<class UCameraComponent> FollowCamera;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/**Speed Buffer witch can be changed per item */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float SpeedBuffer = 1.5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn)
		TSubclassOf<class AArrow> ArrowBP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation)
		bool GotHit = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
		bool isJumping = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
		bool FellDown = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
		float ArrowZLocation = 180;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn)
		TSubclassOf<class ACollectableItem> BrainBP;

	virtual void Tick(float deltaSeconds) override;
	virtual void BeginPlay() override;

	bool hasItem;
	bool isSlow, isFast, hasShield;

	UPROPERTY()
	ACharacterHUD* myControllerHUD;

	ItemEffect* currentItem;

	float slowTimer, fastTimer, shieldTimer;
	float itemTimerDelay = 5.;

	void DestroyArrowPointer();
	bool hasBrain;

	FVector startPosition;
	FRotator startRotation;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	/** Start Jump Animation, wich triggers jump movement*/
	void StartJump();

	/**My Stuff */
	bool firstUpdate;

	void PickUpItem();

	virtual void ReceiveHit(
	class UPrimitiveComponent * MyComp,
	class AActor * Other,
	class UPrimitiveComponent * OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult & Hit) override;

	void CollectItem();

	void UseItem();

	void TickItem(float deltaSeconds);

	void SpawnArrow();

	int score;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


};

