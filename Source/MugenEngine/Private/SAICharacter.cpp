// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "SAICharacter.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "SAttributeComponent.h"

// Sets default values
ASAICharacter::ASAICharacter()
{
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");

}

void ASAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//PawnSensingComponent->OnSeePawn.AddDynamic(this, &ASAICharacter::OnPawnSeen);
	//PawnSensingComponent->OnSeePawn.AddDynamic()
}

void ASAICharacter::OnPawnSeen(APawn* Pawn) const
{
	AAIController* TheController = Cast<AAIController>(GetController());
	if (TheController)
	{
		UBlackboardComponent* BlackboardComponent = TheController->GetBlackboardComponent();

		BlackboardComponent->SetValueAsObject("TargetActor", Pawn);
	}
}

void ASAICharacter::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComponent, float Health,
	float DeltaTime)
{
}
