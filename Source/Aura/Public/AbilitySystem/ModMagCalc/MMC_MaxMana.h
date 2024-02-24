// Copyright Brandon Davis

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UMMC_MaxMana();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multipliers")
	float BaseValue = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multipliers")
	float IntelligenceMult = 2.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multipliers")
	float LevelMultiplier = 15.f;
	
};
