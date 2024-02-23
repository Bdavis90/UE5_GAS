// Copyright Brandon Davis

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AuraPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();

	virtual FORCEINLINE UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class UAttributeSet* GetAttributeSet() const { return AttributeSet; };
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	FORCEINLINE int32 GetPlayerLevel() const { return Level; }

protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UAttributeSet> AttributeSet;

private:

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);

	
};
