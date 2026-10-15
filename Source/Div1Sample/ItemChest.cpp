#include "ItemChest.h"
#include "InventoryComponent.h"
#include "ItemGameInstance.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Texture2D.h"

AItemChest::AItemChest()
{
    PrimaryActorTick.bCanEverTick = false;

    Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
    Collision->SetBoxExtent(FVector(70.f));
    Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    SetRootComponent(Collision);

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    Body->SetupAttachment(Collision);
    Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // 메시는 지정하지 않는다. 파생 블루프린트에서 Body 의 Static Mesh 를 고른다.

    // 주의: 여기서 DropSettings 를 받지 않는다.
    // 생성자는 클래스 기본 객체(CDO)를 만들 때도 불려서, 설정을 영원히 붙잡게 된다.
}

void AItemChest::BeginPlay()
{
    Super::BeginPlay();

    // 공유 설정을 받는다. 이미 다른 상자가 받아 둔 것이 있으면 같은 설정이 온다.
    DropSettings = FDropSettings::Acquire();

    UE_LOG(LogTemp, Warning, TEXT("[Chest] %s BeginPlay | DropSettings refs=%d"),
        *GetName(), DropSettings.GetSharedReferenceCount());

    Collision->OnComponentBeginOverlap.AddDynamic(this, &AItemChest::OnBeginOverlap);
}

void AItemChest::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    // 겹침 이벤트는 한 번에 여러 번 올 수 있다. 한 번만 처리한다.
    if (bOpened || !OtherActor)
    {
        return;
    }

    // 인벤토리가 붙은 액터(플레이어)만 상자를 열 수 있다.
    UInventoryComponent* Inventory = OtherActor->FindComponentByClass<UInventoryComponent>();
    if (!Inventory)
    {
        return;
    }

    bOpened = true;
    Open(OtherActor, Inventory);
}

void AItemChest::Open(AActor* Opener, UInventoryComponent* Inventory)
{
    UE_LOG(LogTemp, Warning, TEXT("[Chest] %s opened"), *GetName());

    int32 Gained = 0;

    if (FMath::FRand() <= DropSettings->DropChance)
    {
        Gained = FMath::RandRange(DropSettings->MinCount, DropSettings->MaxCount);

        // new 가 아니라 NewObject 로 만든다. 첫 인자가 Outer(소속)다.
        // 이 아이템은 플레이어가 얻은 것이므로 Outer 를 플레이어로 준다.
        // Outer 는 소속만 알린다. 객체를 살려 두는 것은 Outer 가 아니라 UPROPERTY 참조다.
        UItemData* Item = NewObject<UItemData>(Opener);
        Item->Init(ItemName, Gained, Grade, ItemIcon);

        Inventory->AddItem(Item);
    }

    Inventory->SetLastOpenedChest(this);

    // Cast 는 실패하면 nullptr 을 돌려준다. 프로젝트 설정을 빠뜨린 경우를 로그로 알린다.
    if (UItemGameInstance* GI = Cast<UItemGameInstance>(GetGameInstance()))
    {
        GI->RecordChestOpened(Gained);
    }
    else
    {
        UE_LOG(LogTemp, Error,
            TEXT("[Chest] Game Instance Class is not UItemGameInstance. Check Project Settings."));
    }

    // 상자는 열린 뒤 사라진다. 객체는 다음 GC 때 수거된다.
    Destroy();
}