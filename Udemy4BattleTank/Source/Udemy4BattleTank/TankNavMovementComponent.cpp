// Fill out your copyright notice in the Description page of Project Settings.

#include "TankNavMovementComponent.h"
#include "TankTrackSMComponent.h"



void UTankNavMovementComponent::IntendMoveForward(float value)
{
	LeftTrack->SetThrottle(value);
	RightTrack->SetThrottle(value);
}

void UTankNavMovementComponent::Initialize(UTankTrackSMComponent* LeftTrackToSet, UTankTrackSMComponent* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankNavMovementComponent::IntendTurnRight(float value)
{
	LeftTrack->SetThrottle(value);
	RightTrack->SetThrottle(-value);
}

void UTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	float intendMove = FVector::DotProduct(TankForward, AIForwardIntention);

	UE_LOG(LogTemp, Warning, TEXT("intendMove =%f"), intendMove);

	IntendMoveForward(intendMove);



	//UE_LOG(LogTemp, Warning, TEXT("AI: Plater Tank pawn name=%s"), *playerTank->GetName());
	//UE_LOG(LogTemp, Warning, TEXT("%s is vectoring to %s"), *name, *MoveVelocityStr);

}