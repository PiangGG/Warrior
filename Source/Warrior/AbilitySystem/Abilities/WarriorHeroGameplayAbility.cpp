// Piang


#include "WarriorHeroGameplayAbility.h"

#include "Warrior/Characters/WarriorHeroCharacter.h"
#include "Warrior/Controllers/WarriorHeroPlayerController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedWarriorHeroCharacter.IsValid()?CachedWarriorHeroCharacter.Get():nullptr;
}

AWarriorHeroPlayerController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroPlayerController.IsValid())
	{
		CachedWarriorHeroPlayerController = Cast<AWarriorHeroPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedWarriorHeroPlayerController.IsValid()?CachedWarriorHeroPlayerController.Get():nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
