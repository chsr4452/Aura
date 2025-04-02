// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraPlayerController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/AuraEnemyCharacterBase.h"
#include "Data/AuraInputConfig.h"
#include "GameFramework/Character.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"

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

void AAuraPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CursorTrace();
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
		
		for (FAuraInputTag& i : InputConfigPtr->InputConfigs)
		{
			if (i.InputAction && i.GameplayTag.IsValid())
			{
				EnhancedInputComponent->BindAction(i.InputAction, ETriggerEvent::Started, this, &AAuraPlayerController::AbilityInputTagPressed, i.GameplayTag);
	            EnhancedInputComponent->BindAction(i.InputAction, ETriggerEvent::Completed, this, &AAuraPlayerController::AbilityInputTagReleased, i.GameplayTag);
	            EnhancedInputComponent->BindAction(i.InputAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::AbilityInputTagHeld, i.GameplayTag);
			}

		}
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

UAuraAbilitySystemComponent* AAuraPlayerController::GetASC()
{
	if (AuraAbilitySystemComponent == nullptr)
	{
		AuraAbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return AuraAbilitySystemComponent;
}

void AAuraPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	
	if (Cast<ACharacter>(CursorHit.GetActor()))
	{
					if (GetASC()) GetASC()->AbilityInputTagPressed(InputTag);
                	// GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::Printf(TEXT("Press: %s"), *InputTag.ToString()));
	}
}

void AAuraPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!AuraAbilitySystemComponent)
	{
		AuraAbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));
	}
	// GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::Printf(TEXT("Release: %s"), *InputTag.ToString()));
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!Cast<ACharacter>(CursorHit.GetActor()))
	{
		CachedDestination = CursorHit.ImpactPoint;
	}
}

void AAuraPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	// GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, FString::Printf(TEXT("Held: %s"), *InputTag.ToString()));
}

void AAuraPlayerController::CursorTrace()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	FormerActor = CurrentActor;
	CurrentActor = CursorHit.GetActor();
	if (FormerActor == nullptr)
	{
		if (CurrentActor != nullptr)
		{
			// Case B
			CurrentActor->Highlight();
		}
		else
		{
			// Case A - both are null, do nothing
		}
	}
	else // FormerActor is valid
	{
		if (CurrentActor == nullptr)
		{
			// Case C
			FormerActor->UnHighlight();
		}
		else // both actors are valid
		{
			if (FormerActor != CurrentActor)
			{
				// Case D
				FormerActor->UnHighlight();
				CurrentActor->Highlight();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
}
