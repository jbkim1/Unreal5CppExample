#pragma once

#include "CoreMinimal.h"

// UObject 가 아니다. UCLASS 도 USTRUCT 도 없는 순수 C++ 타입이다.
struct FDropSettings
{
    float DropChance = 1.0f;    // 0.0 ~ 1.0
    int32 MinCount = 1;
    int32 MaxCount = 3;

    FDropSettings();
    ~FDropSettings();

    // 모든 상자가 같은 설정 하나를 쓰도록, 살아 있는 설정이 있으면 그것을 돌려준다.
    // 없으면 새로 만든다. 마지막 사용자가 놓으면 설정도 해제된다.
    static TSharedRef<FDropSettings> Acquire();

private:
    // 소유하지 않고 관찰만 한다. 이 포인터는 설정의 수명을 붙잡지 않는다.
    static TWeakPtr<FDropSettings> Shared;
};