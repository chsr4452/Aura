// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayAbility/AuraGameplayAbility.h"

UAuraAbilitySystemComponent::UAuraAbilitySystemComponent()
{
	
}

void UAuraAbilitySystemComponent::BindDelegates()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::AddAbility(const TSubclassOf<UGameplayAbility> Ability)
{
	FGameplayAbilitySpec GameplayAbilitySpec = FGameplayAbilitySpec(Ability);
	GameplayAbilitySpec.DynamicAbilityTags.AddTag(Cast<UAuraGameplayAbility>(GameplayAbilitySpec.Ability)->InputTag);
	
	GiveAbility(GameplayAbilitySpec);
	auto StartActivatableAbilities = GetActivatableAbilities();
	bStartupAbilitiesGiven = true;
}

void UAuraAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag InTag)
{
	
	if (!InTag.IsValid()){return;}
	auto StartActivatableAbilities = GetActivatableAbilities();
	for (FGameplayAbilitySpec& GameplayAbilitySpec :StartActivatableAbilities)
	{
		if (GameplayAbilitySpec.DynamicAbilityTags.HasTagExact(InTag))
		{
			if (!GameplayAbilitySpec.IsActive())
			{
				TryActivateAbility(GameplayAbilitySpec.Handle);
				// GEngine->AddOnScreenDebugMessage(2, 2, FColor::Red, FString::Printf(TEXT("Press: %s"), *InTag.ToString()));
			}
			
		}
	}
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* InAbilitySystemComponent, const FGameplayEffectSpec& InGameplayEffectSpec, FActiveGameplayEffectHandle InActiveGameplayEffectHandle) const
{
	FGameplayTagContainer AssetTagContainer = InGameplayEffectSpec.Def->GetAssetTags();
	OnEffectAppliedDelegate.Broadcast(AssetTagContainer);
}
