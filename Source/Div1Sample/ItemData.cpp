#include "ItemData.h"
#include "Engine/Texture2D.h"

void UItemData::Init(const FString& InName, int32 InCount, EItemGrade InGrade,
    const TSoftObjectPtr<UTexture2D>& InIcon)
{
    ItemName = InName;
    Count = InCount;
    Grade = InGrade;
    Icon = InIcon;      // 경로만 복사한다. 여기서 로드하지 않는다.

    UE_LOG(LogTemp, Warning, TEXT("[Item] Init %s | outer=%s | icon=%s"),
        *ToLogString(),
        *GetNameSafe(GetOuter()),
        Icon.IsNull() ? TEXT("not set") : TEXT("path only (not loaded)"));
}

UTexture2D* UItemData::GetIcon()
{
    // 이미 로드한 적이 있으면 보관해 둔 결과를 돌려준다.
    if (LoadedIcon)
    {
        return LoadedIcon;
    }

    if (Icon.IsNull())
    {
        UE_LOG(LogTemp, Warning, TEXT("[Item] %s has no icon path"), *ItemName);
        return nullptr;
    }

    UE_LOG(LogTemp, Warning, TEXT("[Item] %s icon: loading now (IsPending=%s)"),
        *ItemName, *LexToString(Icon.IsPending()));

    LoadedIcon = Icon.LoadSynchronous();

    UE_LOG(LogTemp, Warning, TEXT("[Item] %s icon: loaded=%s"),
        *ItemName, *LexToString(LoadedIcon != nullptr));

    return LoadedIcon;
}

FString UItemData::ToLogString() const
{
    return FString::Printf(TEXT("%s x%d (%s)"),
        *ItemName, Count, *UEnum::GetValueAsString(Grade));
}

void UItemData::BeginDestroy()
{
    UE_LOG(LogTemp, Warning, TEXT("[Item] BeginDestroy: %s | %s"), *GetName(), *ItemName);

    Super::BeginDestroy();      // 빠뜨리지 않는다
}