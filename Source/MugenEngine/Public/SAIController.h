// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SAIController.generated.h"

class UBehaviorTree;
/**
 * 
 */
UCLASS()
class MUGENENGINE_API ASAIController : public AAIController
{
public:
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
protected:
	virtual void BeginPlay() override;


	// Updates the target list every second 
	FTimerHandle TimerHandle_Retarget;
	void RefreshTarget();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target");
	APawn* MyPawn;
};
