// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class EnginFeaturesUE4Target : TargetRules
{
	public EnginFeaturesUE4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "EnginFeaturesUE4" } );
	}
}
