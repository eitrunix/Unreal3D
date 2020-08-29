// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPickup.generated.h"

UENUM()
enum itemRatiry
{
	Common UMETA(DisplayName = "Common"),
	Uncommon UMETA(DisplayName = "Uncommon"),
	Rare UMETA(DisplayName = "Rare"),
	Mythic UMETA(DisplayName = "Mythic"),
};

UENUM()
enum statToInrease
{
	Health UMETA(DisplayName = "Health"),
	Damage UMETA(DisplayName = "Damage"),
	FireRate UMETA(Displayname = "FireRate"),

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
		TEnumAsByte<statToInrease> stat;
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
