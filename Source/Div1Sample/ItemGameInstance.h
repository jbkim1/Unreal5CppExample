#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ItemGameInstance.generated.h"

class UInventoryComponent;

// 레벨을 옮겨도 남는 누적 기록이다.
// 이 클래스를 부모로 한 블루프린트를 만들어 프로젝트 설정의 Game Instance Class 에 지정해야 쓰인다.
UCLASS(Blueprintable)
class DIV1SAMPLE_API UItemGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    virtual void Init() override;
    virtual void Shutdown() override;

    // 상자를 열 때마다 호출한다.
    void RecordChestOpened(int32 ItemCount);

    // PIE 콘솔(~)에서 ItemStatus 를 입력하면 현재 상태를 로그로 보여 준다.
    UFUNCTION(Exec)
    void ItemStatus();

    // PIE 콘솔에서 ItemIcon 0 처럼 입력하면 0번 아이템의 아이콘을 처음 쓰는 순간이 된다.
    UFUNCTION(Exec)
    void ItemIcon(int32 Index);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Record")
    int32 TotalChestsOpened = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Record")
    int32 TotalItemsAcquired = 0;

private:
    UInventoryComponent* FindPlayerInventory() const;
};