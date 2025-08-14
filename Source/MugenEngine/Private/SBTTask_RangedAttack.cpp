// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.
#include "SBTTask_RangedAttack.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/PrimitiveComponent.h"

USBTTask_RangedAttack::USBTTask_RangedAttack()
	:  MaxBulletSpread(5.0f)
{
}


EBTNodeResult::Type USBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Log, TEXT("Test message"))
	AAIController* MyController = OwnerComp.GetAIOwner();
	if (!MyController) return EBTNodeResult::Failed;

	ACharacter* MyPawn = Cast<ACharacter>(MyController->GetPawn());
	if (!MyPawn) return EBTNodeResult::Failed;

	AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("TargetActor"));
	if (!TargetActor) return EBTNodeResult::Failed;

	FVector MuzzleLocation = MyPawn->GetMesh()->GetSocketLocation("weaponSocket_r");
	FVector Direction = TargetActor->GetActorLocation() - MuzzleLocation;
	Direction.Normalize();

	FVector SpawnLocation = MuzzleLocation + Direction * 20.0f; // Offset forward
	FRotator MuzzleRotation = Direction.Rotation();

	MuzzleRotation.Pitch += FMath::RandRange(0.f, MaxBulletSpread);
	MuzzleRotation.Yaw += FMath::RandRange(-MaxBulletSpread, MaxBulletSpread);

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParameters.Instigator = MyPawn->GetInstigator();
	SpawnParameters.Owner = MyPawn;

	AActor* NewProjectile = GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, MuzzleRotation, SpawnParameters);

	if (NewProjectile)
	{
		UPrimitiveComponent* RootComp = Cast<UPrimitiveComponent>(NewProjectile->GetRootComponent());
		if (RootComp)
		{
			RootComp->IgnoreActorWhenMoving(MyPawn, true);
		}

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

