// Piang


#include "DataAsset_EnemyStartUpData.h"

#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/AbilitySystem/Abilities/WarriorEnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveToWarriorAbilitySystemComponent(UWarriorAbilitySystemComponent* InAscToGive,
                                                                      int32 ApplyLevel)
{
	Super::GiveToWarriorAbilitySystemComponent(InAscToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UWarriorEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass)continue;
			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InAscToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;
		
			InAscToGive->GiveAbility(AbilitySpec);
		}
	}
}
