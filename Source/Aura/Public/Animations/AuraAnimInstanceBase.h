// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AuraAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	UAuraAnimInstanceBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation Params")
	float GroundSpeed;
};
