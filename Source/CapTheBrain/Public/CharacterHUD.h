// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ACharacterHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;

	/** Basic UI Elements*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* TimerImg;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* BrainImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* SplatterImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float UIPaddingBottomRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float UIPaddingLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		float UIImgScale;

	UFUNCTION(BlueprintCallable, Category = HUD)
		void DrawBasicUIElements(float screenWidth, float screenHeight);

	/**Basic Editable Elements*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		FString TimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		FString BrainCount;

	UFUNCTION(BlueprintCallable, Category = HUD)
		void DrawCounterElements(float screenWidth, float screenHeight);

	/**Item that are not always visible*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* SlowImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* FastImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* ShieldImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* SwapImg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		UTexture2D* ZappImg;

	bool PlayerHasItem;

	int currentItem;

	std::vector<UTexture2D*> ItemImgs;
};
