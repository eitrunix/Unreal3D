// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LootCrate.generated.h"

UENUM()
enum CrateType
{
	CashBox UMETA(DisplayName = "Cash Box"),
	Small UMETA(DisplayName = "Small Crate"),
	Medium UMETA(DisplayName = "Medium Crate"),
	Large UMETA(DisplayName = "Large Crate"),

};

UCLASS(Blueprintable)
class TDROR_API ALootCrate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootCrate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Currency")
		int moneyInChest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Currency")
		int chestCost;

	UFUNCTION(BlueprintCallable, Category = "Currency")
		int GiveMoney();	
	UFUNCTION(BlueprintCallable, Category = "LootBox")
		int Loot();
	UFUNCTION(BlueprintCallable, Category = "Currency")
		bool SetOpened();	
	UFUNCTION(BlueprintCallable, Category = "Currency")
		bool SetLooted();
	UFUNCTION(BlueprintCallable, Category = "LootBox")
		int GiveItemLoot();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootBox")
		bool inOpenRange;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootBox")
		bool opened = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootBox")
		bool givenLoot = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot Box")
		TEnumAsByte<CrateType> type;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};


