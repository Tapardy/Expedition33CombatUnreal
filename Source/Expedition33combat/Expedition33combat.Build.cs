// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Expedition33combat : ModuleRules
{
	public Expedition33combat(ReadOnlyTargetRules Target) : base(Target)
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
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Expedition33combat",
			"Expedition33combat/Variant_Platforming",
			"Expedition33combat/Variant_Combat",
			"Expedition33combat/Variant_Combat/AI",
			"Expedition33combat/Variant_SideScrolling",
			"Expedition33combat/Variant_SideScrolling/Gameplay",
			"Expedition33combat/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
