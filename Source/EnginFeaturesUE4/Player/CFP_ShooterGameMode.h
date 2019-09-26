// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/FP_FirstPersonGameMode.h"
#include "CFP_ShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ENGINFEATURESUE4_API ACFP_ShooterGameMode : public AFP_FirstPersonGameMode
{
	GENERATED_BODY()

	public:

		ACFP_ShooterGameMode();

		UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
		void PopulateBoundsVolumePool();
	
	protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
		class UCActorPool* NavMeshBoundsVolumePool;

	private:

	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
	
};
