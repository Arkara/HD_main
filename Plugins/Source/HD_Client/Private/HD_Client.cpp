// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "HD_ClientPrivatePCH.h"
#include "HD_Client.h"

#define LOCTEXT_NAMESPACE "FHD_ClientModule"


void FHD_ClientModule::StartupModule()
{
	

	ISocketSubsystem* SocketSubsystemPointer = ISocketSubsystem::Get();


	TSharedRef<FInternetAddr> Addr = SocketSubsystemPointer->CreateInternetAddr(0, 56124);

	bool bIsValid;
	FString HostIp = "192.168.1.4";
	Addr->SetIp(*HostIp, bIsValid);

	if (bIsValid)
	{
		SendingSocket = SocketSubsystemPointer->CreateSocket(NAME_Stream, TEXT("FHD_Client tcp"));

		// try to connect to the server
		if (SendingSocket->Connect(*Addr) == true)
		{
			char DataBuffer[1024];
			int32 SentData;

			sprintf_s(DataBuffer, "Hello from UE4 Harikan Dawn Client!\n");
			SendingSocket->Send((uint8 *)DataBuffer, 1024, SentData);
		}
		SocketSubsystemPointer->DestroySocket(SendingSocket);
		SendingSocket = NULL;
	}
}

void FHD_ClientModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}





#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHD_ClientModule, HD_Client)