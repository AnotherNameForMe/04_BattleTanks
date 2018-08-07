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
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		// Get world location if linetrace through crosshair
		// If it hits the landscape
		// Tell controlled tank to aim at this point
	}
}
bool ATankPlayerController::bGetSightRayHitLocation(FVector& OUTHitLocation) const
{
	//find crosshair position

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;
	if (bGetLookDirection(ScreenLocation, LookDirection))
	{
		//linetrace along that look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OUTHitLocation);
	
	}
	return true;
}
bool ATankPlayerController::bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OUTHitLocation) const
{
	FHitResult HitResult; 
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OUTHitLocation = HitResult.Location;
			return true;
	}
	OUTHitLocation = FVector(0);
	return false;
}
