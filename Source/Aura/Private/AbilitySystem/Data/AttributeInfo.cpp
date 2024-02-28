// Copyright Brandon Davis


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for(const FAuraAttributeInfo& Info : AttributeInformation)
	{
		bool Tag = Info.AttributeTag.MatchesTagExact(AttributeTag);

		if (Tag) return Info;

		if(bLogNotFound)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Can't find info for AttributeTag %s on AttributeInfo %s"), *AttributeTag.ToString(), *GetNameSafe(this)));
		}

	}

	return FAuraAttributeInfo();
}
