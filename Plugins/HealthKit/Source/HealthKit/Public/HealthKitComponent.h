// HealthKitComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthKitComponent.generated.h"

// 플러그인 모듈(HealthKit)에 속한 체력 컴포넌트다.
// HEALTHKIT_API 가 있어야 프로젝트 모듈에서 이 클래스를 쓸 수 있다.
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HEALTHKIT_API UHealthKitComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHealthKitComponent();

    UFUNCTION(BlueprintCallable, Category = "Health")
    void ApplyDamage(float Amount);

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealth() const { return Health; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
    float MaxHealth = 100.f;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Health")
    float Health = 0.f;
};
