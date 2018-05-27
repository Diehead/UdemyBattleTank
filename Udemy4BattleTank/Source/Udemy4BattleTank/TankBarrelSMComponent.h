// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelSMComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UDEMY4BATTLETANK_API UTankBarrelSMComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:	
	void Elevate(float RelativeSpeed);

public:
	UPROPERTY(EditDefaultsOnly)
	float MaxDegreesPerSecond = 5.f;

	UPROPERTY(EditDefaultsOnly)
	float MaxElevationDegrees = 60.f;

	UPROPERTY(EditDefaultsOnly)
	float MinElevationDegrees = 0.f;
};
