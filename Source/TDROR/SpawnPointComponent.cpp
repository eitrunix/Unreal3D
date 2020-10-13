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

TSubclassOf<AActor> USpawnPointComponent::EnemyFromArray()
{

	int Rand;
	Rand = FMath::RandRange(0, (enemyListArray.Num()) - 1);
	if(enemyListArray.IsValidIndex(Rand))
	{
		return enemyListArray[Rand];
	}

	//for (int i = 0; i < enemyListArray.Num(); i++)
	//{
	//	if (i == Rand)
	//	{
	//		return enemyListArray[i];
	//	}
	//}
	return 0;
}

AActor* USpawnPointComponent::SpawnEnemy(FVector Loc, FRotator Rot)
{
	TSubclassOf<AActor> tmpEnemy;
	tmpEnemy = EnemyFromArray();
	FActorSpawnParameters SpawnParams;
	AActor* spawnedItemRef = GetWorld()->SpawnActor<AActor>(tmpEnemy, Loc, Rot, SpawnParams);
	return spawnedItemRef;
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

