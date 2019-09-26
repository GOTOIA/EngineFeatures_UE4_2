// Fill out your copyright notice in the Description page of Project Settings.


#include "CFP_ShooterGameMode.h"
#include "Navmesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "CActorPool.h"


ACFP_ShooterGameMode::ACFP_ShooterGameMode() {

	NavMeshBoundsVolumePool = CreateDefaultSubobject<UCActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void ACFP_ShooterGameMode::PopulateBoundsVolumePool() {


	//Add to EnginFeaturesUE4.Build.cs file build data "NavigationSystem"
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
	

}





void ACFP_ShooterGameMode::AddToPool(class ANavMeshBoundsVolume *VolumeToAdd) {


	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());

}