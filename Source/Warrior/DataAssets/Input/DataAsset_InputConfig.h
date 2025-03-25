// Piang

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(Category="Input"))
	FGameplayTag InputTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext * DefaultMappingContext;

	/*
	 * 在使用结构作为数组元素时，可通过自定义的格式来美化分组显示的标题。
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;
	
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
