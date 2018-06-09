// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "TankBarrelSMComponent.h"
#include "TankTurretSMComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
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

	if (ensure(bHaveAimSolution))
	{
		FVector AimDirection = outVelocity.GetSafeNormal();
	//	UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString());
		
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotation = AimAsRotator - BarrelRotation;
	

	//UE_LOG(LogTemp, Warning, TEXT("DeltaRotation.Pitch = %f"), DeltaRotation.Pitch);
	Barrel->Elevate(DeltaRotation.Pitch);
	Turret->Rotate(DeltaRotation.Yaw);
}

/*void UTankAimingComponent::SetBarrelReference(UTankBarrelSMComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurretSMComponent* TurretToSet)
{
	Turret = TurretToSet;
}*/

void UTankAimingComponent::Initialize(UTankBarrelSMComponent* BarrelToSet, UTankTurretSMComponent* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}