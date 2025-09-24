// Piang

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartUpDataBase.generated.h"

struct FWarriorHeroAbilitySet;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_HeroStartUpDataBase : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

	virtual void GiveToWarriorAbilitySystemComponent(UWarriorAbilitySystemComponent* InAscToGive,int32 ApplyLevel = 1)override;
private:
	UPROPERTY(EditDefaultsOnly,Category="StartUpData",meta=(TitleProperty="Input"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;
};
