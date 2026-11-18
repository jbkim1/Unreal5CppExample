// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HealthKit : ModuleRules
{
	public HealthKit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// 공개 헤더(HealthKitComponent.h)가 UActorComponent 를 상속하므로
		// CoreUObject · Engine 을 Public 배열에 둔다. (12-1 3-4절)
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
