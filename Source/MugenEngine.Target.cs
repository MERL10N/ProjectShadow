// Sega owns the rights of Sonic The Hedgehog. Work done is done for learning purposes.

using UnrealBuildTool;
using System.Collections.Generic;

public class MugenEngineTarget : TargetRules
{
	public MugenEngineTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "MugenEngine" } );
	}
}
