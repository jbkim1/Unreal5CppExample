#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AItemChest;
class UItemData;

// 플레이어에 붙어서 아이템 목록과 마지막으로 연 상자를 들고 있는 기능 조각이다.
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DIV1SAMPLE_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    void AddItem(UItemData* Item);
    void SetLastOpenedChest(AItemChest* Chest);

    // 보관 목록, 마지막 상자 상태, 아이콘 로드 상태를 로그로 보여 준다.
    void LogState() const;

    // 보관 중인 아이템의 아이콘을 쓴다. 이 순간이 아이콘을 처음 쓰는 시점이 된다.
    void UseIcon(int32 Index);

private:
    void LogLastChest() const;

    // 보관 목록: 객체의 수명을 책임지는 강한 참조다. UPROPERTY 가 있어야 GC 가 이 참조를 센다.
    UPROPERTY()
    TArray<TObjectPtr<UItemData>> Items;

    // 마지막으로 연 상자: 가리키기만 한다. 상자가 사라져도 이 참조가 상자를 붙잡지 않는다.
    TWeakObjectPtr<AItemChest> LastOpenedChest;
};