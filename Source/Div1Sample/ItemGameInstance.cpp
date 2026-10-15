#include "ItemGameInstance.h"
#include "InventoryComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

void UItemGameInstance::Init()
{
    Super::Init();

    // 게임을 실행할 때 한 번만 불린다. 레벨을 옮겨도 다시 불리지 않는다.
    UE_LOG(LogTemp, Warning, TEXT("[Record] GameInstance Init"));
}

void UItemGameInstance::Shutdown()
{
    UE_LOG(LogTemp, Warning, TEXT("[Record] GameInstance Shutdown | chests=%d items=%d"),
        TotalChestsOpened, TotalItemsAcquired);

    Super::Shutdown();
}

void UItemGameInstance::RecordChestOpened(int32 ItemCount)
{
    ++TotalChestsOpened;
    TotalItemsAcquired += ItemCount;

    UE_LOG(LogTemp, Warning, TEXT("[Record] chests=%d items=%d"),
        TotalChestsOpened, TotalItemsAcquired);
}

void UItemGameInstance::ItemStatus()
{
    UE_LOG(LogTemp, Warning, TEXT("[Record] STATUS chests=%d items=%d"),
        TotalChestsOpened, TotalItemsAcquired);

    if (UInventoryComponent* Inventory = FindPlayerInventory())
    {
        Inventory->LogState();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[Record] no inventory in this level"));
    }
}

void UItemGameInstance::ItemIcon(int32 Index)
{
    if (UInventoryComponent* Inventory = FindPlayerInventory())
    {
        Inventory->UseIcon(Index);
    }
}

UInventoryComponent* UItemGameInstance::FindPlayerInventory() const
{
    const APlayerController* PC = GetFirstLocalPlayerController();
    const APawn* Pawn = PC ? PC->GetPawn() : nullptr;

    return Pawn ? Pawn->FindComponentByClass<UInventoryComponent>() : nullptr;
}