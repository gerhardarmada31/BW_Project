// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"


APlatformTrigger::APlatformTrigger()
{
		platformCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
		platformCollisionBox->SetBoxExtent(FVector(200,200,200));
		RootComponent=mesh;
		platformCollisionBox->SetRelativeLocation(FVector(200,200,0));
		platformCollisionBox->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

	platformCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	platformCollisionBox->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);
	
	
}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void APlatformTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check if the other actor
	if(OtherActor != this)
	{
		print("Player has entered");
		printFString("Overlapped Actor = %s", *OtherActor->GetName());
	}

}


