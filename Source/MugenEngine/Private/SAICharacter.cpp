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
}

void ASAICharacter::OnPawnSeen(APawn* Pawn) const
{
	if (!Pawn || Pawn == this) return;

	ASAICharacter* Self = const_cast<ASAICharacter*>(this);
	if (!Self->SeenPawns.Contains(Pawn))
	{
		Self->SeenPawns.Add(Pawn);
	}

	// Pick best target among all seen pawns
	float BestScore = -FLT_MAX;
	APawn* BestTarget = nullptr;

	for (APawn* Candidate : Self->SeenPawns)
	{
		if (!IsValid(Candidate)) continue;

		float Score = 0.0f;

		// Score based on tag or distance
		if (Candidate->ActorHasTag("Player"))
			Score += 1000.f;
		else if (Candidate->ActorHasTag("Enemy"))
			Score += 700.f;

		float Dist = FVector::Dist(Self->GetActorLocation(), Candidate->GetActorLocation());
		Score += FMath::Clamp(1000.f - Dist, 0.f, 1000.f);

		if (Score > BestScore)
		{
			BestScore = Score;
			BestTarget = Candidate;
		}
	}

	if (BestTarget)
	{
		AAIController* Controller = Cast<AAIController>(GetController());
		if (Controller)
		{
			UBlackboardComponent* Blackboard = Controller->GetBlackboardComponent();
			Blackboard->SetValueAsObject("TargetActor", BestTarget);
		}
	}
}

void ASAICharacter::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComponent, float Health,
	float DeltaTime)
{
}
