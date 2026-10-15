#include "InventoryComponent.h"
#include "ItemChest.h"
#include "ItemData.h"
#include "Engine/Texture2D.h"

void UInventoryComponent::AddItem(UItemData* Item)
{
    if (!IsValid(Item))
    {
        return;
    }

    Items.Add(Item);

    UE_LOG(LogTemp, Warning, TEXT("[Inventory] added %s | held=%d"),
        *Item->ToLogString(), Items.Num());
}

void UInventoryComponent::SetLastOpenedChest(AItemChest* Chest)
{
    // 덮어쓰기 전에 이전 상자가 어떤 상태인지 먼저 확인한다.
    LogLastChest();

    LastOpenedChest = Chest;
}

void UInventoryComponent::LogLastChest() const
{
    if (LastOpenedChest.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("[Inventory] last chest: %s (alive)"),
            *LastOpenedChest->GetName());
    }
    else if (LastOpenedChest.IsStale())
    {
        // 한 번은 가리켰지만 지금은 사라졌다. 크래시 없이 이 분기로 온다.
        UE_LOG(LogTemp, Warning, TEXT("[Inventory] last chest: gone"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[Inventory] last chest: none (never opened)"));
    }
}

void UInventoryComponent::LogState() const
{
    UE_LOG(LogTemp, Warning, TEXT("[Inventory] held=%d"), Items.Num());

    for (int32 i = 0; i < Items.Num(); ++i)
    {
        UE_LOG(LogTemp, Warning, TEXT("[Inventory]  #%d %s | icon loaded=%s"),
            i, *Items[i]->ToLogString(), *LexToString(Items[i]->IsIconLoaded()));
    }

    LogLastChest();
}

void UInventoryComponent::UseIcon(int32 Index)
{
    if (!Items.IsValidIndex(Index))
    {
        UE_LOG(LogTemp, Warning, TEXT("[Inventory] no item at index %d"), Index);
        return;
    }

    const UTexture2D* Icon = Items[Index]->GetIcon();

    UE_LOG(LogTemp, Warning, TEXT("[Inventory] icon of #%d -> %s"),
        Index, *GetNameSafe(Icon));
}