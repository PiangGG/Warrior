#pragma once

UENUM(BlueprintType)
enum class EWarriorConfirmType :uint8
{
	Yes,
	No
};

UENUM(BlueprintType)
enum class EWarriorValidType :uint8
{
	Valid,
	InValid
};

UENUM(BlueprintType)
enum class EWarriorSuccessType :uint8
{
	Successful,
	Failed
};