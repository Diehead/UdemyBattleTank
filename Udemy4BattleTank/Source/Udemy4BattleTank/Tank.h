// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrelSMComponent;
class UTankAimingComponent;
class UTankTurretSMComponent;
class AProjectile;

UCLASS()
class UDEMY4BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrelSMComponent* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurretSMComponent* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> Projectile;

private:
	UTankAimingComponent* TankAimingComponent = nullptr;
	UTankBarrelSMComponent* Barrel;
	
};