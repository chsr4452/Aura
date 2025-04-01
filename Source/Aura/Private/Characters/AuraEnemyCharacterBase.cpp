// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraEnemyCharacterBase.h"

#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

AAuraEnemyCharacterBase::AAuraEnemyCharacterBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("Ability System Component");
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("Attribute Set");
}

void AAuraEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
}

void AAuraEnemyCharacterBase::Highlight()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, "Highlight");
}

void AAuraEnemyCharacterBase::UnHighlight()
{
}
