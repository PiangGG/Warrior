// Piang

#pragma once

#include "CoreMinimal.h"
#include "WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AWarriorHeroPlayerController;
class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,Category="Warrior|Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure,Category="Warrior|Ability")
	AWarriorHeroPlayerController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure,Category="Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
private:
	TWeakObjectPtr<AWarriorHeroCharacter> CachedWarriorHeroCharacter;
	TWeakObjectPtr<AWarriorHeroPlayerController> CachedWarriorHeroPlayerController;
};
