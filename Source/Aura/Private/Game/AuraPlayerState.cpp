// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AuraPlayerState.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("Ability System Component");
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("Attribute Set");
}
