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
	AuraASC->GetGameplayAttributeValueChangeDelegate(AuraAS->GetHealthAttribute()).AddUObject(this, &UAuraOverlayWidgetController::OnHealthChangeCallback);
	AuraASC->GetGameplayAttributeValueChangeDelegate(AuraAS->GetMaxHealthAttribute()).AddUObject(this, &UAuraOverlayWidgetController::OnMaxHealthChangeCallback);
}

void UAuraOverlayWidgetController::OnHealthChangeCallback(const FOnAttributeChangeData& Data)
{
	OnHealthChange.Broadcast(Data.NewValue);
}

void UAuraOverlayWidgetController::OnMaxHealthChangeCallback(const FOnAttributeChangeData& Data)
{
	OnMaxHealthChange.Broadcast(Data.NewValue);
}