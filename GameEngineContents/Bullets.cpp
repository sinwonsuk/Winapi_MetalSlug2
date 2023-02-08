#include "Bullets.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
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
	if (test == true)
	{
		switch (Dir)
		{
		case Bullets::Left:
			MoveDir += float4::Left * 10;
			break;
		case Bullets::Right:
			MoveDir += float4::Right * 10;
			break;
		case Bullets::Up:
			MoveDir += float4::Up * 10;
			break;
		case Bullets::Down:
			MoveDir += float4::Down * 10;
			break;
		default:
			break;
		}
	}
	SetMove(MoveDir * _DeltaTime);

}
