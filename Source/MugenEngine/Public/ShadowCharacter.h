// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "ShadowCharacter.generated.h"


/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class MUGENENGINE_API AShadowCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShadowCharacter();

	UFUNCTION(BlueprintCallable)
	// Add Ring Count, Score, BoostAmount upon collecting rings
	void AddRing(int32 RingAmount);

	UFUNCTION(BlueprintCallable)
	// Add Score, BoostAmount 
	void AddScore(int32 ScoreAmount);

	UFUNCTION(BlueprintCallable)
	// Add BoostAmount
	void AddBoost(float BoostAmount);

	void Jump();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponet) override;

	void HandleSpring(AActor* OverlappedActor);
	void HandleRing(AActor* OverlappedActor);
	void HandleDashRamp(AActor* OverlappedActor);
	void HandleTrickRamp(AActor* OverlappedActor);

	void ResetGravity();

	void MoveForward(const FInputActionValue& Value);

	void MoveRight(float Value);

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool IsStomping;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool IsHomingAttacking;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool IsDoubleJumping;
	
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool IsGrinding;

	// Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* SpinDashAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	UParticleSystem* StompAura;

	

	int32 TotalRings;
	int32 TotalScore;

	float BoostEnergyTotal;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
};
