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
	

	GameEngineRender* Render = CreateRender("BackGround.bmp", 0);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());	
	Render->SetScale(GameEngineWindow::GetScreenSize());

	
	{
		AnimationRender = CreateRender(1);
		AnimationRender->SetScale({ 416, 32 });
		AnimationRender->SetPosition(float4(600, 780));		
		AnimationRender->CreateAnimation({ .AnimationName = "BackGroungWrite",  .ImageName = "BackGroundWrite.bmp", .Start = 0, .End = 1, .InterTime = 1.0f });		
	}
	
}

void TitleBack::Update(float _DeltaTime)
{
	AnimationRender->ChangeAnimation("BackGroungWrite");

}
