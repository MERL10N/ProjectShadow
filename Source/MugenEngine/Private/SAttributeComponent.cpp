// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool USAttributeComponent::IsAlive() const
{
	return Health > 0.f;
}

bool USAttributeComponent::IsFullHealth() const
{
	return Health == MaxHealth;
}

float USAttributeComponent::GetHealthMax() const
{
	return MaxHealth;
}

bool USAttributeComponent::ApplyHealthChange()
{
	float OldHealth = Health;
	Health = FMath::Clamp(Health, 0.f, MaxHealth);
	float ActualDelta =  Health - OldHealth;
	//OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);

	return ActualDelta != 0.f;
}

