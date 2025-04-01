// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UTargetInterface;
class ITargetInterface;
class UAuraAbilitySystemComponent;
class UAuraInputConfig;
struct FGameplayTag;
struct FAuraInputTag;
struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	AAuraPlayerController();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

protected:

	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> IMC_Main;
	
	void MoveInput(const FInputActionValue& InputValue);
	UAuraAbilitySystemComponent* GetASC();

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly,Category="InputConfig")
	TArray<FAuraInputTag> InputConfigs;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UAuraInputConfig> InputConfigPtr;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

private:
	bool bCharacter = false;
	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;
	
	void CursorTrace();
	FHitResult CursorHit;

	TScriptInterface<ITargetInterface> CurrentActor;
	TScriptInterface<ITargetInterface> FormerActor;
};

