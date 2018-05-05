// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurretSMComponent.h"
#include "Engine/World.h"

void UTankTurretSMComponent::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	float NewYaw = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0.f, NewYaw, 0.f));
}


