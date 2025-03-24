// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayTagContainer.h"

UAuraAbilitySystemComponent::UAuraAbilitySystemComponent()
{
	
}

void UAuraAbilitySystemComponent::BindDelegates()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* InAbilitySystemComponent, const FGameplayEffectSpec& InGameplayEffectSpec, FActiveGameplayEffectHandle InActiveGameplayEffectHandle) const
{
	FGameplayTagContainer AssetTagContainer = InGameplayEffectSpec.Def->GetAssetTags();


	OnEffectAppliedDelegate.Broadcast(AssetTagContainer);
}
