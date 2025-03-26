// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AuraAssetManager.h"
#include "Data/AuraNativeGameplayTags.h"


const UAuraAssetManager& UAuraAssetManager::GetAuraAssetManager()
{
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraNativeTags::InitNativeGameplayTags();
}
