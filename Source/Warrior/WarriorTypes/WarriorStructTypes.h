// Piang

#pragma once
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "WarriorStructTypes.generated.h"

class UInputMappingContext;
class UWarriorHeroGameplayAbility;
class UWarriorHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(Categories="Input"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Meta=(TitleProperty="InputTag"))
	TArray<FWarriorHeroAbilitySet> DefaultWeaponAbilities;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FScalableFloat WeaponBaseDamage;
};