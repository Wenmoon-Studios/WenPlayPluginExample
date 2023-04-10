// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TransactionStatus.h"

#include "TransactionState.generated.h"

USTRUCT(BlueprintType)
struct FTransactionState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MultiversX")
	TEnumAsByte<ETransactionStatus> status = ETransactionStatus::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MultiversX")
	FString txHash;

	FString id;

	bool checkingState = false;
};
