// Fill out your copyright notice in the Description page of Project Settings.


#include "CActorPool.h"

// Sets default values for this component's properties
UCActorPool::UCActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



AActor * UCActorPool::Checkout()
{
	return nullptr;
}

void UCActorPool::Return(AActor * ActorToReturn)
{
}

void UCActorPool::Add(AActor * ActorToAdd)
{
}
