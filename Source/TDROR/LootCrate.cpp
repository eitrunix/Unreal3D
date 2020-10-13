// Fill out your copyright notice in the Description page of Project Settings.


#include "LootCrate.h"
#include <StaticMeshResources.h>



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
		baseMoneyInChest = 8;
		GiveMoney();
		return baseMoneyInChest;
		break;
	case Small:
		baseChestCost = 10;

		GiveItemLoot();
		SpawnObject(GetActorLocation(), GetActorRotation());
		return baseChestCost;
		break;
	case Medium:
		baseChestCost = 20;

		GiveItemLoot();
		SpawnObject(GetActorLocation(), GetActorRotation());

		return baseChestCost;
		break;
	case Large:
		baseChestCost = 30;

		GiveItemLoot();
		SpawnObject(GetActorLocation(), GetActorRotation());
		return baseChestCost;

		break;
	default:
		return 0;
		break;
	}
}
int ALootCrate::GiveMoney()
{
	int tmpMoney = baseMoneyInChest;
	if (opened)
	{
		SetLooted();
		return tmpMoney;
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
	int tmpCost = baseChestCost;
	if (opened)
	{
		SetLooted();
		return tmpCost;
	}
	return 0;
}

void ALootCrate::SpawnObject(FVector Loc, FRotator Rot)
{
	TSubclassOf<AActor> tempItem;
	FVector offSet;
	offSet = Loc;

	offSet.X -= 20.0f;
	offSet.Y;
	offSet.Z += 35.0f;
	tempItem = GetItemFromArray();
	FActorSpawnParameters SpawnParams;
	AActor* spawnedItemRef = GetWorld()->SpawnActor<AActor>(tempItem, offSet, Rot, SpawnParams);
}

TSubclassOf<AActor> ALootCrate::GetItemFromArray()
{
	int Rand;
	Rand = FMath::RandRange(0, spawnedItemArray.Num() - 1);

	for (int i = 0; i < spawnedItemArray.Num(); i++)
	{
		if (i == Rand)
		{
			return spawnedItemArray[i];
		}
	}
	return 0;
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

