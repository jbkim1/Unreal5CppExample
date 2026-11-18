// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Div1Sample : ModuleRules
{
	public Div1Sample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"HealthKit"	// 12-2: 플러그인 모듈 의존성
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Div1Sample",
			"Div1Sample/Variant_Platforming",
			"Div1Sample/Variant_Platforming/Animation",
			"Div1Sample/Variant_Combat",
			"Div1Sample/Variant_Combat/AI",
			"Div1Sample/Variant_Combat/Animation",
			"Div1Sample/Variant_Combat/Gameplay",
			"Div1Sample/Variant_Combat/Interfaces",
			"Div1Sample/Variant_Combat/UI",
			"Div1Sample/Variant_SideScrolling",
			"Div1Sample/Variant_SideScrolling/AI",
			"Div1Sample/Variant_SideScrolling/Gameplay",
			"Div1Sample/Variant_SideScrolling/Interfaces",
			"Div1Sample/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
