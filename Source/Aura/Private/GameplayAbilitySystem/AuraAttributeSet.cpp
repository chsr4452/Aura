// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilitySystem/AuraAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	
}

void UAuraAttributeSet::OnRep_Health(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldAttr)
}

void UAuraAttributeSet::OnRep_Mana(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldAttr)
}

void UAuraAttributeSet::OnRep_MaxHealth(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldAttr)
}

void UAuraAttributeSet::OnRep_MaxMana(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldAttr)
}

void UAuraAttributeSet::OnRep_Strength(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Strength, OldAttr)
}

void UAuraAttributeSet::OnRep_Intelligence(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Intelligence, OldAttr)
}

void UAuraAttributeSet::OnRep_Vigor(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Vigor, OldAttr)
}

void UAuraAttributeSet::OnRep_Resilience(FGameplayAttributeData& OldAttr)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Resilience, OldAttr)
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAuraAttributeSet, Health);
	DOREPLIFETIME(UAuraAttributeSet, Mana);
	DOREPLIFETIME(UAuraAttributeSet, MaxHealth);
	DOREPLIFETIME(UAuraAttributeSet, MaxMana);
	DOREPLIFETIME(UAuraAttributeSet, Strength);
	DOREPLIFETIME(UAuraAttributeSet, Intelligence);
	DOREPLIFETIME(UAuraAttributeSet, Vigor);
	DOREPLIFETIME(UAuraAttributeSet, Resilience);
}

void UAuraAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}
