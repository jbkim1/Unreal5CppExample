// EnemyBase.cpp
#include "EnemyBase.h"
#include "Components/StaticMeshComponent.h"

AEnemyBase::AEnemyBase()
{
    PrimaryActorTick.bCanEverTick = false;

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    SetRootComponent(Body);

    // 생성자는 기본 객체(CDO)를 만들 때도 불린다. 지금 만들어지는 객체가 어느 쪽인지 함께 찍는다.
    UE_LOG(LogTemp, Warning, TEXT("[Enemy] Ctor %s | CDO=%s"),
        *GetName(),
        HasAnyFlags(RF_ClassDefaultObject) ? TEXT("Yes") : TEXT("No"));
}

void AEnemyBase::BeginPlay()
{
    Super::BeginPlay();

    // 배치할 때 따로 정하지 않았으면 종류의 최대 체력으로 시작한다.
    if (CurrentHealth <= 0.f)
    {
        CurrentHealth = MaxHealth;
    }

    UE_LOG(LogTemp, Warning, TEXT("[Enemy] %s BeginPlay | %s | Health=%.0f/%.0f"),
        *GetName(), *DisplayName.ToString(), CurrentHealth, MaxHealth);
}
