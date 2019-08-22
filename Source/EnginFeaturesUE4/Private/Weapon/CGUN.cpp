// Fill out your copyright notice in the Description page of Project Settings.


#include "CGUN.h"
#include "Animation/AnimInstance.h"
#include "Weapon/CWeaponProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACGUN::ACGUN()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// Only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;		// Disallow mesh to cast dynamic shadows
	FP_Gun->CastShadow = false;			// Disallow mesh to cast other shadows
	//FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint_1"));

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Set weapon damage and range
	//WeaponRange = 5000.0f;
	//WeaponDamage = 500000.0f;
}

// Called when the game starts or when spawned
void ACGUN::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACGUN::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACGUN::OnFire()
{
	

		// try and fire a projectile
		if (ProjectileClass != NULL)
		{
			const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();;
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();

			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				// spawn the projectile at the muzzle
				World->SpawnActor<ACWeaponProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			}
		}
		// Play a sound if there is one
		if (FireSound != NULL)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		// Try and play a firing animation if specified
		if (FireAnimation != NULL)
		{
			// Get the animation object for the arms mesh
			
			if (AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}

		// Now send a trace from the end of our gun to see if we should hit anything
		/*APlayerController* PlayerController = Cast<APlayerController>(GetController());

		FVector ShootDir = FVector::ZeroVector;
		FVector StartTrace = FVector::ZeroVector;

		if (PlayerController)
		{
			// Calculate the direction of fire and the start location for trace
			FRotator CamRot;
			PlayerController->GetPlayerViewPoint(StartTrace, CamRot);
			ShootDir = CamRot.Vector();

			// Adjust trace so there is nothing blocking the ray between the camera and the pawn, and calculate distance from adjusted start
			StartTrace = StartTrace + ShootDir * ((GetActorLocation() - StartTrace) | ShootDir);
		}

		// Calculate endpoint of trace
		const FVector EndTrace = StartTrace + ShootDir * WeaponRange;

		// Check for impact
		const FHitResult Impact = WeaponTrace(StartTrace, EndTrace);

		// Deal with impact
		AActor* DamagedActor = Impact.GetActor();
		UPrimitiveComponent* DamagedComponent = Impact.GetComponent();

		// If we hit an actor, with a component that is simulating physics, apply an impulse
		if ((DamagedActor != NULL) && (DamagedActor != this) && (DamagedComponent != NULL) && DamagedComponent->IsSimulatingPhysics())
		{
			DamagedComponent->AddImpulseAtLocation(ShootDir * WeaponDamage, Impact.Location);
		}*/
	

}


/*FHitResult  ACGUN::WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const
{
	// Perform trace to retrieve hit info
	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(WeaponTrace), true, Instigator);
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_WEAPON, TraceParams);

	return Hit;
}*/

