// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/AuraNativeGameplayTags.h"

#include "GameplayTagsManager.h"

FAuraNativeTags FAuraNativeTags::GameplayTags;

void FAuraNativeTags::InitNativeGameplayTags()
{

	// Primary Attributes
	GameplayTags.Attribute_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Vital.Health"), FString("Hit Point"));
	GameplayTags.Attribute_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Vital.Mana"), FString("Mana Point"));
	GameplayTags.Attribute_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Vital.MaxHealth"), FString("Max Hit Point"));
	GameplayTags.Attribute_Vital_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Vital.MaxMana"), FString("Max Mana Point"));

	// Secondary Attributes
	GameplayTags.Attribute_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Primary.Strength"), FString("Physical Attack Point"));
	GameplayTags.Attribute_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Primary.Intelligence"), FString("Magical Attack Point"));
	GameplayTags.Attribute_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Primary.Vigor"), FString("Physical Defense Point"));
	GameplayTags.Attribute_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Primary.Resilience"), FString("Magical Defense Point"));

	// Message
	GameplayTags.Message_HealthPotion = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.HealthPotion"), FString(""));
	GameplayTags.Message_ManaPotion = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.ManaPotion"), FString(""));
	GameplayTags.Message_HealthCrystal = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.HealthCrystal"), FString(""));
	GameplayTags.Message_ManaCrystal = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.ManaCrystal"), FString(""));


}
