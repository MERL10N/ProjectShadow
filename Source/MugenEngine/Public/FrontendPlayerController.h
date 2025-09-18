// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FrontendPlayerController.generated.h"

/**
 * @class AFrontendPlayerController
 * @brief Represents a player controller designed for the frontend operations of the MUGEN engine.
 *
 * AFrontendPlayerController is a subclass of APlayerController, customized to handle UI 
 * specific logic related to player control and view management.
 */
UCLASS()
class MUGENENGINE_API AFrontendPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:

	// Begin APlayerController Interface
	virtual void OnPossess(APawn* aPawn) override;
	
};
