// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPickup.h"

// Sets default values
AItemPickup::AItemPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float AItemPickup::IncreaseStat(float _StatToIncrease, float _IncreaseBy)
{
	_StatToIncrease += _IncreaseBy;

	return _StatToIncrease;
}

// Called when the game starts or when spawned
void AItemPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//switch (rarity)
//{
//case Common:
//	break;
//case Uncommon:
//	break;
//case Rare:
//	break;
//case Mythic:
//	break;
//}
