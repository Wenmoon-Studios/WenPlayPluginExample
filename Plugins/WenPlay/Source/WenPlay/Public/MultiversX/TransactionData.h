// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TransactionData.generated.h"

USTRUCT(BlueprintType)
struct FTransactionData
{
	GENERATED_BODY()

	UPROPERTY()
	int nonce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TransactionData")
	FString from;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TransactionData")
	FString to;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TransactionData")
	FString amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TransactionData")
	int gasPrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TransactionData")
	int gasLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TransactionData")
	FString data;

	UPROPERTY()
	FString chainId;

	UPROPERTY()
	int version;
};
