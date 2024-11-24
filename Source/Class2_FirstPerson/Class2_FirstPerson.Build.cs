// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Class2_FirstPerson : ModuleRules
{
	public Class2_FirstPerson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
