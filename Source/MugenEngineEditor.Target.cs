// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

using UnrealBuildTool;
using System.Collections.Generic;

public class MugenEngineEditorTarget : TargetRules
{
	public MugenEngineEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "MugenEngine" } );
	}
}
