// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "OutputActor.h"
#include "TargetObject.h"
#include "BW_Project/BW_ProjectCharacter.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green,FString::Printf(TEXT(text),fstring))



APlatformTrigger::APlatformTrigger()
{
		RootComponent=mesh;
		platformCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
		platformCollisionBox->SetBoxExtent(FVector(200,200,200));
	
		platformCollisionBox->SetRelativeLocation(FVector(200,200,0));

		secondaryMesh->SetupAttachment(RootComponent);
		//secondaryMesh->SetRelativeLocation(FVector(200,200,5));
		//secondaryMesh->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

		platformCollisionBox->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);



	platformCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	platformCollisionBox->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);
	
	
}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (doorActor != NULL)
	{
		//check if the other actor has IteleportableInteract interface
		if(OtherActor != this)
		{
			playerCharacter = Cast<ABW_ProjectCharacter>(OtherActor);
			targetObject = Cast<ATargetObject>(OtherActor);

			//Checks if the player counts as a trigger object
			if(isPlayerTrigger)
			{
				if (playerCharacter || targetObject)
				{
					if(IKeyObjectInteract* keyObject=Cast<IKeyObjectInteract>(doorActor))
					{
						keyObject->OnKeyCollide(false);
						//print("key is FALSE");
					}
				}
			}
			else
			{
				if(targetObject)
				{
					if(IKeyObjectInteract* keyObject=Cast<IKeyObjectInteract>(doorActor))
					{
						keyObject->OnKeyCollide(false);
						//print("key is FALSE");
					}
				}
			}
		}
	}
}



void APlatformTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (doorActor != NULL)
	{
		//check if the other actor has IteleportableInteract interface
		if(OtherActor != this)
		{
			playerCharacter = Cast<ABW_ProjectCharacter>(OtherActor);
			targetObject = Cast<ATargetObject>(OtherActor);
		
			
			
			//Checks if the player counts as a trigger object
			if(isPlayerTrigger)
			{
				if (playerCharacter || targetObject)
				{
					if(IKeyObjectInteract* keyObject=Cast<IKeyObjectInteract>(doorActor))
					{
						keyObject->OnKeyCollide(true);
						//print("key is TRUE");
						//playerCharacter->GetName();
						//printf("PlayerCharacter %s", *playerCharacter->GetName());
					}
				}
			}
			else
			{
				if(targetObject)
				{
					print("key is TRUE");
					if(IKeyObjectInteract* keyObject=Cast<IKeyObjectInteract>(doorActor))
					{
						keyObject->OnKeyCollide(true);
					
					}
				}
			}
		}
	}
	else
	{
		print("output actor is empty");
	}

}





