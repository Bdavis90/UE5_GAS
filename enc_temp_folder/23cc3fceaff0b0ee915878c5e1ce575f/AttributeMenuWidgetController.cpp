// Copyright Brandon Davis


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AuraGameplayTags.h"


void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo)

	for(auto& Tag : AttributeInfo.Get()->AttributeInformation)
	{
		BroadcastAttributeInfo(Tag.AttributeTag);
	}


}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& Tag) const
{
	// GEt info from DataAsset based on gameplay tag.
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Tag);
	// Set the value.
	Info.AttributeValue = Info.AttributeGetter.GetNumericValue(AttributeSet);
	// Broadcast to the subscribers.
	AttributeInfoDelegate.Broadcast(Info);
}


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{

}
