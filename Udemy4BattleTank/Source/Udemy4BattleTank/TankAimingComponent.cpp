// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "TankBarrelSMComponent.h"
#include "TankTurretSMComponent.h"
#include "Projectile.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = FPlatformTime::Seconds();
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (RoundsLeft <= 0)
	{
		FiringState = EFiringState::OutOfAmmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Locked;
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }

	FVector BarrelFroward = Barrel->GetForwardVector();
	return !BarrelFroward.Equals(AimDirection, 0.01f);
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank aiming at %s"), *HitLocation.ToString())
	
	if (!ensure(Barrel))
	{
		return;
	}

	FVector outVelocity;
	FVector barrelSocketLocation = Barrel->GetSocketLocation("ProjectileSocket");

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, outVelocity, barrelSocketLocation, HitLocation, LaunchSpeed, 
	false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		AimDirection = outVelocity.GetSafeNormal();
	//	UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString());
		
		MoveBarrelTowards(AimDirection);
	}
}


void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel))
	{
		return;
	}

	//bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	//if (FiringState != EFiringState::Reloading)
	if (FiringState == EFiringState::Locked || FiringState == EFiringState::Aiming)
	{
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, Barrel->GetSocketLocation("ProjectileSocket"),
			Barrel->GetSocketRotation("ProjectileSocket"));
		if (ensure(Projectile))
		{
			Projectile->LaunchProjectile(LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
			RoundsLeft--;
		}
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotation = AimAsRotator - BarrelRotation;
	

	//UE_LOG(LogTemp, Warning, TEXT("DeltaRotation.Pitch = %f"), DeltaRotation.Pitch);
	Barrel->Elevate(DeltaRotation.Pitch);
	float newYaw = (DeltaRotation.Yaw > 180.f) ? (360 - DeltaRotation.Yaw) * (-1.f) : DeltaRotation.Yaw;
	Turret->Rotate(newYaw);
}

void UTankAimingComponent::Initialize(UTankBarrelSMComponent* BarrelToSet, UTankTurretSMComponent* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;


}

int32 UTankAimingComponent::GetRoundsLeft() const
{
	return RoundsLeft;
}