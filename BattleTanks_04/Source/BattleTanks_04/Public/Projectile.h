// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "ParticleDefinitions.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class StaticMeshComponent;

UCLASS()
class BATTLETANKS_04_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	void LaunchProjectile(float Speed);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit);
	
	UFUNCTION()
	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly)
	float DestroyDelay = 10.f;
	
	UPROPERTY(EditDefaultsOnly)
		float ProjectileDamage =20.f;

	UProjectileMovementComponent * ProjectileMovement = nullptr;
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent * CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent * LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent * ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere)
		URadialForceComponent* ExplosionForce = nullptr;


};
