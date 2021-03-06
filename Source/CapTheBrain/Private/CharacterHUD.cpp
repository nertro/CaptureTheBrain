// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CharacterHUD.h"
#include "CapTheBrainCharacter.h"
#include <vector>
#include "EngineUtils.h"
#include "BrainzlapGameInstance.h"


ACharacterHUD::ACharacterHUD(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay();
	ItemImgs.Add(FastImg);
	ItemImgs.Add(SlowImg);
	ItemImgs.Add(ShieldImg);
	ItemImgs.Add(SwapImg);
	ItemImgs.Add(ZappImg);

	if (Cast<UBrainzlapGameInstance>(GetGameInstance())->playerCount == 1)
	{
		UIImgScale = 0.2;
		UISmallImgScale = 0.12;
		UISmallPaddingLeft = 125;
		UISmallPaddingBottom = 65;
		UISmallImgSpace = 20;
		UIPaddingBottomRight = 120;
		UITextPaddingBottom = 120;
		UITextPaddingBottomRight = 90;
		UISyringeBottom = -25;
	}

	owner = Cast<ACapTheBrainCharacter>(GetOwningPlayerController()->GetPawn());
}

void ACharacterHUD::DrawBasicUIElements(float screenWidth, float screenHeight)
{
	if (SplatterImg && BrainImg && GUIFont)
	{
		float offset = screenWidth / screenHeight;
		Super::DrawTexture(SplatterImg, UIPaddingLeft, screenHeight - (SplatterImg->GetSizeY() * UIImgScale) - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		Super::DrawTexture(SyringeImg, (screenWidth / 2) - ((SyringeImg->GetSizeX() * UIImgScale * 2.5 * UISyringeMultiLeft) / 2), screenHeight - (SyringeImg->GetSizeY() * UIImgScale * 2.5) + UISyringeBottom, screenWidth, screenHeight, UILiquidAmount, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale * 2.5, false, 0, FVector2D::ZeroVector);
		//Super::DrawTexture(LiquidImg, (screenWidth / 2) - ((LiquidImg->GetSizeX() * UIImgScale * UILiquidMultiLeft) / 2), screenHeight - (LiquidImg->GetSizeY() * UIImgScale) - UILiquidBottom, screenWidth, screenHeight, UILiquidAmount, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale / 1.3, false, 0, FVector2D::ZeroVector);
		Super::DrawTexture(BrainImg, screenWidth - (BrainImg->GetSizeX() * UIImgScale) - UIPaddingBottomRight, screenHeight - (BrainImg->GetSizeY() * UIImgScale) - UIPaddingBottomRight, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UIImgScale, false, 0, FVector2D::ZeroVector);
		int score = 0;
		if (Cast<ACapTheBrainCharacter>(GetOwningPawn()))
		{
			score = Cast<ACapTheBrainCharacter>(GetOwningPawn())->score;
		}
		Super::DrawText(FString::FromInt(score), FLinearColor::Black, screenWidth - UITextPaddingBottomRight, screenHeight - UITextPaddingBottom, GUIFont, UIFontScale, false);
	}
	if (Cast<UBrainzlapGameInstance>(GetGameInstance())->gameOver)
	{
		FString text = " ";
		if (Cast<ACapTheBrainCharacter>(GetOwningPawn())->won)
		{
			text = "You win!";
		}
		else
		{
			text = "You loose!";
		}

		Super::DrawText(text, FLinearColor::Red, UIPaddingLeft*4, screenHeight / 2, GUIFont, UIFontScale * 2, false);
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
	if (!owner)
	{
		owner = Cast<ACapTheBrainCharacter>(GetOwningPlayerController()->GetPawn());
	}
	if (owner)
	{
		if (owner->isFast)
		{
			Super::DrawTexture(ItemImgs[0], UISmallPaddingLeft + (SplatterImg->GetSizeX()*UIImgScale), screenHeight - (ItemImgs[0]->GetSizeY() * UISmallImgScale) - UISmallPaddingBottom, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UISmallImgScale, false, 0, FVector2D::ZeroVector);
		}
		if (owner->isSlow)
		{
			Super::DrawTexture(ItemImgs[1], UISmallPaddingLeft + ((SplatterImg->GetSizeX()*UIImgScale) * 2) + UISmallImgSpace, screenHeight - (ItemImgs[0]->GetSizeY() * UISmallImgScale) - UISmallPaddingBottom, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UISmallImgScale, false, 0, FVector2D::ZeroVector);
		}
		if (owner->hasShield)
		{
			Super::DrawTexture(ItemImgs[2], UISmallPaddingLeft + ((SplatterImg->GetSizeX()*UIImgScale) * 3) + (UISmallImgSpace * 2), screenHeight - (ItemImgs[0]->GetSizeY() * UISmallImgScale) - UISmallPaddingBottom, screenWidth, screenHeight, 0, 0, offset, 1, FLinearColor::White, BLEND_Translucent, UISmallImgScale, false, 0, FVector2D::ZeroVector);
		}
	}
}

