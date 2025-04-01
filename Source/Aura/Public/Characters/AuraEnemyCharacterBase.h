// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "Interface/TargetInterface.h"
#include "AuraEnemyCharacterBase.generated.h"

/**
 * 
 */     
UCLASS()
class AURA_API AAuraEnemyCharacterBase : public AAuraCharacterBase, public ITargetInterface
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacterBase();
	virtual void BeginPlay() override;

protected:
	virtual void Highlight() override;
	virtual void UnHighlight() override;
};
