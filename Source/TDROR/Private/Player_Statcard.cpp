// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Statcard.h"

// Sets default values for this component's properties
UPlayer_Statcard::UPlayer_Statcard()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Player_Level = 0;
	health_Per_Level = 0;
	damage_Per_Level = 0;

	base_Armour = 0;
	base_Sprint_Armour = 0;
	base_Bleed_Chance = 0;
	base_Damage = 0;
	base_Crit_Chance = 0;
	baseBonus_Damage_ToBoss = 0;
	base_FireRate = 0;
	base_MAXHEALTH = 0;
	base_Health = 0;
	base_MoveSpeed = 0;
	baseRegenRate_OutofCombat = 0;
	baseRegenRate_InCombat = 0;
	baseSprintSpeed = 0;

	// ...
}


void UPlayer_Statcard::SetupPerLevelStats(float _Player_Level, float _health_Per_Level, float _damage_Per_Level)
{
	Player_Level = _Player_Level;
	health_Per_Level = _health_Per_Level;
	damage_Per_Level = _damage_Per_Level;
}

void UPlayer_Statcard::SetupBaseStats(float _base_Armour, float _base_Sprint_Armour, float _base_Bleed_Chance, float _base_Damage, float _base_Crit_Chance, float _baseBonus_Damage_ToBoss, float _base_FireRate, float _base_MAXHEALTH, float _base_MoveSpeed, float _baseRegenRate_OutofCombat, float _baseRegenRate_InCombat, float _baseSprintSpeed)
{
	base_Armour = _base_Armour;
	base_Sprint_Armour = _base_Sprint_Armour;
	base_Bleed_Chance = _base_Bleed_Chance;
	base_Damage = _base_Damage;
	base_Crit_Chance = _base_Crit_Chance;
	baseBonus_Damage_ToBoss = _baseBonus_Damage_ToBoss;
	base_FireRate = _base_FireRate;
	base_MAXHEALTH = _base_MAXHEALTH;
	base_Health = _base_MAXHEALTH;
	base_MoveSpeed = _base_MoveSpeed;
	baseRegenRate_OutofCombat = _baseRegenRate_OutofCombat;
	baseRegenRate_InCombat = _baseRegenRate_InCombat;
	baseSprintSpeed = _baseSprintSpeed;
}

// Called when the game starts
void UPlayer_Statcard::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayer_Statcard::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

