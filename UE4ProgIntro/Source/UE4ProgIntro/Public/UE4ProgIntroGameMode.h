// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "UE4ProgIntroGameMode.generated.h"

// enum to store the current state of gameplay
enum class EUE4ProgIntroPlayerState : uint8 // replacing 'short' with uint8 for blueprint access
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AUE4ProgIntroGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AUE4ProgIntroGameMode(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power)
	float DecayRate;

	EUE4ProgIntroPlayerState GetCurrentState() const;

	void SetCurrentState(EUE4ProgIntroPlayerState NewState);

private:
	EUE4ProgIntroPlayerState CurrentState;

	void HandleNewState(EUE4ProgIntroPlayerState NewState);
};


FORCEINLINE EUE4ProgIntroPlayerState AUE4ProgIntroGameMode::GetCurrentState() const
{
	return CurrentState;
}

