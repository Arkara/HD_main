// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "Networking.h"
#include "Engine.h"
//include <string>


class FHD_ClientModule : public IModuleInterface
{
private:

	FSocket*       ListeningSocket;
	FSocket*       SendingSocket;
	FIPv4Endpoint  RemoteEndpointForConnection;
	FString        RemoteHostURL;
	int32          ReceiveBufferSize = 2 * 1024 * 1024;

public :

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


