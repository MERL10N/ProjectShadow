// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "../Public/SAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	GetWorld()->GetTimerManager().SetTimer(
	TimerHandle_Retarget, 
	this, 
	&ASAIController::RefreshTarget, 
	0.5f, // every second
	true
);
}

void ASAIController::RefreshTarget()
{
	TArray<AActor*> PotentialTargets;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("BlackArmsEnemy"), PotentialTargets);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (PlayerPawn)
	{
		PotentialTargets.Add(PlayerPawn);
	}
	
	float BestScore = -FLT_MAX;
	AActor* BestTarget = nullptr;

	const APawn* AIPawn = GetPawn();

	for (AActor* Target : PotentialTargets)
	{
		if (!Target || Target == AIPawn)
			continue;

		float Score = 0.f;

		if (Target == PlayerPawn)
			Score += 10.f;   
		if (Target->ActorHasTag("Enemy"))
			Score += 20.f;    // Give higher priority to GUN robots

		const float Dist = FVector::Dist(AIPawn->GetActorLocation(), Target->GetActorLocation());
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
