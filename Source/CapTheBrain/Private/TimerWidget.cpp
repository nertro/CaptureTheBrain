// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "TimerWidget.h"


UTimerWidget::UTimerWidget(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	totalMinutes = minutesLeft = 7;
	totalSeconds = 60;
	secondsPassedOnLastUpdate = 0;
}


int32 UTimerWidget::SetSeconds()
{
	secondsPassed = GetWorld()->TimeSeconds;
	secondsPassed = (int32)secondsPassed % totalSeconds;
	secondsLeft = totalSeconds - secondsPassed;

	if (secondsLeft == 60)
	{
		return 0;
	}

	return secondsLeft;
}

int32 UTimerWidget::SetMinutes()
{
	if (minutesLeft > 0 && secondsPassed - secondsPassedOnLastUpdate >= 1)
	{
		if (secondsLeft == 59)
		{
			minutesLeft -= 1;
		}
	}

	secondsPassedOnLastUpdate = secondsPassed;

	return minutesLeft;

}

