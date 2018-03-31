// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Udemy4BattleTankEditorTarget : TargetRules
{
	public Udemy4BattleTankEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Udemy4BattleTank" } );
	}
}
