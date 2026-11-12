// EnemyCodex.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "EnemyCodex.generated.h"

class AEnemyBase;

// 적을 스폰하지 않고 종류별 기본값을 읽어 출력하는 도감이다.
UCLASS(Blueprintable)
class DIV1SAMPLE_API AEnemyCodex : public AActor
{
    GENERATED_BODY()

public:
    AEnemyCodex();

protected:
    virtual void BeginPlay() override;

    // 적 「인스턴스」가 아니라 적 「클래스」의 목록이다.
    // TSubclassOf 가 AEnemyBase 계열만 고를 수 있게 제한한다.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Codex")
    TArray<TSubclassOf<AEnemyBase>> EnemyClasses;
};
