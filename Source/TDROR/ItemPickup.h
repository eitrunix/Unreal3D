// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPickup.generated.h"

UENUM()
enum itemRatiry
{
	Common		UMETA(DisplayName = "Common"),
	Uncommon	UMETA(DisplayName = "Uncommon"),
	Rare		UMETA(DisplayName = "Rare"),
	Mythic		UMETA(DisplayName = "Mythic"),
};

UENUM(BlueprintType)
enum statToIncrease
{
	Health					UMETA(DisplayName = "Health"),
	MaxHealth				UMETA(DisplayName = "MaxHealth"),
	Damage					UMETA(DisplayName = "Damage"),
	Bleed					UMETA(Displayname = "Bleed"),
	DamageToBoss			UMETA(Displayname = "DamageToBoss"),
	Crit					UMETA(Displayname = "Crit"),
	FireRate				UMETA(Displayname = "FireRate"),
	MoveSpeed				UMETA(Displayname = "MoveSpeed"),
	OnHIt					UMETA(Displayname = "OnHIt"),
	OnKill					UMETA(Displayname = "OnKill"),
	OvertimeHeal			UMETA(Displayname = "OvertimeHeal"),
	OvertimeHealNoCombat 	UMETA(Displayname = "OvertimeHealNoCombat"),
	Armour					UMETA(Displayname = "Armour"),
	ArmourSprinting			UMETA(Displayname = "ArmourSprinting"),
	SprintSpeed				UMETA(Displayname = "SprintSpeed")
};

USTRUCT(BlueprintType)
struct FStatData
{
	GENERATED_BODY()

	statToIncrease Type;
	float BaseValue;
	int Count;

	void IncrementStat()
	{
		Count++;
	}

	float GetStatTotal()
	{
		return float(Count) * BaseValue;
	}
};

UCLASS()
class TDROR_API AItemPickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
		TEnumAsByte<itemRatiry> rarity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
		TEnumAsByte<statToIncrease> stat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat Changes")
		float changeInStat;
	UFUNCTION(BlueprintCallable, Category = "Item Loot")
		float IncreaseStat(float _StatToIncrease, float _IncreaseBy);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

