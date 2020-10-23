// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPointComponent.h"
#include <StaticMeshResources.h>

// Sets default values for this component's properties
USpawnPointComponent::USpawnPointComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
AActor* USpawnPointComponent::EnemyFromArray()
{

	int Rand;
	Rand = FMath::RandRange(0, (enemyListArray.Num()) - 1);
	if(enemyListArray.IsValidIndex(Rand))
	{
		return enemyListArray[Rand];
	}

	return 0;
}

AActor* USpawnPointComponent::SpawnEnemy(FVector Loc, FRotator Rot)
{
	//FActorSpawnParameters SpawnParams;
	//TSubclassOf<AActor> EnemyToSpawn;
	//EnemyToSpawn = enemyToBeSpawned[0];
	//RemoveFromEnemyToSpawnList();
	//AActor* spawnedItemRef = GetWorld()->SpawnActor<AActor>(EnemyToSpawn, Loc, Rot, SpawnParams);
	//return spawnedItemRef;
	return 0;
}

AActor* USpawnPointComponent::AddEnemyToList()
{
	FActorSpawnParameters SpawnParams;
	AActor* EnemyToSpawn;
	EnemyToSpawn = enemyToBeSpawned[0];
	return EnemyToSpawn;
}

void USpawnPointComponent::AddEnemyToSpawnList(AActor* enemyToAdd)
{
	enemyToBeSpawned.Add(enemyToAdd);
}

void USpawnPointComponent::RemoveFromEnemyToSpawnList()
{
	if (enemyToBeSpawned.Contains(pickedEnemy))
	{
		enemyToBeSpawned.Remove(pickedEnemy);
	}
}

AActor* USpawnPointComponent::GetFromEnemyToSpawnList()
{
	if (enemyListArray.Contains(pickedEnemy))
	{
		return enemyToBeSpawned[0];
	}

	return 0;
}

void USpawnPointComponent::PickEnemy()
{
	pickedEnemy = EnemyFromArray();
	AddEnemyToSpawnList(pickedEnemy);
}

// Called when the game starts
void USpawnPointComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnPointComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

