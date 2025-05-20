// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SAICharacter.generated.h"

class UPawnSensingComponent;
class USAttributeComponent;

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
	
	UPROPERTY(BlueprintReadWrite , Category= "Player")
	float PlayerBounceOff;

	UPROPERTY(BlueprintReadWrite , Category= "Player")
	float PlayerHomingBounceOff;

	UPROPERTY(BlueprintReadWrite , Category= "Player")
	float PlayerDamageKnockBack;

	UPROPERTY(BlueprintReadWrite , Category= "Player")
	int ScoreAmount;

	UPROPERTY(VisibleAnywhere , Category= "Player")
	float EnemyRadius = 100;

	void OnPawnSeen(APawn* Pawn) const;

	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComponent, float Health, float DeltaTime);

	
};
