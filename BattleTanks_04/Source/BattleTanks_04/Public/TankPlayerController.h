// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

class ATank;
UCLASS()
class BATTLETANKS_04_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	




	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	void AimTowrdsCrosshairs();

	bool bGetSightRayHitLocation(FVector& OUTHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .33333f;

	UPROPERTY(EditAnywhere)
		float LineRange = 1000000;

	bool bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector ScreenLocation, FVector &LookDircetion) const;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank * GetControlledTank() const;

};
