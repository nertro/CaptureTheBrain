// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

class ACapTheBrainCharacter;

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ACharacterHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	bool PlayerHasItem;

	virtual void BeginPlay() override;

	ACapTheBrainCharacter* owner;

	/** Basic UI Elements*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* TimerImg;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* BrainImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* SplatterImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UIPaddingBottomRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UIPaddingLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UIImgScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UISmallPaddingLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UISmallPaddingBottom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UISmallImgScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UISmallImgSpace;

	UFUNCTION(BlueprintCallable, Category = HUD)
		void DrawBasicUIElements(float screenWidth, float screenHeight);

	/**Basic Editable Elements*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		FString TimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		FString BrainCount;

	UFUNCTION(BlueprintCallable, Category = HUD)
		void DrawCounterElements(float screenWidth, float screenHeight);

	/**Items that are not always visible*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* SlowImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* FastImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* ShieldImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* SwapImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UTexture2D* ZappImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		UFont* GUIFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UIFontScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UITextPaddingBottomRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI)
		float UITextPaddingBottom;

	int currentItem;

	std::vector<UTexture2D*> ItemImgs;
};
