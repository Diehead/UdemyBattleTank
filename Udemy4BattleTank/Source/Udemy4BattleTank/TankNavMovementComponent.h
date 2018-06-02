// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankNavMovementComponent.generated.h"

class UTankTrackSMComponent;

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class UDEMY4BATTLETANK_API UTankNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float value);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float value);
	
	UTankTrackSMComponent* LeftTrack = nullptr;
	UTankTrackSMComponent* RightTrack = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankTrackSMComponent* LeftTrackToSet, UTankTrackSMComponent* RightTrackToSet);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;	
};
