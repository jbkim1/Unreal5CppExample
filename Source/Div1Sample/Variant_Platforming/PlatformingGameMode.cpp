// Copyright Epic Games, Inc. All Rights Reserved.


#include "Variant_Platforming/PlatformingGameMode.h"

APlatformingGameMode::APlatformingGameMode(): goalCount(1), playerCount(0)
{
	// stub
}

// 누적 수량을 더하고 목표 달성 여부를 판정한다
bool APlatformingGameMode::addPlayCount(int src_count)
{
	playerCount += src_count;

	if (playerCount >= goalCount)
	{
		return true;
	}

	return false;
}