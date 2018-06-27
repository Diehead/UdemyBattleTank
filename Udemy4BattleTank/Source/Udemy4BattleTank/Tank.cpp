// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrelSMComponent.h"
#include "TankTurretSMComponent.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "Engine/StaticMeshSocket.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
	
}

/*void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}*/

/*void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);	
}*/


/*void ATank::SetBarrelReference(UTankBarrelSMComponent* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}*/

/*void ATank::SetTurretReference(UTankTurretSMComponent* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}*/

/*void ATank::SetAimingComponent(UTankAimingComponent* TankAimingComponentToSet)
{
	TankAimingComponent = TankAimingComponentToSet;  NEEEEEEEEEEEEEEEEEEEEDED TO BE SET SOMEHOW!!!!!!!!!!!!!!!!!
}*/

/*void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("AAAAAAAAAAAAAJAJJAJAJAJJJJJJJJJJJJJJJJJJJ"));

	if (!ensure(Barrel))
	{
		return;
	}

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (ensure(Barrel && isReloaded))
	{
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, Barrel->GetSocketLocation("ProjectileSocket"),
			Barrel->GetSocketRotation("ProjectileSocket"));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		isReloaded = false;
	}
}*/