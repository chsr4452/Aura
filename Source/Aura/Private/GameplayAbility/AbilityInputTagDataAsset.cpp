// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/AbilityInputTagDataAsset.h"

TSubclassOf<UGameplayAbility> UAbilityInputTagDataAsset::MatchInputTagWithAbility(FName& InInputTag)
{
	for (auto i : InputActionAbility)
	{
		if (i.InputTag.GetTagName() == InInputTag)
		{
			return i.GameplayAbility;
		}
	}
	return nullptr;
}
