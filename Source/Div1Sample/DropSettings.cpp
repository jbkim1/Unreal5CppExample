#include "DropSettings.h"

TWeakPtr<FDropSettings> FDropSettings::Shared;

FDropSettings::FDropSettings()
{
    UE_LOG(LogTemp, Warning, TEXT("[DropSettings] created"));
}

FDropSettings::~FDropSettings()
{
    // 순수 C++ 객체가 해제되는 순간이다.
    UE_LOG(LogTemp, Warning, TEXT("[DropSettings] destroyed"));
}

TSharedRef<FDropSettings> FDropSettings::Acquire()
{
    // Pin 이 성공하면 누군가 아직 쓰고 있다는 뜻이다. 같은 설정을 공유한다.
    if (TSharedPtr<FDropSettings> Existing = Shared.Pin())
    {
        return Existing.ToSharedRef();
    }

    TSharedRef<FDropSettings> Created = MakeShared<FDropSettings>();
    Shared = Created;
    return Created;
}