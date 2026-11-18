// HealthKitComponent.cpp
#include "HealthKitComponent.h"

UHealthKitComponent::UHealthKitComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UHealthKitComponent::BeginPlay()
{
    Super::BeginPlay();
    Health = MaxHealth;
}

void UHealthKitComponent::ApplyDamage(float Amount)
{
    Health = FMath::Clamp(Health - Amount, 0.f, MaxHealth);
    UE_LOG(LogTemp, Warning, TEXT("[HealthKit] %s Health: %.0f"), *GetOwner()->GetName(), Health);
}
