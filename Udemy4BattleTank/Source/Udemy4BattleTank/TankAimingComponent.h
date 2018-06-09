// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading
};


class UTankBarrelSMComponent;
class UTankTurretSMComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY4BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrelSMComponent* BarrelToSet, UTankTurretSMComponent* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
	/*void SetBarrelReference(UTankBarrelSMComponent* BarrelToSet);
	void SetTurretReference(UTankTurretSMComponent* TurretToSet);*/


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

private:
	void MoveBarrelTowards(FVector AimDirection);

private:
	UTankBarrelSMComponent* Barrel;
	UTankTurretSMComponent* Turret;
};
