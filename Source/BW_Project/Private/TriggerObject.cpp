// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerObject.h"

// Sets default values
ATriggerObject::ATriggerObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ATriggerObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATriggerObject::OnObjectTrigger()
{
	ITeleportInterface::OnObjectTrigger();
}


// Called every frame
void ATriggerObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

