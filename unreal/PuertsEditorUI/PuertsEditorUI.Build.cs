using System;
using System.IO;
using UnrealBuildTool;

public class PuertsEditorUI : ModuleRules {
    public PuertsEditorUI(ReadOnlyTargetRules target) : base(target) {
        // Needed for class derived from UEditorUtilityWidget, only EditorOnly UClass is allowed.
        OverridePackageType = PackageOverrideType.EditorOnly;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
				"Core", "CoreUObject", "Engine", "SlateCore", "Slate", "Puerts", "UMG", "Blutility", "PuertsGameUI",
            }
        );
        PrivateDependencyModuleNames.Add("UnrealEd");
    }
}
