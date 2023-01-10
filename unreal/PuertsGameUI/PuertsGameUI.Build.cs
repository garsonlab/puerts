using System;
using System.IO;
using UnrealBuildTool;

public class PuertsGameUI : ModuleRules {
	public PuertsGameUI(ReadOnlyTargetRules target) : base(target) {
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", "CoreUObject", "Engine", "SlateCore", "Slate", "Puerts", "UMG", "Blutility",
			}
		);
		if (target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}
	}
}