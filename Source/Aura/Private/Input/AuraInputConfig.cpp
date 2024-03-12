// Copyright Brandon Davis


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for(const FAuraInputAction& Action : AbilityInputActions)
	{
		if(Action.InputAction && InputTag.MatchesTagExact(Action.InputTag))
		{
			return Action.InputAction;
		}
	}

	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this))
	}

	return nullptr;
}
