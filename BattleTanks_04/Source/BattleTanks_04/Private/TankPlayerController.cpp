// Copyright EmbracedIT Ltd.

#include "TankPlayerController.h"
#include "TankAimComponent.h"
#include "Tank.h"
#include "BattleTanks_04.h"


void ATankPlayerController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnTanksDeath);
	}
}

void ATankPlayerController::OnTanksDeath()
{
	StartSpectatingOnly();
}

void ATankPlayerController::BeginPlay()
{
	Super:: BeginPlay();
	auto AimComponent = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (!ensure(AimComponent)) { return; }
	{
		FoundAimComponent(AimComponent);
	}

}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowrdsCrosshairs();

}

void ATankPlayerController::AimTowrdsCrosshairs()
{
	if (!GetPawn()) { return; }

	auto AimComponent = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (!ensure(AimComponent)) { return; }

	FVector OUTHitLocation; //OUT parameter
	bool bGotHitLocation = bGetSightRayHitLocation(OUTHitLocation);

	if (bGotHitLocation)
	{
		AimComponent->AimAt(OUTHitLocation);
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
		return GetLookVectorHitLocation(LookDirection, OUTHitLocation);
	
	}

	return false;
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

	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation, ECollisionChannel::ECC_Camera))
	{
		OUTHitLocation = HitResult.Location;
			return true;
	}
	OUTHitLocation = FVector(0);
	return false;
}
