// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::GetInputAction(FGameplayTag InGameplayTag) const
{
	for (const FAuraInputTag& i : InputConfigs)
	{
		if (i.GameplayTag.MatchesTag(InGameplayTag))
		{
			return i.InputAction;
		}
	}
	return nullptr;
}
