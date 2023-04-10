// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum ETransactionStatus
{
	None		UMETA(DisplayName = "None"),
	Pending		UMETA(DisplayName = "Pending"),
	Failed		UMETA(DisplayName = "Failed"),
	Successful	UMETA(DisplayName = "Successful")
};
