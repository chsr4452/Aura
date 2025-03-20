// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI Input;
	Input.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	Input.SetHideCursorDuringCapture(false);
	SetInputMode(Input);

	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (IMC_Main)
	{
		UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(IMC_Main, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AAuraPlayerController::MoveInput);
	}
}

void AAuraPlayerController::MoveInput(const FInputActionValue& InputValue)
{
	const FVector2D MoveVector = InputValue.Get<FVector2D>();

	if (APawn* PawnOwner = GetPawn())
	{
		PawnOwner->AddMovementInput(FVector(MoveVector.X,0.f, 0.f));
		PawnOwner->AddMovementInput(FVector(0.f,MoveVector.Y, 0.f));
	}
	
}
