#include "Bullets.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Player.h"
#include "ContentsEnums.h"
#include "Monster.h"
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
		//AnimationRender->SetPosition({500,500 });
		AnimationRender->SetScale({ 48,48 });
		AnimationRender->On();
	//	AnimationRender->

	}

	{
		Collision = CreateCollision(MetalSlugOrder::Bullet);
		Collision->SetScale({ 30, 30 });
		
	}

}

void Bullets::Update(float _DeltaTime)
{
	//CurPos = { 0,0 };
	
	SetMove(MoveDir * _DeltaTime* 1500);


	
	//	if (test == false)
	//	{
	//		CurPos = { Player::MainPlayer->GetPos().x, Player::MainPlayer->GetPos().y - 100 };
	//		Collision->SetPosition({ CurPos });
	//		AnimationRender->Off();
	//		Collision->Off();
	//	}
	//


	//if (test == true)
	//{
	//	Collision->On();
	//	switch (Dir)
	//	{	
	//	case Direction::Left:
	//		
	//		AnimationRender->SetPosition({ CurPos });
	//		
	//		MoveDir = float4::Left * 2000;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::Right:
	//	
	//		AnimationRender->SetPosition({ CurPos });			
	//		MoveDir = float4::Right * 2000;
	//		AnimationRender->On();
	//		//test = false;
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::Down:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4::Down * 2000;
	//		AnimationRender->On();
	//		SetMove(MoveDir * _DeltaTime);
	//		break;
	//	case Direction::Up:
	//		AnimationRender->SetPosition({ CurPos });
	//		MoveDir = float4::Up * 2000;
	//		AnimationRender->On();
	//		
	//		break;

	//	default:
	//		break;
	//	}
	//}
	////SetMove(MoveDir * _DeltaTime);

	///*if (nullptr != Collision)
	//{
	//	std::vector<GameEngineCollision*> collision;
	//	if (true == Collision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision) && test ==true)
	//	{
	//	
	//		this->Death();
	//		for (size_t i = 0; i < collision.size(); i++)
	//		{
	//			Monster* ColActor = collision[i]->GetActor();
	//			
	//		    ColActor->Death();
	//		}
	//	
	//		AnimationRender->Off();
	//		
	//	}

	//}*/
	

	

}

void Bullets::Render(float _Time)
{
	//Collision->DebugRender(); 
}
