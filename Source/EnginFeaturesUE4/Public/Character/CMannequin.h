// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "CMannequin.generated.h"



UCLASS()
class ENGINFEATURESUE4_API ACMannequin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACMannequin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void UnPossessed() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class ACGUN> GunBlueprint;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PullTrigger();

private:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class ACGUN * Gun;



};
