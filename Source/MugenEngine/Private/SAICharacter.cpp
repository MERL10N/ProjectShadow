// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "SAICharacter.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
ASAICharacter::ASAICharacter()
{
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");

}

void ASAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PawnSensingComponent->OnSeePawn.AddDynamic(this, &ASAICharacter::OnPawnSeen);
}

void ASAICharacter::OnPawnSeen(APawn* Pawn)
{
	AAIController* TheController = Cast<AAIController>(GetController());
	if (TheController)
	{
		UBlackboardComponent* BlackboardComponent = TheController->GetBlackboardComponent();

		BlackboardComponent->SetValueAsObject("TargetActor", Pawn);
	}
}