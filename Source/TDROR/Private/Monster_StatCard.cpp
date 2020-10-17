// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster_StatCard.h"

// Sets default values for this component's properties
UMonster_StatCard::UMonster_StatCard()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	currentSpawnCost = baseSpawnCost;

	// ...
}


int UMonster_StatCard::GetBaseCost()
{
	return currentSpawnCost;
}

void UMonster_StatCard::SetCost(int _newCost)
{
	currentSpawnCost = _newCost;
}

int UMonster_StatCard::IncreaseCost(float _coeff)
{
	int newTmpCost;
	newTmpCost = baseSpawnCost * _coeff;
	SetCost(newTmpCost);

	return newTmpCost;
}

// Called when the game starts
void UMonster_StatCard::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMonster_StatCard::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

