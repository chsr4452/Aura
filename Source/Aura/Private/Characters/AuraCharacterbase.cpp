// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraCharacterbase.h"

#include "AttributeSet.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(GetMesh(),TEXT("WeaponSocket"));
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
