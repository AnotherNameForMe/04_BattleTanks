// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks_04.h"
#include "TankPlayerController.h"

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
	// Get world location if linetrace through crosshair
	// If it hits the landscape
	// Tell controlled tank to aim at this point
}