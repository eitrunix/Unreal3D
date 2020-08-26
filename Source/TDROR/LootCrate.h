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
		int givenCurrency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player In Range")
		bool inOpenRange;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curency")
		bool opened;

	UFUNCTION(BlueprintCallable, Category = "Currency")
		int GiveCurrency(int _givenCurrency);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
