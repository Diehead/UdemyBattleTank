// Fill out your copyright notice in the Description page of Project Settings.
#include "TankTrackSMComponent.h"
#include "Engine/World.h"
#include "Delegate.h"



UTankTrackSMComponent::UTankTrackSMComponent()
{
	PrimaryComponentTick.bCanEverTick = false;


}

void UTankTrackSMComponent::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrackSMComponent::OnCompHit);

}

void UTankTrackSMComponent::OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0.f;
}

void UTankTrackSMComponent::ApplySidewaysForce()
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	float SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	FVector Accelleration = -SlippageSpeed / DeltaTime * GetRightVector();

	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent()); // COULD BE MOVED TO BEGINPLAY
	if (TankRoot)
	{
		float TankMass = TankRoot->GetMass();

		// F = m * a 
		FVector CorrectionForce = (TankMass * Accelleration) / 2; // due to 2 tracks
		TankRoot->AddForce(CorrectionForce);
	}
}

void UTankTrackSMComponent::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1.f, 1.f);

}

void UTankTrackSMComponent::DriveTrack()
{
	FVector ForceApplied = GetForwardVector() * TrackMaxDrivingForce * CurrentThrottle;
	FVector ForceLocation = GetComponentLocation(); // it is the Track Socket location

	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


