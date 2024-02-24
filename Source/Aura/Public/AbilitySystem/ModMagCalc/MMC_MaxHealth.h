// Copyright Brandon Davis

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UMMC_MaxHealth();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

	FGameplayEffectAttributeCaptureDefinition VigorDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multipliers")
	float BaseValue = 80.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multipliers")
	float VigorMultiplier = 2.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multipliers")
	float LevelMultiplier = 10.f;
	
};
