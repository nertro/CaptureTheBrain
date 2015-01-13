// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CharacterHUD.h"
#include "CapTheBrainCharacter.h"
#include <vector>
#include "BrainzlapGameInstance.h"
#include "EngineUtils.h"



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

	UBrainzlapGameInstance* instance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	if (instance->playerCount == 1)
	{
		UIImgScale = 0.2;
		UIPaddingBottomRight = 120;
		UITextPaddingBottom = 120;
		UITextPaddingBottomRight = 90;
	}
}

void ACharacterHUD::DrawBasicUIElements(float screenWidth, float screenHeight)
{
	if (SplatterImg && BrainImg && GUIFont)
	{
		float offset = screenWidth / screenHeight;
		Super::DrawTexture(SplatterImg, UIPaddingLeft, screenHeight - (SplatterImg->GetSizeY() * UIImgScale) - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		Super::DrawTexture(BrainImg, screenWidth - (SplatterImg->GetSizeX() * UIImgScale) - UIPaddingBottomRight, screenHeight - (SplatterImg->GetSizeY() * UIImgScale) - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		int score = Cast<ACapTheBrainCharacter>(GetOwningPawn())->GetScore();
		Super::DrawText(FString::FromInt(score), FLinearColor::Black, screenWidth - UITextPaddingBottomRight, screenHeight - UITextPaddingBottom, GUIFont, UIFontScale, false);
	}
}

void ACharacterHUD::DrawCounterElements(float screenWidth, float screenHeight)
{
	float offset = screenWidth / screenHeight;
	if (PlayerHasItem)
	{
		if (ItemImgs[currentItem])
		{
			Super::DrawTexture(ItemImgs[currentItem], UIPaddingLeft, screenHeight - (SplatterImg->GetSizeY() * UIImgScale) - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		}
	}
}

