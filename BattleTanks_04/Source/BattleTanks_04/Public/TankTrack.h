// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set max drive force and apply them to Tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_04_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly)
		float TackMaxDriveForce = 400000;
	
private:
	UTankTrack();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitCOmponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	virtual void BeginPlay()override;

	void ApplySideForce();
	void DriveTrack();

	float CurrentThrottle = 0.0f;



};
