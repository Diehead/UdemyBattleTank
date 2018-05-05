// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelSMComponent.h"
#include "Engine/World.h"


void UTankBarrelSMComponent::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	float ClampedPitch = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(ClampedPitch, 0.f, 0.f));
}
