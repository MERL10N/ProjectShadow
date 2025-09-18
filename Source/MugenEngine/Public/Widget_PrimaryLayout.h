// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Widget_PrimaryLayout.generated.h"

class UCommonActivatableWidgetContainerBase;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class MUGENENGINE_API UWidget_PrimaryLayout : public UCommonUserWidget
{
	GENERATED_BODY()
public:
	UCommonActivatableWidgetContainerBase* FindWidgetStackByTag(const FGameplayTag& InTag) const;
protected:
		UFUNCTION(BlueprintCallable)
		void RegisterWidgetStack(UPARAM( meta = (Catgories = "Frontend.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack);
private:
	TMap<FGameplayTag, UCommonActivatableWidgetContainerBase*> RegisteredWidgetsStackMap;
};
