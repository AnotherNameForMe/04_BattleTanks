// Copyright EmbraceIT LTD.

#include "SprungWheel.h"



// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WheelConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Wheel Constraint Component"));
	WheelConstraintComponent->AttachToComponent(WheelConstraintComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	Axles = CreateDefaultSubobject<USphereComponent>(FName("Axles"));
	Axles->AttachToComponent(WheelConstraintComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Wheels = CreateDefaultSubobject<USphereComponent>(FName("Wheels"));
	Wheels->AttachToComponent(Axles, FAttachmentTransformRules::KeepRelativeTransform);

	AxleConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Axle Constraint Component"));
	AxleConstraintComponent->AttachToComponent(Axles, FAttachmentTransformRules::KeepRelativeTransform);

	

	

	}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraints();
	
 }

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::SetupConstraints()
{
	if (!GetAttachParentActor()) return;
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) return;
	WheelConstraintComponent->SetConstrainedComponents(BodyRoot, NAME_None, Axles, NAME_None);
	AxleConstraintComponent->SetConstrainedComponents(Axles, NAME_None, Wheels, NAME_None);


}

