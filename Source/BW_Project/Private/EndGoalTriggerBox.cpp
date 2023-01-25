// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGoalTriggerBox.h"

#include "BW_Project/BW_ProjectCharacter.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5, FColor::Green,text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green,FString::Printf(TEXT(text),fstring))

AEndGoalTriggerBox::AEndGoalTriggerBox()
{


 OnActorBeginOverlap.AddDynamic(this, &AEndGoalTriggerBox::OnOverLapBegin);
 OnActorEndOverlap.AddDynamic(this, &AEndGoalTriggerBox::OnOverLapEnd);
}

void AEndGoalTriggerBox::OnOverLapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
playerCharacter = Cast<ABW_ProjectCharacter>(OtherActor);

 if(OtherActor != this && OtherActor)
 {
  print("Player Enter");
  UGameplayStatics::OpenLevel(GetWorld(),nextLevelName);
 }



 
}

void AEndGoalTriggerBox::OnOverLapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
 
}






