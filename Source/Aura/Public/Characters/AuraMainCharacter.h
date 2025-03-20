// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterbase.h"
#include "AuraMainCharacter.generated.h"

class AAuraPlayerState;
class UAuraAnimInstanceBase;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraMainCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraMainCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimInstance")
	TObjectPtr<UCharacterMovementComponent> CharacterMovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimInstance")
	TObjectPtr<UAuraAnimInstanceBase> AuraAnimInstance;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Aura PlayerState")
	TObjectPtr<AAuraPlayerState> AuraPlayerState;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
};

