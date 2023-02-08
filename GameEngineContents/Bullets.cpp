#include "Bullets.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include "Player.h"
#include "ContentsEnums.h"
Bullets::Bullets()
{
}

Bullets::~Bullets()
{
}

void Bullets::Start()
{



	{
		AnimationRender = CreateRender(10);
		AnimationRender->SetImage("Bullet.Bmp");
		AnimationRender->SetPosition({500,500 });
		AnimationRender->SetScale({ 100,100 });
		//AnimationRender->Off();
	//	AnimationRender->

	}

}

void Bullets::Update(float _DeltaTime)
{
	//CurPos = { 0,0 };
	
	if (test == false)
	{
		CurPos = { Player::MainPlayer->GetPos().x, Player::MainPlayer->GetPos().y - 100 };
	}

	if (test == true)
	{

		
		
		switch (Dir)
		{	
		case Direction::Left:
			
			AnimationRender->SetPosition({ CurPos });
			MoveDir += float4::Left * 2;
			AnimationRender->On();
			break;
		case Direction::Right:
		
			AnimationRender->SetPosition({ CurPos });
			MoveDir += float4::Right * 2;
			AnimationRender->On();
			break;
		case Direction::Down:
			AnimationRender->SetPosition({ CurPos });
			MoveDir += float4::Down * 2;
			AnimationRender->On();
			break;
		case Direction::Up:
			AnimationRender->SetPosition({ CurPos });
			MoveDir += float4::Up * 2;
			AnimationRender->On();
			break;

		default:
			break;
		}
	}
	SetMove(MoveDir * _DeltaTime);

}
