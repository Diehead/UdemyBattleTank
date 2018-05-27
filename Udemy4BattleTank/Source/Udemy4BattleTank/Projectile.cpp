// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AProjectile::AProjectile()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponent"));
	ProjectileMovementComponent->bAutoActivate = false;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Launch"));
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed); //ForwardVector is an UnitVector
	ProjectileMovementComponent->Activate();

}