// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.
#include "Widget_PrimaryLayout.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	checkf(RegisteredWidgetsStackMap.Contains(InTag), TEXT("Widget stack with tag %s not found"), *InTag.ToString())
	return RegisteredWidgetsStackMap.FindRef(InTag);
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM( meta = (Catgories = "Frontend.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	if (!IsDesignTime())
	{
		if (!RegisteredWidgetsStackMap.Contains(InStackTag))
		{
			RegisteredWidgetsStackMap.Add(InStackTag, InStack);
		}
	}
}
