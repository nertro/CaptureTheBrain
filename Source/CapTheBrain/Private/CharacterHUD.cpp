// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CharacterHUD.h"
#include <vector>



ACharacterHUD::ACharacterHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay();
	ItemImgs.push_back(FastImg);
	ItemImgs.push_back(SlowImg);
	ItemImgs.push_back(ShieldImg);
	ItemImgs.push_back(SwapImg);
	ItemImgs.push_back(ZappImg);
}

void ACharacterHUD::DrawBasicUIElements(float screenWidth, float screenHeight)
{
	if (TimerImg && SplatterImg && BrainImg)
	{
		float offset = screenWidth / screenHeight;
		Super::DrawTexture(SplatterImg, UIPaddingLeft, screenHeight - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		Super::DrawTexture(BrainImg, screenWidth - UIPaddingBottomRight, screenHeight - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
	}
}

void ACharacterHUD::DrawCounterElements(float screenWidth, float screenHeight)
{
	float offset = screenWidth / screenHeight;
	if (PlayerHasItem)
	{
		if (ItemImgs[currentItem])
		{
			Super::DrawTexture(ItemImgs[currentItem], UIPaddingLeft, screenHeight - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		}
	}
}

