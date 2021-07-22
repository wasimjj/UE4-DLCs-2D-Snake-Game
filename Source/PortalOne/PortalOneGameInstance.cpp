// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalOneGameInstance.h"

void UPortalOneGameInstance::Init()
{
	FindFiles();
}

void UPortalOneGameInstance::FindFiles()
{

	if(GetWorld()->WorldType == EWorldType::PIE)
	{
		GamesList = TArray<FString>{"Snake2d","SurvivalGame"};
		return;
	}
	TArray<FString> FullFilesPath;
	IFileManager::Get().FindFilesRecursive(FullFilesPath, *FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir() + "/Paks/"),  _T("*.pak"), true, false, false);
	for(auto File : FullFilesPath)
	{
		FString GameName = FPaths::GetBaseFilename(File);
		if(!GameName.Contains("PortalOne"))
		{
			GamesList.Add(GameName);
		}
	}
}
