// Piang


#include "DataAsset_StartUpDataBase.h"

#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "GameplayEffect.h"
void UDataAsset_StartUpDataBase::GiveToWarriorAbilitySystemComponent(UWarriorAbilitySystemComponent* InAscToGive,
                                                                     int32 ApplyLevel)
{
	check(InAscToGive);
	
	GrantAbilities(ActivateOnGivenAbilities,InAscToGive,ApplyLevel);
	GrantAbilities(ReactiveAbilities,InAscToGive,ApplyLevel);

	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (auto EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass)continue;
			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InAscToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel,InAscToGive->MakeEffectContext());
		}
	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,UWarriorAbilitySystemComponent* InAscToGive,int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (auto &Element : InAbilitiesToGive)
	{
		if (!Element)continue;
		FGameplayAbilitySpec AbilitySpec(Element);
		AbilitySpec.SourceObject = InAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InAscToGive->GiveAbility(AbilitySpec);
	}
}
