// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../../../../Program Files/Epic Games/UE_5.3/Engine/Plugins/Editor/GameplayTagsEditor/Source/GameplayTagsEditor/Private/GameplayTagEditorUtilities.h"

/**
 * 
 */

struct FAuraNativeTags
{
public:
	const FAuraNativeTags& GetNativeTags() const{return GameplayTags;}
    static void InitNativeGameplayTags();
	
	static FAuraNativeTags GameplayTags;

	// Gameplay Tags
	// Vital Attributes

	FGameplayTag Attribute_Vital_Health;
	FGameplayTag Attribute_Vital_Mana;
	FGameplayTag Attribute_Vital_MaxHealth;
	FGameplayTag Attribute_Vital_MaxMana;

	// Primary Attributes

	FGameplayTag Attribute_Primary_Strength;
	FGameplayTag Attribute_Primary_Intelligence;
	FGameplayTag Attribute_Primary_Vigor;
	FGameplayTag Attribute_Primary_Resilience;

	// Message Tags
	FGameplayTag Message_HealthPotion;
	FGameplayTag Message_ManaPotion;
	FGameplayTag Message_HealthCrystal;
	FGameplayTag Message_ManaCrystal;
};
