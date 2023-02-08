#include "Bullets.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "Player.h"
Bullets::Bullets()
{
}

Bullets::~Bullets()
{
}

void Bullets::Start()
{



	{
		GameEngineRender* AnimationRender = CreateRender(10);
		AnimationRender->SetImage("Bullet.Bmp");
		//AnimationRender->SetPosition({500,500 });
		AnimationRender->SetScale({ 100,100 });
	}

}

void Bullets::Update(float _DeltaTime)
{
	//Player::MainPlayer->GetPos();
	//if (true == GameEngineInput::IsDown("Attack"))
	//{
	//	SetMove({1,0});
	//}

}
