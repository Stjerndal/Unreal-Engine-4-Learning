// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROGINTRO_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	

public:

	ABatteryPickup(const FObjectInitializer& ObjectInitializer);

	// Set the amount of power given to player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PowerLevel;
	
	// Override the OnPickedUp function (use _Implementation because this is a BlueprintNativeEvent)
	void OnPickedUp_Implementation() override;

	
	
};
