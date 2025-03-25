// Piang

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Warrior/DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InputConfig,const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserObject* ContextObject ,CallbackFunc Callback);
};

template <class UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	//check(InInputConfig);
	checkf(InInputConfig,TEXT("输入配置资产为空，不能继续绑定"))
	if (UInputAction * FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent,ContextObject,Func);
	}
}
