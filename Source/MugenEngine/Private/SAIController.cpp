// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "../Public/SAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (MyPawn)
	{
		GetBlackboardComponent()->SetValueAsVector("MoveToLocation", MyPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsObject("TargetActor", MyPawn);
	}

	if (GunPawn)
	{
		GetBlackboardComponent()->SetValueAsVector("MoveToLocation", GunPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsObject("TargetActor", GunPawn);
	}
}
