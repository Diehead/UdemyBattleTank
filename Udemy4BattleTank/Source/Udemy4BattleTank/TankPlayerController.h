// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class UDEMY4BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& outHitLocation) const;
	
private:
	ATank* ControlledTank = nullptr;
};
