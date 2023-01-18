#include "StudyGameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"


MetalSlugCore MetalSlugCore::Core;

MetalSlugCore::MetalSlugCore() 
{
}

MetalSlugCore::~MetalSlugCore() 
{
}

void MetalSlugCore::Start()
{
	
	GameEngineWindow::SettingWindowSize({1200.0f, (1200.0f / 800.0f) * 600.0f});

	new int();

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<PlayLevel>("PlayLevel");
	
	ChangeLevel("TitleLevel");

	
}

void MetalSlugCore::Update()
{
	
}
void MetalSlugCore::End() 
{
	
}