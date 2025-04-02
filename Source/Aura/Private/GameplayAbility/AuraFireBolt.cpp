// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/AuraFireBolt.h"

#include "Actors/AuraProjectileActor.h"
#include "Interface/CombatInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UAuraFireBolt::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                    const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(this, FString("Activate Ability (C++)"));

	const bool bServer = HasAuthority(&ActivationInfo);
	if (!bServer) return;

	CombatInterface = GetAvatarActorFromActorInfo();
	if (!CombatInterface) return;
	const FVector ProjectileSpawnLocation = CombatInterface->GetCombatSocketLocation();
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(ProjectileSpawnLocation);

	AAuraProjectileActor* ProjectileActor = GetWorld()->SpawnActorDeferred<AAuraProjectileActor>(
		ProjectileClass,
		SpawnTransform,
		ActorInfo->OwnerActor.Get(),
		Cast<APawn>(ActorInfo->OwnerActor.Get()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn,
		ESpawnActorScaleMethod::OverrideRootScale
	);
	
	ProjectileActor->FinishSpawning(SpawnTransform);
	// EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
