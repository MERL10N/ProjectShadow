// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "SAICharacter.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "SAttributeComponent.h"

ASAICharacter::ASAICharacter()
{
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");
	AttributeComponent =  CreateDefaultSubobject<USAttributeComponent>("AttributeComponent");
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ASAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PawnSensingComponent->OnSeePawn.AddDynamic(this, &ASAICharacter::OnPawnSeen);
	//AttributeComponent->OnHealthChanged.AddDynamic(this, &ASAICharacter::OnHealthChanged);
}

void ASAICharacter::OnPawnSeen(APawn* Pawn)
{
	if (AAIController* TheController = Cast<AAIController>(GetController()))
	{
		UBlackboardComponent* BlackboardComponent = TheController->GetBlackboardComponent();

		BlackboardComponent->SetValueAsObject("TargetActor", Pawn);
	}
}

void ASAICharacter::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComponent, float Health,
	float Delta)
{
	if (Delta < 0.f)
	{
		if (Health <= 0.f)
		{
			if (AAIController* TheController = Cast<AAIController>(GetController()))
			{
				TheController->GetBrainComponent()->StopLogic("Killed");
			}
		}
	}
}