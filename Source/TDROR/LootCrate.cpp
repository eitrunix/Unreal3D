// Fill out your copyright notice in the Description page of Project Settings.


#include "LootCrate.h"

// Sets default values
ALootCrate::ALootCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int ALootCrate::Loot()
{
	SetOpened();

	switch (type)
	{
	case CashBox:
		GiveMoney();
		return moneyInChest;
		break;
	case Small:
		GiveItemLoot();
		return chestCost;
		break;
	case Medium:
		return 0;
		break;
	case Large:
		return 0;
		break;
	default:
		return 0;
		break;
	}
}
int ALootCrate::GiveMoney()
{
	if (opened)
	{
		SetLooted();
		return moneyInChest;
	}
	return 0;
}

bool ALootCrate::SetOpened()
{
	if(!opened)
	{
		opened = true;
	}
	return opened;
}

bool ALootCrate::SetLooted()
{
	if(!givenLoot)
	{
		givenLoot = true;
	}
	return givenLoot;
}

int ALootCrate::GiveItemLoot()
{
	chestCost = 0 - chestCost;
	if (opened)
	{
		SetLooted();
	}
	return chestCost;
}

// Called when the game starts or when spawned
void ALootCrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALootCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

