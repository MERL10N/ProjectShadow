// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "../Public/SBTService_CheckAttackRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void USBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// Check distance between pawn and target done
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	if (ensure(BlackboardComp))
	{
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));

		if (TargetActor)
		{
			AAIController * MyController = OwnerComp.GetAIOwner();
			if (ensure(MyController))
			{
				APawn* AIPawn = MyController->GetPawn();
				if (ensure(AIPawn))
				{
					float DistanceSquared = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());

					bool bWithinRange = DistanceSquared < (2000.f * 2000.f);

					bool bHasLineOfSight = bWithinRange && MyController->LineOfSightTo(TargetActor);

					bool bValidRange = bWithinRange && bHasLineOfSight;

					BlackboardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, bValidRange);
				}
			}
		}
	}
}


