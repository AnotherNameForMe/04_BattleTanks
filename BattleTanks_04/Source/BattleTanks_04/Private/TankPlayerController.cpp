// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTanks_04.h"


void ATankPlayerController::BeginPlay()
{
	Super:: BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO Controller"))

	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlled by TankPlayerController!!!"), *(ControlledTank->GetName()));
}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowrdsCrosshairs();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowrdsCrosshairs()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //OUT parameter
	if (bGetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// Get world location if linetrace through crosshair
		// If it hits the landscape
		// Tell controlled tank to aim at this point
	}
}
bool ATankPlayerController::bGetSightRayHitLocation(FVector& OUTHitLocation) const
{
	OUTHitLocation = FVector(1);
	return false;
}