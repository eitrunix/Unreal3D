// Fill out your copyright notice in the Description page of Project Settings.


#include "LootCrate.h"

// Sets default values
ALootCrate::ALootCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int ALootCrate::GiveLoot(int _currencyGained)
{
	moneyInChest += _currencyGained;
	if (opened)
	{
		givenLoot = true;
	}
	return _currencyGained;
}

bool ALootCrate::SetOpened()
{
	if(!opened)
	{
		opened = true;
	}
	return opened;
}

bool ALootCrate::SetLootGiven()
{
	if(!givenLoot)
	{
		givenLoot = true;
	}
	return givenLoot;
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

