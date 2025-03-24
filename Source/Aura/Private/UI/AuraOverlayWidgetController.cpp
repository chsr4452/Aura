// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraOverlayWidgetController.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

void UAuraOverlayWidgetController::BroadCastInitAttribute()
{
	OnHealthChange.Broadcast(AuraAS->GetHealth());
	OnMaxHealthChange.Broadcast(AuraAS->GetMaxHealth());
}

void UAuraOverlayWidgetController::BindCallbacksToDependencies()
{
	AuraASC->GetGameplayAttributeValueChangeDelegate(AuraAS->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnHealthChange.Broadcast(Data.NewValue);
	});
	AuraASC->GetGameplayAttributeValueChangeDelegate(AuraAS->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnMaxHealthChange.Broadcast(Data.NewValue);
	});
	AuraASC->GetGameplayAttributeValueChangeDelegate(AuraAS->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnManaChange.Broadcast(Data.NewValue);
	});
	AuraASC->GetGameplayAttributeValueChangeDelegate(AuraAS->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnMaxManaChange.Broadcast(Data.NewValue);
	});
}


