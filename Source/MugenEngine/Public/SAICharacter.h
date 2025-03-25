// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SAICharacter.generated.h"

class UPawnSensingComponent;

UCLASS()
class MUGENENGINE_API ASAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASAICharacter();

protected:
	virtual void PostInitializeComponents() override;
	
	UPROPERTY(VisibleAnywhere , Category="Components")
	UPawnSensingComponent* PawnSensingComponent;

	void OnPawnSeen(APawn* Pawn);

};
