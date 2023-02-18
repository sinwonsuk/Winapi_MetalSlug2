#include "HeavyGun.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Player.h"
#include "ContentsEnums.h"
#include <math.h>

HeavyGun::HeavyGun()
{


}

HeavyGun::~HeavyGun()
{


}

void HeavyGun::Start()
{
	{
		AnimationRender = CreateRender(10);
		AnimationRender->SetImage("Bullet.Bmp");
		//AnimationRender->SetPosition({ 500,500 });
		AnimationRender->SetScale({ 100,100 });
		AnimationRender->On();
		//	AnimationRender->

	}

	{
		Collision = CreateCollision(MetalSlugOrder::Bullet);
		Collision->SetScale({ 100, 100 });
	}

}

void HeavyGun::Update(float _DeltaTime)
{
	

	SetMove(MoveDir * _DeltaTime * 1000);
	//AnimationRender->On();

	

	//if (test == true)
	//{
	//	Collision->On();
	//	switch (Dir)
	//	{
	//	case Direction::Left:

	//		AnimationRender->SetPosition({ CurPos });

	//		MoveDir = float4::Left * Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::Right:
	//		Angle = 0;
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4::Right * Speed;
	//		//MoveDir = float4{ 1,float(tan(75)) } *1000;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::Down:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4::Down * Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::Up:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4::Up * Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::A:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4{ 1,-0.3 } *Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::B:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4{ 1,-0.6 } *Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::C:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4{ 1,-0.9 } *Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::D:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4{ 1,-1.2 } *Speed;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	default:
	//		break;
	//	}
	//}

}

void HeavyGun::Render(float _Time)
{


}
