// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientMetadata.generated.h"

USTRUCT(BlueprintType) 
struct FClientMetadata
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Client Metadata")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Client Metadata")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Client Metadata")
	TArray<FString> icons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Client Metadata")
	FString name;
};
