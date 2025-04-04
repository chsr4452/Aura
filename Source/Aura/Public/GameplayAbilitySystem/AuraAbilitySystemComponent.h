// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEffectAppliedDelegate, const FGameplayTagContainer&)
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UAuraAbilitySystemComponent();

	FOnEffectAppliedDelegate OnEffectAppliedDelegate;

	void BindDelegates();
	
	void AddAbility(const TSubclassOf<UGameplayAbility> Ability);
	
	UFUNCTION(BlueprintCallable)
	void AbilityInputTagPressed(const FGameplayTag InTag);

	bool bStartupAbilitiesGiven = false;
	
protected:
	void EffectApplied(UAbilitySystemComponent* InAbilitySystemComponent, const FGameplayEffectSpec& InGameplayEffectSpec, FActiveGameplayEffectHandle InActiveGameplayEffectHandle) const;
	
};
