// Piang


#include "DataAsset_StartUpDataBase.h"

#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToWarriorAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorAscToGive,
                                                                     int32 ApplyLevel)
{
	check(InWarriorAscToGive);
	
	GrantAbilities(ActivateOnGivenAbilities,InWarriorAscToGive,ApplyLevel);
	GrantAbilities(ReactiveAbilities,InWarriorAscToGive,ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,UWarriorAbilitySystemComponent* InWarriorAscToGive,int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (auto &Element : InAbilitiesToGive)
	{
		if (!Element)continue;
		FGameplayAbilitySpec AbilitySpec(Element);
		AbilitySpec.SourceObject = InWarriorAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InWarriorAscToGive->GiveAbility(AbilitySpec);
	}
}
