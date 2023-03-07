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


}

void TitleBack::Update(float _DeltaTime)
{
	

}
