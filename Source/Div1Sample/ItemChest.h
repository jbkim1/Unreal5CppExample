#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemData.h"
#include "DropSettings.h"
#include "ItemChest.generated.h"

class UBoxComponent;
class UInventoryComponent;
class UStaticMeshComponent;
class UTexture2D;

// Blueprintable: 이 클래스를 부모로 하는 블루프린트를 만들 수 있다.
// 로직과 규칙은 C++ 에 두고, 메시 · 이름 · 아이콘 같은 값은 파생 블루프린트에서 채운다.
UCLASS(Blueprintable)
class DIV1SAMPLE_API AItemChest : public AActor
{
    GENERATED_BODY()

public:
    AItemChest();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Chest")
    TObjectPtr<UBoxComponent> Collision;

    UPROPERTY(VisibleAnywhere, Category = "Chest")
    TObjectPtr<UStaticMeshComponent> Body;

    UPROPERTY(EditAnywhere, Category = "Chest")
    FString ItemName = TEXT("Potion");

    UPROPERTY(EditAnywhere, Category = "Chest")
    EItemGrade Grade = EItemGrade::Common;

    // 에디터에서 에셋을 지정한다. 레벨이 로드될 때 함께 로드되지 않는다.
    UPROPERTY(EditAnywhere, Category = "Chest")
    TSoftObjectPtr<UTexture2D> ItemIcon;

private:
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);

    void Open(AActor* Opener, UInventoryComponent* Inventory);

    // 순수 C++ 설정을 여러 상자가 함께 쓴다. UObject 가 아니므로 UPROPERTY 를 붙이지 않는다.
    TSharedPtr<FDropSettings> DropSettings;

    bool bOpened = false;
};