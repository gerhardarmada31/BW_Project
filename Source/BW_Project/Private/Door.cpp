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

	
	if(isKeyIn)
	{
		// if (timeElapsed < lerpDuration)
		// {
		// 	//SetActorLocation(endPoint->GetRelativeLocation(),false,0,ETeleportType::None);
		// 	//mesh->SetRelativeLocation(endPoint->GetRelativeLocation(),false,0,ETeleportType::None);
		// 	
		// 	mesh->SetRelativeLocation(FMath::Lerp(startLocation,targetlocation,timeElapsed/lerpDuration));
		// 	//parent->SetActorLocation(FMath::Lerp(startLocation,endLocation,timeElapsed/lerpDuration));
		// 	//mesh->SetRelativeTransform(FMath::Lerp(startLocation,endLocation,timeElapsed/lerpDuration),false,0,ETeleportType::None);
		// 	timeElapsed+=DeltaTime;
		// }
	}
	else
	{
		// print("fr not entered");
	 //    if(timeElapsed < lerpDuration)
	 //    {
	 //    	mesh->SetRelativeLocation(FMath::Lerp(startLocation,(targetlocation*(-1.0f)),timeElapsed/lerpDuration));
	 //    	timeElapsed+=DeltaTime;
	 //    }
	}
	
}


