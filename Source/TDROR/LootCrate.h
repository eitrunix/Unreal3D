// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LootCrate.generated.h"

UCLASS(Blueprintable)
class TDROR_API ALootCrate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootCrate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Currency")
		int moneyInChest;

	UFUNCTION(BlueprintCallable, Category = "Currency")
		int GiveLoot(int _currencyGained);	
	UFUNCTION(BlueprintCallable, Category = "Currency")
		bool SetOpened();	
	UFUNCTION(BlueprintCallable, Category = "Currency")
		bool SetLootGiven();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootBox")
		bool inOpenRange;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootBox")
		bool opened = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootBox")
		bool givenLoot = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
