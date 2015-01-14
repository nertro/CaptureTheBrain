// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API UTimerWidget : public UUserWidget
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = Widget)
	int32 SetMinutes();

	UFUNCTION(BlueprintCallable, Category = Widget)
	int32 SetSeconds();

	UFUNCTION(BlueprintCallable, Category = Widget)
	ESlateVisibility::Type SetTimerVisibilitySingle();

	UFUNCTION(BlueprintCallable, Category = Widget)
	ESlateVisibility::Type SetTimerVisibilityMulti(ESlateVisibility::Type singleVisibility);

private:
	int32 totalMinutes;
	int32 totalSeconds;
	int32 minutesLeft;
	int32 secondsLeft;
	float secondsPassed;
	float secondsPassedOnLastUpdate;
};
