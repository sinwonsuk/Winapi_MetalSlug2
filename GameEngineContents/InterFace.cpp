#include "InterFace.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Player.h"
InterFace::InterFace()
{
}

InterFace::~InterFace()
{
}

void InterFace::Start()
{

	{
		GameEngineRender* AnimationRender = CreateRender(2);
		AnimationRender->SetImage("Score.Bmp");
		AnimationRender->SetPosition({ 300,150 });
		AnimationRender->SetScale({ 300,100 });
		AnimationRender->EffectCameraOff();
	}


}

void InterFace::Update(float _DeltaTime)
{
	
	//GetLevel()->
	//SetPos(CamerPos);
	///*if (Player::MainPlayer->test23 == true)
	//{
	//	SetMove(Player::MainPlayer->GetCameraDir());
	//}*/
}
