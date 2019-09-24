// Fill out your copyright notice in the Description page of Project Settings.


#include "CTile.h"
#include "DrawDebugHelpers.h"


//Sub find a good location (empty)
bool ACTile::FindEmptyLocation(FVector & OutLocation, float Radius)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	
	const int MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius)) {
			OutLocation = CandidatePoint;
			return true;
		}
	}
	return false;
}


//Sub PlaceActore blueprintable
void ACTile::PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}




// Sets default values
ACTile::ACTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACTile::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void ACTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//If empty location then place actor
void ACTile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius) {
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint;
		bool found = FindEmptyLocation(SpawnPoint, Radius);
		if (found) {
			PlaceActor(ToSpawn, SpawnPoint);
		}
	}
}


bool ACTile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);
	FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	
	DrawDebugCapsule(GetWorld(), GlobalLocation, 0, Radius, FQuat::Identity, ResultColor, true, 100);
	return !HasHit;
}