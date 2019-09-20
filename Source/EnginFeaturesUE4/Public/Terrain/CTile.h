// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTile.generated.h"

UCLASS()
class ENGINFEATURESUE4_API ACTile : public AActor
{
	GENERATED_BODY()

private :
	
	UFUNCTION(BlueprintCallable, Category = "Component")
		void PlaceActors(TSubclassOf<AActor>ToSpawn, int minSpawn, int maxSpawn);

	
public:	
	// Sets default values for this actor's properties
	ACTile();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
