// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrackSMComponent.h"



void UTankTrackSMComponent::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * TrackMaxDrivingForce * Throttle;
	FVector ForceLocation = GetComponentLocation(); // it is the Track Socket location

	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}




