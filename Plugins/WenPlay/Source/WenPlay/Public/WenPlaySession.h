// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlatformHttp.h"

#include "NetworkType.h"
#include "ClientMetadata.h"
#include "WalletConnectProtocol.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

#include "WenPlaySession.generated.h"

UCLASS(BlueprintType)
class AWenPlaySession : public AActor
{
public:
	GENERATED_BODY()
	
	AWenPlaySession()
		: Connected(false)
	{
		PrimaryActorTick.bCanEverTick = true;
	}

	UFUNCTION(BlueprintCallable, Category = "WenPlaySession")
	void CreateWenPlaySession(FString const& InProjectID, FClientMetadata const& InMetadata,
			TEnumAsByte<ENetworkType> InNetworkType, FString const& InMainNetEndPoint);

	UFUNCTION(BlueprintCallable, Category = "WenPlaySession")
	void UpdateSessionURI();

	UFUNCTION(BlueprintCallable, Category = "WenPlaySession")
	UPARAM(DisplayName = "TransactionID")
	FString SignTransaction(FTransactionData const& Transaction);

	UFUNCTION(BlueprintCallable, Category = "WenPlaySession")
	UPARAM(DisplayName = "TransactionState")
	FTransactionState GetTransactionState(FString const& TransactionId);

	UFUNCTION(BlueprintCallable, Category = "WenPlaySession")
	void CloseSession();

	virtual void Tick(float DeltaSeconds);

protected:

	void UpdateSession();

	void HandleCheckTransactionStatusHttpRequestComplete(FHttpRequestPtr Request, 
		FHttpResponsePtr Response, bool bWasSuccessful);

	void HandleGetNonceHttpRequestComplete(FHttpRequestPtr Request,
		FHttpResponsePtr Response, bool bWasSuccessful);

	void HandleSignTransaction(FString const& Response);

	void HandleSignTransactionHttpRequestComplete(FHttpRequestPtr Request,
		FHttpResponsePtr Response, bool bWasSuccessful);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WenPlaySession")
	FString URI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WenPlaySession")
	FString Account;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WenPlaySession")
	bool Connected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WenPlaySession")
	TArray<FTransactionState> Transactions;

	FClientMetadata Metadata;
	FString ProjectID;

	TEnumAsByte<ENetworkType> NetworkType;

	FString MainNetEndpoint;
	FString DevNetEndpoint = "https://devnet-api.multiversx.com";

	int64 LastTransactionToSign = -1;

	TMap<int64, FTransactionData> TransactionToSign;
	TMap<FHttpRequestPtr, FTransactionData> HttpRequestsToData;
	
	TMap<int64, FTransactionState> IdToTransactionsState;
	TMap<FHttpRequestPtr, FTransactionState> HttpRequestsToTransactionsState;

	TMap<FHttpRequestPtr, FString> HttpRequestsToTransactionId;

	TSharedPtr<WalletConnectProtocol> Transport;
};
