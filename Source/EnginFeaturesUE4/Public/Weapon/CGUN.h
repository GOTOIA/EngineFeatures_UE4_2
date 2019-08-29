// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGUN.generated.h"

UCLASS()
class ENGINFEATURESUE4_API ACGUN : public AActor
{
	GENERATED_BODY()

		/** Gun mesh */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;


	
public:	
	// Sets default values for this actor's properties
	ACGUN();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ACWeaponProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;

	/* This is when calculating the trace to determine what the weapon has hit */
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//	float WeaponRange;

	/* This is multiplied by the direction vector when the weapon trace hits something to apply velocity to the component that is hit */
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//	float WeaponDamage;


	/** Fires a virtual projectile. */
	UFUNCTION(BlueprintCallable, Category = "Action")
	void OnFire();

	//FHitResult WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const;

};
