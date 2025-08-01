// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "../Public/SAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	//MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	//if (MyPawn)
	//{
	//	GetBlackboardComponent()->SetValueAsVector("MoveToLocation", MyPawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsObject("TargetActor", MyPawn);
	//}

	TArray<AActor*> PotentialTargets;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player"), PotentialTargets);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Enemy"), PotentialTargets);

	float BestScore = -FLT_MAX;
	AActor* BestTarget = nullptr;

	APawn* AIPawn = GetPawn();

	for (AActor* Target : PotentialTargets)
	{
		if (!Target || Target == AIPawn) continue;

		float Score = 0.f;

		if (Target->ActorHasTag("Player"))
			Score += 1000.f;
		else if (Target->ActorHasTag("Enemy"))
			Score += 700.f;

		float Dist = FVector::Dist(AIPawn->GetActorLocation(), Target->GetActorLocation());
		Score += FMath::Clamp(1000.f - Dist, 0.f, 1000.f);

		if (Score > BestScore)
		{
			BestScore = Score;
			BestTarget = Target;
		}
	}

	if (BestTarget)
	{
		GetBlackboardComponent()->SetValueAsObject("TargetActor", BestTarget);
		GetBlackboardComponent()->SetValueAsVector("MoveToLocation", BestTarget->GetActorLocation());
	}
}
