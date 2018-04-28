// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();

}


ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* tank = nullptr;

	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		tank = Cast<ATank>(ControlledPawn);
		UE_LOG(LogTemp, Warning, TEXT("Tank pawn name=%s"), *ControlledPawn->GetName()); // Log,Warning,Error
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get a tank"));
	}
	return tank;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();


}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ControlledTank)
	{
		return;
	}

	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation))
	{
		ControlledTank->AimAt(hitLocation);
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