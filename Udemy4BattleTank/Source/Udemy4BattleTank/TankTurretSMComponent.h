// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurretSMComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UDEMY4BATTLETANK_API UTankTurretSMComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);
	

public:
	UPROPERTY(EditDefaultsOnly)
	float MaxDegreesPerSecond = 9.f;
	
};
