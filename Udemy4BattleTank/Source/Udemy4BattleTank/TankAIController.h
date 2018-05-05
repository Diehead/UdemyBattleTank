// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class UDEMY4BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	ATank* GetPlayerTank() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

private:
	ATank* PlayerTank = nullptr;
	ATank* ControlledTank = nullptr;
};