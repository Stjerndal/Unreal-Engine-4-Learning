// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "ProgIntroHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROGINTRO_API AProgIntroHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	AProgIntroHUD(const FObjectInitializer& ObjectInitializer);

	// Variable for storing the font
	UPROPERTY()
		UFont* HUDFont;

	// Pirmary draw call for the HUD
	virtual void DrawHUD() override;
	
	
};
