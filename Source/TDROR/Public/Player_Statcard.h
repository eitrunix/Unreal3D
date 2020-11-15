// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player_Statcard.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TDROR_API UPlayer_Statcard : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayer_Statcard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Level")
		float Player_Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Level")
		float health_Per_Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Level")
		float damage_Per_Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_Armour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_Sprint_Armour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_Bleed_Chance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_Crit_Chance;		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float baseBonus_Damage_ToBoss;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_FireRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_Health;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_MAXHEALTH;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float base_MoveSpeed;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float baseRegenRate_OutofCombat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float baseRegenRate_InCombat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats | Base")
		float baseSprintSpeed;


	UFUNCTION(BlueprintCallable, Category = "Stats | Functions")
		void SetupPerLevelStats(float _Player_Level, float _health_Per_Level, float _damage_Per_Level);

	UFUNCTION(BlueprintCallable, Category = "Stats | Functions")
		void SetupBaseStats(float _base_Armour, float _base_Sprint_Armour, float _base_Bleed_Chance, float _base_Damage, float _base_Crit_Chance, float _baseBonus_Damage_ToBoss, float _base_FireRate, float _base_MAXHEALTH, float _base_MoveSpeed, float _baseRegenRate_OutofCombat, float _baseRegenRate_InCombat, float _baseSprintSpeed);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
