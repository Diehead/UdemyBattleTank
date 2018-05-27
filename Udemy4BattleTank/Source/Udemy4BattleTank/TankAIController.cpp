// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{

	UE_LOG(LogTemp, Warning, TEXT("AI"));

	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	PlayerTank = GetPlayerTank();
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* playerTank = nullptr;
	APawn* playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (playerPawn)
	{
		playerTank = Cast<ATank>(playerPawn);
		UE_LOG(LogTemp, Warning, TEXT("AI: Plater Tank pawn name=%s"), *playerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: Plater Tank NOT FOUND"));
	}
	return playerTank;
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* tank = nullptr;
	
	APawn* pawn = GetPawn();
	if (pawn)
	{
		tank = Cast<ATank>(pawn);
	}
		
	return tank;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ControlledTank)
	{
		return;
	}

	if (PlayerTank)
	{
		FVector playerLocation = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(playerLocation);
		ControlledTank->Fire();

	}
	
}


