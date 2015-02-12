// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "TimerWidget.h"

#include "EngineUtils.h"
#include "CapTheBrainArenaGameMode.h"
#include "BrainzlapGameInstance.h"


UTimerWidget::UTimerWidget(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	totalMinutes = minutesLeft = 1;
	totalSeconds = 60;
	secondsPassedOnLastUpdate = 0;
}


int32 UTimerWidget::SetSeconds()
{
	if (minutesLeft == 0 && secondsLeft == 0)
	{
		return secondsLeft;
	}

	secondsPassed = GetWorld()->TimeSeconds;
	secondsPassed = (int32)secondsPassed % totalSeconds;
	secondsLeft = totalSeconds - secondsPassed;

	if (secondsLeft == totalSeconds)
	{
		secondsLeft = 0;
	}

	return secondsLeft;
}

int32 UTimerWidget::SetMinutes()
{
	if (minutesLeft > 0 && secondsPassed - secondsPassedOnLastUpdate >= 1)
	{
		if (secondsLeft == totalSeconds-1)
		{
			minutesLeft -= 1;
		}
	}

	secondsPassedOnLastUpdate = secondsPassed;

	if (minutesLeft == 0 && secondsLeft == 0)
	{
		ACapTheBrainArenaGameMode* gameMode = Cast<ACapTheBrainArenaGameMode>(GetWorld()->GetAuthGameMode());
		gameMode->GameOver();
	}

	return minutesLeft;
}

ESlateVisibility::Type UTimerWidget::SetTimerVisibilitySingle()
{
	if (GetWorld()->GetAuthGameMode()->NumPlayers > 1)
	{
		return ESlateVisibility::Hidden;
	}

	return ESlateVisibility::Visible;
}

ESlateVisibility::Type UTimerWidget::SetTimerVisibilityMulti(ESlateVisibility::Type singleVisibility)
{
	if (singleVisibility == ESlateVisibility::Hidden)
	{
		return ESlateVisibility::Visible;
	}

	return ESlateVisibility::Hidden;
}

