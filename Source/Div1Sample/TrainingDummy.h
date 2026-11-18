// TrainingDummy.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrainingDummy.generated.h"

class UHealthKitComponent;

// 프로젝트 모듈(Div1Sample)의 액터가 플러그인 모듈(HealthKit)의 컴포넌트를 쓴다.
UCLASS()
class DIV1SAMPLE_API ATrainingDummy : public AActor
{
    GENERATED_BODY()

public:
    ATrainingDummy();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UHealthKitComponent> Health;
};
