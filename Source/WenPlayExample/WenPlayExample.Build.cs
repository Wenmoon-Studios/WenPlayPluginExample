// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

using UnrealBuildTool;

public class WenPlayExample : ModuleRules
{
	public WenPlayExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
