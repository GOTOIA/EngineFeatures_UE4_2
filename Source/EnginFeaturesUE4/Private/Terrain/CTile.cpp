// Fill out your copyright notice in the Description page of Project Settings.


#include "CTile.h"

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


void ACTile::PlaceActors() {

	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	//Generating random number
	for (size_t i = 0; i < 20; i++)
	{
		FVector SpawnPoint = FMath::RandPointInBox(Bounds);
		UE_LOG(LogTemp, Warning, TEXT("SpawnPoint: %s"), *SpawnPoint.ToCompactString())
	}

}

