// EnemyBase.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

class UStaticMeshComponent;

// Abstract: 이 클래스 자체는 레벨에 놓을 수 없고, 클래스 선택 목록에도 나오지 않는다.
// 적 종류는 이 클래스를 부모로 한 블루프린트로만 만든다.
UCLASS(Abstract, Blueprintable)
class DIV1SAMPLE_API AEnemyBase : public AActor
{
    GENERATED_BODY()

public:
    AEnemyBase();

    // ---- 종류 정보: 같은 종류의 적은 모두 같은 값을 가진다 ----
    // EditDefaultsOnly: 블루프린트의 Class Defaults 에서만 편집한다. 레벨의 개체에서는 바꿀 수 없다.
    // C++ 에는 종류별 값을 쓰지 않는다. 아래 초기값은 「아직 채우지 않았다」를 알리는 표시다.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Kind")
    FText DisplayName = INVTEXT("Unnamed");

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Kind")
    float MaxHealth = 1.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Kind")
    int32 RewardGold = 0;

    // ---- 개체 정보: 배치한 개체마다 다르고 플레이 중에 바뀐다 ----
    // EditInstanceOnly: 레벨에 놓은 개체에서만 편집한다. 0 이면 최대 체력으로 시작한다.
    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Enemy|Instance")
    float CurrentHealth = 0.f;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Enemy")
    TObjectPtr<UStaticMeshComponent> Body;
};
