// Piang

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartUpDataBase.generated.h"

USTRUCT(BlueprintType)
struct FWarriorHeroAbility
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(Category="Input"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(Category="Input"))
	TSubclassOf<UWarriorGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};
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
	TArray<FWarriorHeroAbility> HeroStartUpAbilitySets;
};
