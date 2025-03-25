// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraMainCharacter.h"

#include "Animations/AuraAnimInstanceBase.h"
#include "Camera/CameraComponent.h"
#include "Game/AuraPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"
#include "UI/AuraHUD.h"

AAuraMainCharacter::AAuraMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	CameraComponent->SetupAttachment(SpringArmComponent);
	SpringArmComponent->SetupAttachment(GetRootComponent());

	SpringArmComponent->SetRelativeRotation(FRotator(-60, 0, 0));
	SpringArmComponent->TargetArmLength = 800;

	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = false;
	
	GetCharacterMovement()->MaxWalkSpeed = 400;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AAuraMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	checkf(AuraAnimInstance = Cast<UAuraAnimInstanceBase>(GetMesh()->GetAnimInstance()), TEXT("Getting AuraAnimInstance failed."));
	checkf(CharacterMovementComponent = GetCharacterMovement(), TEXT("GetCharacterMovement failed."));

	if (AttributeSet)
	{
			Cast<UAuraAttributeSet>(AttributeSet)->SetHealth(50.f);
        	Cast<UAuraAttributeSet>(AttributeSet)->SetMaxHealth(100.f);
        	Cast<UAuraAttributeSet>(AttributeSet)->SetMana(25.f);
        	Cast<UAuraAttributeSet>(AttributeSet)->SetMaxMana(50.f);
	}

}

void AAuraMainCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AuraAnimInstance->GroundSpeed =  CharacterMovementComponent->GetCurrentAcceleration().Size();
	FString GroundSpeedStr = FString::Printf(TEXT("GroundSpeed: %f"), AuraAnimInstance->GroundSpeed);
	// GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, GroundSpeedStr);
}

void AAuraMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AuraPlayerState = GetPlayerState<AAuraPlayerState>())
	{
			AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
        	AttributeSet = AuraPlayerState->GetAttributeSet();
        
        	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
		
			Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->BindDelegates();
	}
	APlayerController* MainPlayerController = GetPlayerState()->GetPlayerController();
	if (MainPlayerController)
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(MainPlayerController->GetHUD()))
		{
			AuraHUD->InitAuraHUD(MainPlayerController, AttributeSet, AbilitySystemComponent, GetPlayerState());
		}
		InitPrimaryAttribute();
	}
}

void AAuraMainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (AuraPlayerState = GetPlayerState<AAuraPlayerState>())
	{
		AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
		AttributeSet = AuraPlayerState->GetAttributeSet();
        
		AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
		
		Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->BindDelegates();
	}
	APlayerController* MainPlayerController = GetPlayerState()->GetPlayerController();
	if (MainPlayerController)
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(MainPlayerController->GetHUD()))
		{
			AuraHUD->InitAuraHUD(MainPlayerController, AttributeSet, AbilitySystemComponent, GetPlayerState());
		}
		InitPrimaryAttribute();
	}
}

void AAuraMainCharacter::InitPrimaryAttribute()
{
	Super::InitPrimaryAttribute();
}
