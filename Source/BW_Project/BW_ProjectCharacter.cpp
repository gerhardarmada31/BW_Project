// Copyright Epic Games, Inc. All Rights Reserved.

#include "BW_ProjectCharacter.h"
#include "BW_ProjectProjectile.h"
#include "DrawDebugHelpers.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "TargetObject.h"
#include "TeleportInterface.h"
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5, FColor::Green,text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green,FString::Printf(TEXT(text),fstring))

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ABW_ProjectCharacter

ABW_ProjectCharacter::ABW_ProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// otherwise won't be visible in the multiplayer
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);




	//bUsingMotionControllers = true;
	
	//Endpoint value of lineTrace
	endpointDistance = 2000.0f;
}

void ABW_ProjectCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// // Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	// if (bUsingMotionControllers)
	// {
	// 	VR_Gun->SetHiddenInGame(false, true);
	// 	Mesh1P->SetHiddenInGame(true, true);
	// }
	// else
	// {
	// 	VR_Gun->SetHiddenInGame(true, true);
	// 	Mesh1P->SetHiddenInGame(false, true);
	// }
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABW_ProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABW_ProjectCharacter::OnFire);

	//Bind restart event
	PlayerInputComponent->BindAction("ResetLevel", IE_Pressed,this,&ABW_ProjectCharacter::OnRestart);


	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &ABW_ProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABW_ProjectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABW_ProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABW_ProjectCharacter::LookUpAtRate);
}

//Player falls and restart
void ABW_ProjectCharacter::FellOutOfWorld(const UDamageType& dmgType)
{
	print("I'm falling");
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()),false);
}

void ABW_ProjectCharacter::OnFire()
{
	print("ooh shots fired");

	FVector start = FirstPersonCameraComponent->GetComponentLocation();
	FVector forwardVector = FirstPersonCameraComponent->GetForwardVector();
	FVector endPoint = start +(forwardVector*endpointDistance);

	FHitResult outHit;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);

	//bool ishit2 = GetWorld()->Sweep
	bool isHit = GetWorld()->LineTraceSingleByChannel(outHit,start,endPoint,ECC_Visibility,params);
	DrawDebugLine(GetWorld(),start,endPoint,FColor::Cyan, false,1,0,1 );
	if (isHit)
	{
		AActor *hitActor = outHit.GetActor();
		if (hitActor->IsA<ATargetObject>())
		{
			print("Hit Target Object");
			targetTransform = hitActor->GetActorLocation();
			myTransform = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

			SetActorLocation(targetTransform);
			if (ITeleportInterface* objectInterface=Cast<ITeleportInterface>(hitActor))
			{
				objectInterface->OnTargetTeleport(myTransform);
			}
		}
	}
}




void ABW_ProjectCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ABW_ProjectCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ABW_ProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABW_ProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABW_ProjectCharacter::OnRestart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()),false);
}



