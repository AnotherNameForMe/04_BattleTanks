// Copyright EmbracedIT Ltd.

#pragma once


#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

class UTankAimComponent;
/**
*Responsible for Player aim
*/
UCLASS()
class BATTLETANKS_04_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	
	virtual void BeginPlay() override;
	
	void SetPawn(APawn * InPawn);

	

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
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimComponent(UTankAimComponent* AimCompRef);

	UFUNCTION()
	void OnTanksDeath();
};
