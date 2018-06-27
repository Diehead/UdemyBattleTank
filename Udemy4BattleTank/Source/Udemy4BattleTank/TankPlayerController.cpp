// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
//#include "Tank.h"
#include "Camera/PlayerCameraManager.h"
#include "TankAimingComponent.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//ATank* ControlledTank = GetControlledTank();
	
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}

	

}


ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* tank = nullptr;

	APawn* ControlledPawn = GetPawn();
	return tank;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();


}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(AimingComponent))
	{
		return;
	}

	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation))
	{
		AimingComponent->AimAt(hitLocation);
	}

	

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const
{
	outHitLocation = FVector(0);

	int32 viewportSizeX, viewportSizeY = 0;
	GetViewportSize(viewportSizeX, viewportSizeY);

	FVector2D crosshairViewport = FVector2D(viewportSizeX * CrosshairXLocation, viewportSizeY * CrosshairYLocation);

	FVector crosshairWorldLoc, crosshairWorldDir;
	if (DeprojectScreenPositionToWorld(crosshairViewport.X, crosshairViewport.Y, crosshairWorldLoc, crosshairWorldDir))
	{
		FVector startLocation = PlayerCameraManager->GetCameraLocation();
		FVector endLocation = startLocation + (crosshairWorldDir * LineTraceRange);
		
		FHitResult outHit;
		if (GetWorld()->LineTraceSingleByChannel(outHit, startLocation, endLocation, ECollisionChannel::ECC_Visibility))
		{
			outHitLocation = outHit.Location;
			return true;
		}
	}
	return false;
}