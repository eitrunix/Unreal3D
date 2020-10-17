// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Monster_StatCard.generated.h"

UENUM()
enum MonsterTier
{
	Tier1		UMETA(DisplayName = "Tier1"),
	Tier2	    UMETA(DisplayName = "Tier2"),
	Tier3		UMETA(DisplayName = "Tier3"),
	Boss		UMETA(DisplayName = "Boss"),
};
UENUM()
enum MonsterStat
{
	RewardEXP		UMETA(DisplayName = "RewardEXP"),
	RewardCurrency	UMETA(DisplayName = "RewardCurrency"),
	AttackSpeed	    UMETA(DisplayName = "AttackSpeed"),
	MoveSpeed		UMETA(DisplayName = "MoveSpeed"),
	Damage			UMETA(DisplayName = "Damage"),
	MAX_Health		UMETA(DisplayName = "MAX_Health"),
	Health			UMETA(DisplayName = "Health"),

};

USTRUCT(BlueprintType)
struct FMonsterStatData
{
	GENERATED_BODY()

		MonsterStat Stat;
		float BaseValue;
		float CurrentValue;
		int CurrentLevel;

		float IncreaseStatByLevel()
		{
			CurrentValue = CurrentLevel * BaseValue;

			return CurrentValue;
		}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TDROR_API UMonster_StatCard : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMonster_StatCard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster Stats | Cost to Spawn")
		int baseSpawnCost;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster Stats | Cost to Spawn")
		int currentSpawnCost;

	UFUNCTION(BlueprintCallable, Category = "Monster Stats | Cost to Spawn")
		int GetBaseCost();
	UFUNCTION(BlueprintCallable, Category = "Monster Stats | Cost to Spawn")
		void SetCost(int _newCost);	
	UFUNCTION(BlueprintCallable, Category = "Monster Stats | Cost to Spawn")
		int IncreaseCost(float _coeff);	
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
