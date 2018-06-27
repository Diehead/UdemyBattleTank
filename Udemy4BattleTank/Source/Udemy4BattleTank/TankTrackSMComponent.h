// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrackSMComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UDEMY4BATTLETANK_API UTankTrackSMComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankTrackSMComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float Throttle);


public:
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // Assume 40 tonne tank and 1g acceleration

protected:
	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();
	void ApplySidewaysForce();
	
private:	
	float CurrentThrottle = 0.f;
};
