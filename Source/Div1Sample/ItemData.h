#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/SoftObjectPtr.h"
#include "ItemData.generated.h"

class UTexture2D;

UENUM(BlueprintType)
enum class EItemGrade : uint8
{
    Common,
    Rare,
    Epic
};

// 데이터만 담는 객체다. 레벨에 놓이지 않으므로 AActor 가 아니라 UObject 를 직접 상속한다.
UCLASS(BlueprintType)
class DIV1SAMPLE_API UItemData : public UObject
{
    GENERATED_BODY()

public:
    // UObject 에는 BeginPlay 가 없다. 생성 직후 직접 부르는 초기화 자리를 만든다.
    void Init(const FString& InName, int32 InCount, EItemGrade InGrade,
        const TSoftObjectPtr<UTexture2D>& InIcon);

    // 아이콘을 처음 쓰는 시점에 로드한다. 두 번째부터는 보관해 둔 결과를 돌려준다.
    UTexture2D* GetIcon();

    bool IsIconLoaded() const { return LoadedIcon != nullptr; }

    FString ToLogString() const;

    // GC 가 이 객체를 수거하는 순간에 불린다.
    virtual void BeginDestroy() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    FString ItemName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    int32 Count = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    EItemGrade Grade = EItemGrade::Common;

private:
    // 경로만 들고 있다. 아이템이 만들어져도 텍스처는 로드되지 않는다.
    UPROPERTY()
    TSoftObjectPtr<UTexture2D> Icon;

    // 로드한 결과다. 강한 참조로 보관해야 GC 가 수거하지 않는다.
    UPROPERTY()
    TObjectPtr<UTexture2D> LoadedIcon;
};