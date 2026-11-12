// EnemyCodex.cpp
#include "EnemyCodex.h"
#include "EnemyBase.h"
#include "Components/SceneComponent.h"
#include "EngineUtils.h"        // TActorIterator

AEnemyCodex::AEnemyCodex()
{
    PrimaryActorTick.bCanEverTick = false;

    // 레벨에 놓고 옮길 수 있도록 빈 루트만 둔다.
    SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));
}

void AEnemyCodex::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("[Codex] entries=%d"), EnemyClasses.Num());

    for (int32 i = 0; i < EnemyClasses.Num(); ++i)
    {
        const TSubclassOf<AEnemyBase>& EnemyClass = EnemyClasses[i];

        // 빈 칸은 건너뛴다. 이 검사가 없으면 아래에서 널 클래스를 역참조해 크래시가 난다.
        if (!EnemyClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("[Codex] #%d (empty slot, skipped)"), i);
            continue;
        }

        // 스폰하지 않는다. 클래스가 붙잡고 있는 기본 객체(CDO)를 읽기 전용으로 받는다.
        // 클래스를 넘겼으므로 부모 C++ 클래스가 아니라 「그 블루프린트」의 CDO 가 온다.
        const AEnemyBase* Defaults = GetDefault<AEnemyBase>(EnemyClass);

        UE_LOG(LogTemp, Warning, TEXT("[Codex] #%d %s | MaxHealth=%.0f | Reward=%d | from %s"),
            i,
            *Defaults->DisplayName.ToString(),
            Defaults->MaxHealth,
            Defaults->RewardGold,
            *Defaults->GetName());
    }

    // 정말 스폰 없이 읽었는지 확인한다. 월드에 있는 적 액터를 센다.
    int32 EnemyActors = 0;
    for (TActorIterator<AEnemyBase> It(GetWorld()); It; ++It)
    {
        ++EnemyActors;
    }

    UE_LOG(LogTemp, Warning, TEXT("[Codex] enemy actors in world=%d"), EnemyActors);
}
