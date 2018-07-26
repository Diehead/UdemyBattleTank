// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{

	UE_LOG(LogTemp, Warning, TEXT("AI"));

	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	PlayerTank = GetPlayerTank();

	AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}

}

APawn* ATankAIController::GetPlayerTank() const
{
	APawn* playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		
	return playerPawn;
}

APawn* ATankAIController::GetControlledTank() const
{
	APawn* pawn = GetPawn();
	return pawn;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(ControlledTank) || !ensure(AimingComponent))
	{
		return;
	}



	if (ensure(PlayerTank))
	{
		
		MoveToActor(PlayerTank, AcceptanceRadius);
		
		FVector playerLocation = PlayerTank->GetActorLocation();
		AimingComponent->AimAt(playerLocation);

		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire();
		}
	}
	
}

void ATankAIController::OnPossessedTankDeath()
{
	APawn* pawn = GetPawn();
	if (pawn)
	{
		pawn->DetachFromControllerPendingDestroy();
	}	
}
