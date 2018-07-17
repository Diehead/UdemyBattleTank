// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"

class UTankAimingComponent;


/**
 * 
 */
UCLASS()
class UDEMY4BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	virtual void SetPawn(APawn* InPawn) override;

	APawn* GetPlayerTank() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Setup")
	float AcceptanceRadius = 8000.f;

	

protected:
	UFUNCTION()
	void OnPossessedTankDeath();

private:
	APawn* GetControlledTank() const;
	
	


private:
	APawn* PlayerTank = nullptr;
	APawn* ControlledTank = nullptr;
	UTankAimingComponent* AimingComponent = nullptr;
};
