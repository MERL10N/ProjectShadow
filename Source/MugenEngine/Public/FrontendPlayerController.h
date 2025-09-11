// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FrontendPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MUGENENGINE_API AFrontendPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:

	// Begin APlayerController Interface
	virtual void OnPossess(APawn* aPawn) override;
	
};
