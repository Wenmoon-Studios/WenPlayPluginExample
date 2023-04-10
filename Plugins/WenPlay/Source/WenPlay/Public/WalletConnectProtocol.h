// Copyright 2023 WenMoon Studios Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "IWebSocket.h"

#include "MultiversX/TransactionData.h"

DECLARE_DELEGATE(FUpdateSessionCallback);
DECLARE_DELEGATE_OneParam(FOnMessageCallback, FString const&);

class WalletConnectProtocol
{
public:
	~WalletConnectProtocol();

	FString Open(FString const& ProjectID, FClientMetadata const& Metadata, 
		ENetworkType NetworkType);
	void Close();

	int64 SignTransaction(FTransactionData const& TransactionData);
	void CloseSession();

	bool IsWalletConnected() const { return bIsWalletConnected; };

	FString const& GetAccountAddress() const { return AccountAddress; }

	void RegisterUpdateSessionCallback(FUpdateSessionCallback const& Callback)
	{
		UpdateSessionCallback = Callback;
	}

	void RegisterOnMessageCallback(int64 Id, FOnMessageCallback const& Callback)
	{
		OnMessageCallbacks.Add(Id, Callback);
	};

	void RemoveOnMessageCallback(int64 Id)
	{
		OnMessageCallbacks.Remove(Id);
	};

protected:
	void OnConnected();
	void OnConnectionError(const FString& Error);
	void OnClosed(int32 StatusCode, const FString& Reason, bool bWasClean);
	void OnMessage(const FString& Msg);

	FString GeneratePairingURI();
	FString GenerateRelayURL(FString const& ProjectID);

	void Subscribe(FString const& Topic);
protected:
	// Symmetric Key
	FString Key;
	TArray<uint8> KeyRaw;

	// SHA256 of symmetric key
	FString Topic;

	// Version of WalletConnect protocol
	FString ProtocolVersion = "2";

	// Ed25519/X25519 Keys - Hex String form
	FString PublicKey;
	FString PrivateKey;

	// Ed25519/X25519 Keys - Raw bytes form
	TArray<uint8> PublicKeyRaw;
	TArray<uint8> PrivateKeyRaw;

	// Subscribed topic list
	TArray<FString> SubscribedTopics;

	// Callback for WalletConnectSession for decrypted messages
	TMap<int64, FOnMessageCallback> OnMessageCallbacks;

	// Callback for WalletConnectSession when wallet data needs to be updated
	FUpdateSessionCallback UpdateSessionCallback;

	// Websocket for message communication
	TSharedPtr<IWebSocket> WebSocket;

	// Project metadata
	FClientMetadata Metadata;

	// Account address
	FString AccountAddress;

	// Dev/Main net identifier
	ENetworkType NetworkType;

	// Is Wallet connected, true after wc_sessionSettle has been received
	bool bIsWalletConnected = false;
};
