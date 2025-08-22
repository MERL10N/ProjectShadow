// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "ShadowCharacter.h"

// Sets default values
AShadowCharacter::AShadowCharacter()
	: IsStomping(false),
      IsHomingAttacking(false),
      IsDoubleJumping(false),
      IsGrinding(false),
	  TotalRings(0),
	  TotalScore(0),
	  BoostEnergyTotal(100.f)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AShadowCharacter::AddRing(int32 RingAmount)
{
	TotalRings += RingAmount;
	TotalRings = FMath::Clamp(TotalRings, 0, 1000);
}

void AShadowCharacter::AddScore(int32 ScoreAmount)
{
	TotalScore += ScoreAmount;
}

void AShadowCharacter::AddBoost(float BoostAmount)
{
	if (BoostEnergyTotal < 100.f)
	{
		BoostEnergyTotal += BoostAmount;
		BoostEnergyTotal = FMath::Clamp(BoostEnergyTotal, 0.f, 100.f);
	}
}


// Called when the game starts or when spawned
void AShadowCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShadowCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShadowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

