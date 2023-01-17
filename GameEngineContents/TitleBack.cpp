#include "TitleBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

TitleBack::TitleBack() 
{
}

TitleBack::~TitleBack() 
{
}


void TitleBack::Start() 
{
	float4 Size = GameEngineWindow::GetScreenSize();
	

	GameEngineRender* Render = CreateRender("titleback.bmp", BubbleRenderOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());
}