// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "ShadowCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AShadowCharacter::AShadowCharacter()
	: IsStomping(false),
	  IsHomingAttacking(false),
	  IsDoubleJumping(false),
	  IsGrinding(false), DefaultMappingContext(nullptr), SpinDashAction(nullptr), JumpAction(nullptr),
	  MoveAction(nullptr), StompAura(nullptr),
	  TotalRings(0),
	  TotalScore(0),
	  BoostEnergyTotal(100.f)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AShadowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AShadowCharacter::Jump);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &AShadowCharacter::MoveForward);
	}
	
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

void AShadowCharacter::Jump()
{
	Super::Jump();
}


// Called when the game starts or when spawned
void AShadowCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShadowCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
}

void AShadowCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
}

void AShadowCharacter::MoveForward(const FInputActionValue& Value)
{
	FVector ForwardVector = GetActorForwardVector();
	
}

void AShadowCharacter::MoveRight(float Value)
{
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

