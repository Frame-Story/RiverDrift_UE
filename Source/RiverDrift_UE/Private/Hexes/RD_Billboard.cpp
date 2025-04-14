// Fill out your copyright notice in the Description page of Project Settings.


#include "Hexes/RD_Billboard.h"
#include "Logging/StructuredLog.h"
#include "Kismet/KismetMathLibrary.h"

URD_Billboard::URD_Billboard()
{
	//PrimaryComponentTick.RegisterTickFunction(GetComponentLevel());
	PrimaryComponentTick.bCanEverTick = true;
	SetComponentTickEnabled(true);
}

void URD_Billboard::BeginPlay()
{
	Super::BeginPlay();


	//RegisterComponent();
	PrimaryComponentTick.Target = this;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.SetTickFunctionEnable(true);
	//PrimaryComponentTick.RegisterTickFunction(GetWorld()->GetLevel());

	CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	lookRotation =  CameraManager->GetCameraRotation();

}


void URD_Billboard::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	lookRotation = CameraManager->GetCameraRotation();

	//setabsoluterota

	//lookRotation.
	FRotator lookAtRot = UKismetMathLibrary::FindLookAtRotation( this->GetOwner()->GetActorLocation(), CameraManager->GetCameraLocation());

	lookRotation = UKismetMathLibrary::FindLookAtRotation( this->GetOwner()->GetActorLocation(), CameraManager->GetCameraLocation());
	//lookRotation = lookRotation + FRotator(0, -90, 0);



	lookRotation = FRotator(0, lookAtRot.Yaw - GetOwner()->GetActorRotation().Yaw, 0);
	lookRotation += applyRot;

	UE_LOGFMT(LogTemp, Log, "look at {0}, look rotation {1}", *lookAtRot.ToCompactString(), *lookRotation.ToCompactString());
	//SetWorldRotation(lookRotation);
	SetRelativeRotation(lookRotation);

}
