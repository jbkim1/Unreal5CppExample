// TrainingDummy.cpp
#include "TrainingDummy.h"
#include "HealthKitComponent.h"   // 플러그인 모듈의 Public 헤더

ATrainingDummy::ATrainingDummy()
{
    Health = CreateDefaultSubobject<UHealthKitComponent>(TEXT("Health"));
}

void ATrainingDummy::BeginPlay()
{
    Super::BeginPlay();
    Health->ApplyDamage(30.f);
}
