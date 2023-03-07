#include "MetalSlugCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"
#include "SelectLevel.h"

MetalSlugCore MetalSlugCore::Core;

MetalSlugCore::MetalSlugCore() 
{
}

MetalSlugCore::~MetalSlugCore() 
{
}

void MetalSlugCore::Start()
{
	
	GameEngineWindow::SettingWindowSize({960.0f, 750.0f});

	new int();

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<SelectLevel>("SelectLevel");
	CreateLevel<PlayLevel>("PlayLevel");
	ChangeLevel("PlayLevel");
	//ChangeLevel("PlayLevel");
	
}

void MetalSlugCore::Update()
{
	
}
void MetalSlugCore::End() 
{
	
}