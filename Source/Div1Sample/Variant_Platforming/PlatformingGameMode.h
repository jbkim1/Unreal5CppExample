// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformingGameMode.generated.h"

/**
 *  Simple GameMode for a third person platforming game
 */
UCLASS()
class APlatformingGameMode : public AGameModeBase
{
	GENERATED_BODY()

private :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int goalCount;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int playerCount;

public:
	UFUNCTION(BlueprintCallable)
	bool addPlayCount(int src_count);
	
public:

	/** Constructor */
	APlatformingGameMode();
};
