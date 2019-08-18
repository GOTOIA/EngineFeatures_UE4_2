// Fill out your copyright notice in the Description page of Project Settings.


#include "CPatrollingGuard.h"

TArray<AActor*> ACPatrollingGuard::GetPatrolPoints() const
{
	return PatrolPointsCPP;
}