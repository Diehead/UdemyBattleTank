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

//	void AimAt(FVector HitLocation);
	

//	virtual void BeginPlay() override;
	/*UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrelSMComponent* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurretSMComponent* TurretToSet);*/

	
	
	/*UFUNCTION(BlueprintCallable, Category = Setup)
	void SetAimingComponent(UTankAimingComponent* TankAimingComponentToSet);*/

	/*UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();*/

public:
	/*UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBP;*/

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, 
	class AController* EventInstigator, AActor* DamageCauser) override;
	
	

	UPROPERTY(EditAnywhere, Category = Setup)
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = Setup)
	int32 CurrentHealth = StartingHealth;

protected:
/*	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;*/

private:
/*	UTankBarrelSMComponent* Barrel;

	double ReloadTimeInSeconds = 3;
	double LastFireTime = 0;*/
};
