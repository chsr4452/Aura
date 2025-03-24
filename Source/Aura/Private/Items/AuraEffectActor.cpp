// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{

}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectClass)
{
	UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (AbilitySystemComponent)
	{
		FGameplayEffectContextHandle GameplayEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
		GameplayEffectContextHandle.AddSourceObject(this);
		FGameplayEffectSpecHandle GameplayEffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(EffectClass, 1, GameplayEffectContextHandle);
		FActiveGameplayEffectHandle ActiveGameplayEffectHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GameplayEffectSpecHandle.Data.Get());

		if (GameplayEffectSpecHandle.Data.Get()->Def->DurationPolicy == EGameplayEffectDurationType::Infinite)
		{
			bInfinite = true;
			ActiveGameplayEffectMap.Add(ActiveGameplayEffectHandle, AbilitySystemComponent);
		}
	}
}

void AAuraEffectActor::ApplyEffectOnBeginOverlap(AActor* TargetActor)
{
	if (IsValid(InstantEffectClass) && (InstantEffectOverlapPolicy == EOnOverlapPolicy::ApplyEffectOnBeginOverlap))
	{
		ApplyEffectToTarget(TargetActor, InstantEffectClass);
	}

	if (IsValid(DurationEffectClass) && (DurationEffectOverlapPolicy == EOnOverlapPolicy::ApplyEffectOnBeginOverlap))
	{
		ApplyEffectToTarget(TargetActor, DurationEffectClass);
	}

	if (IsValid(InfiniteEffectClass) && (InfiniteEffectOverlapPolicy == EOnOverlapPolicy::ApplyEffectOnBeginOverlap))
	{
		ApplyEffectToTarget(TargetActor, InfiniteEffectClass);
	}
}

void AAuraEffectActor::ApplyEffectOnEndOverlap(AActor* TargetActor)
{
	if (bInfinite)
	{
		TArray<FActiveGameplayEffectHandle> ActiveGameplayEffectToRemove;
		for (auto ActiveGameplayEffect : ActiveGameplayEffectMap)
		{
			ActiveGameplayEffect.Value->RemoveActiveGameplayEffect(ActiveGameplayEffect.Key);
			ActiveGameplayEffectToRemove.Add(ActiveGameplayEffect.Key);
		}
		
		for (auto ActiveGameplayEffect : ActiveGameplayEffectToRemove)
        {
        	ActiveGameplayEffectMap.Remove(ActiveGameplayEffect);
        }
	}
}
