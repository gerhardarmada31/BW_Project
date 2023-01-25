// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green,FString::Printf(TEXT(text),fstring))

#include "Door.h"


ADoor::ADoor()
{
	rootPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Endpoint"));
	RootComponent = rootPoint;
	
	//parent = GetOwner();
	//put this in begin play
}

//It will move based on the position of the endpoint
void ADoor::DoorOpening()
{
	//if()
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	//startLocation=GetOwner()->GetActorLocation();
	//printf("The Owner is %s", *parent->GetName());
}


void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


