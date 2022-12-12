// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetObject.h"

// Sets default values
ATargetObject::ATargetObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void ATargetObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATargetObject::OnTargetTeleport(FVector targetTransform)
{
	SetActorLocation(targetTransform,false,0,ETeleportType::None);
	mesh->SetSimulatePhysics(false);

	GetWorld()->GetTimerManager().SetTimer(physicsTimerDelayHandle, this, &ATargetObject::ResetPhysics, 0.1f,false);
}

void ATargetObject::ResetPhysics()
{
	mesh->SetSimulatePhysics(true);
}

// Called every frame
void ATargetObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

