// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class AAuraCharacterBase;
class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemOverlapBegin, float, AttrChange);
UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<AAuraCharacterBase> OverlappedCharacter;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collision")
	TObjectPtr<USphereComponent> SphereComp;

	FOnItemOverlapBegin OnItemOverlapBegin;

	UFUNCTION()
	void OnBeginOverlapFunc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
