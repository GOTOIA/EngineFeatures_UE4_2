// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
//#include "Public/CPatrollingGuard.h" // TODO remove coupling, add ActorComponent patrolPoints
#include "Public/NPC/PatrolRoute.h"
#include "CChooseNextWayPoint.generated.h"


/**
 * 
 */
UCLASS()
class ENGINFEATURESUE4_API UCChooseNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	protected:
		UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IndexKey;

		UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaypointKey;


};
