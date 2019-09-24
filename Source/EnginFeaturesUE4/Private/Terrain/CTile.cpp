// Fill out your copyright notice in the Description page of Project Settings.


#include "CTile.h"
#include "DrawDebugHelpers.h"


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

	CastSphere(GetActorLocation(), 300);
	CastSphere(GetActorLocation() + FVector(0, 0, 1000), 300);
	
}

// Called every frame
void ACTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACTile::PlaceActors(TSubclassOf<AActor>ToSpawn,int minSpawn, int maxSpawn) {


	//TODO Resize scene
	FVector min(0, -2000, 0);
	FVector max(4000, 2000, 0);
	FBox bounds(min, max);
	
	int numberToSpawn = FMath::RandRange(minSpawn, maxSpawn);
	//Generating random number
	for (size_t i = 0; i < numberToSpawn; i++)
	{
		FVector spawnPoint = FMath::RandPointInBox(bounds);
		AActor *spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
		spawned->SetActorRelativeLocation(spawnPoint);
		spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	}

}

bool ACTile::CastSphere(FVector Location, float Radius)
{
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Location,
		Location,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);
	FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	DrawDebugSphere(GetWorld(), Location, Radius, 100, ResultColor, true, 100);
	return HasHit;
}