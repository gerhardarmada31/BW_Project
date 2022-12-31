// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "OutputActor.h"


// Sets default values
AOutputActor::AOutputActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
}

// Called when the game starts or when spawned
void AOutputActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOutputActor::OnKeyCollide(bool isKeyEntered)
{
	if (isKeyEntered)
	{
		//Activate the door to kingdom hearts....
		print("KEY ENTERED!!!");
	}
	else
	{
		print("KEY NOT ENTERED");
	}
}

// Called every frame
void AOutputActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

