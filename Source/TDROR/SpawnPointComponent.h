// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Public\Monster_StatCard.h"
#include "SpawnPointComponent.generated.h"

UENUM()
enum SpawnPointType
{
	Door UMETA(DisplayName = "Door Spawn"),
	Window UMETA(DisplayName = "Window Spawn"),
	Above UMETA(DisplayName = "Above Spawn"),
	Below UMETA(DisplayName = "Below Spawn"),
	Warping UMETA(DisplayName = "Warping Spawn"),
	Boss UMETA(DeisplayName = "Boss Spwan"),
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TDROR_API USpawnPointComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnPointComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy List")
		TArray<AActor*> enemyListArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy List")
		TArray<AActor*> enemyToBeSpawned;

	UFUNCTION(BlueprintCallable, Category = "Enenmy List")
		AActor* EnemyFromArray();

	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		AActor* SpawnEnemy(FVector Loc, FRotator Rot);	
	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		AActor* AddEnemyToList();
	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		void AddEnemyToSpawnList(AActor* enemyToAdd);
	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		void RemoveFromEnemyToSpawnList();	
	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		AActor* GetFromEnemyToSpawnList();

	UFUNCTION(BlueprintCallable, Category = "Enemy Spawn")
		void PickEnemy();
	UPROPERTY(BlueprintReadWrite, Category = "Enemy Spawn")
		int tmpSpawnCost;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy List")
		AActor* pickedEnemy;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
