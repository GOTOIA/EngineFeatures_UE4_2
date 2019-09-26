// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "CTile.generated.h"


class UCActorPool;


UCLASS()
class ENGINFEATURESUE4_API ACTile : public AActor
{
	GENERATED_BODY()

private :
	
	UFUNCTION(BlueprintCallable, Category = "Component")
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);



	bool FindEmptyLocation(FVector& OutLocation, float Radius);
	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Rotation, float Scale);
	bool CanSpawnAtLocation(FVector Location, float Radius);

	UCActorPool* Pool;
	
public:	
	// Sets default values for this actor's properties
	ACTile();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pool")
		void SetPool(UCActorPool* inPool);

};
