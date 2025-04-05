// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RD_PlayerPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

// Sets default values
ARD_PlayerPawn::ARD_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom...
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	PlayerModel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	
	//CameraBoom->AttachToComponent(rootcom);
	//CameraBoom->SetupAttachment(RootComponent);

	PlayerModel->SetupAttachment(RootComponent);
	SpringArmComp->SetupAttachment(PlayerModel);
	TopDownCameraComponent->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	//SpringArmComp->SetRelativeRotation(FRotator(0.0f, 0.f, 0.f));


	//SpringArmComp->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	//SpringArmComp->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

				//Assign SpringArm class variables.
	SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 65.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 400.f;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 3.0f;


	//SpringArmComp->TargetArmLength = 800.f;
	// Create a camera...
	//TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void ARD_PlayerPawn::BeginPlay()
{
	FTransform StartTransform = this->GetTransform();
	//FRotator CameraStartRotation = this->

	//this->RootComponent->SetWorldTransform(ZeroTransform);
	//TopDownCameraComponent->SetWorldTransform(StartTransform);



	Super::BeginPlay();
	
}

// Called every frame
void ARD_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARD_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

