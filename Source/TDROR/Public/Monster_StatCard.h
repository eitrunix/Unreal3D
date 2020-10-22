// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Monster_StatCard.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TDROR_API UMonster_StatCard : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMonster_StatCard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Per Level")
		float healthPerLevel;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Per Level")
		float damagePerLevel;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float baseHealth;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float baseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Spawn Cost")
		int baseSpawnCost;

	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		int getSpawnCost();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
