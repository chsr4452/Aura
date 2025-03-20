// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilitySystem/AuraAttributeSet.h"

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

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAuraAttributeSet, Health);
	DOREPLIFETIME(UAuraAttributeSet, Mana);
	DOREPLIFETIME(UAuraAttributeSet, MaxHealth);
	DOREPLIFETIME(UAuraAttributeSet, MaxMana);
}
