#include "Rebel.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Wall.h"
Rebel::Rebel()
{

}

Rebel::~Rebel()
{

}

void Rebel::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "RebelIdle.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Idle2",  .ImageName = "RebelIdle2.bmp", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "MovePre",  .ImageName = "RebelMovePre.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Move",  .ImageName = "RebelMove.bmp", .Start = 0, .End = 13, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "MoveFinish",  .ImageName = "RebelMoveFinish.bmp", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Attack",  .ImageName = "RebelAttack.bmp", .Start = 0, .End = 13, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Death",  .ImageName = "RebelDeath.bmp", .Start = 0, .End = 10, .InterTime = 0.075f,.Loop = false });




	}
	ChangeState(RebelState::IDLE); 

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetPosition({ 0,-80 });
		MonsterCollision->SetScale({ 50,150 });
	}


}

void Rebel::Update(float _DeltaTime)
{
	if (nullptr == MonsterCollision)
	{
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetPosition({ 0,-80 });
		MonsterCollision->SetScale({ 50,150 });
	}
	if (nullptr != MonsterCollision && Hp>0)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}
			Hp--;
		}
	}

	if (Hp <= 0)
	{
		MonsterCollision->Death();
		ChangeState(RebelState::DEATH);
	}



	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}

void Rebel::Movecalculation(float _DeltaTime)
{
	if (Hp <= 0)
	{
		return;
	}


	MoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (50.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -200.0f;
		}
		else
		{
			MoveDir.x = 200.0f;
		}
	}

	//if (450.0f <= abs(MoveDir.x))
	//{
	//	if (0 > MoveDir.x)
	//	{
	//		MoveDir.x = -450.0f;
	//	}
	//	else
	//	{
	//		MoveDir.x = 450.0f;
	//	}
	//}




	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	
	if (Wall::wall->GetHp() <= -50)
	{
		ChangeState(RebelState::DEATH);
	}


	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || (RGB(255, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(255, 0, 0))) && Wall::wall->GetHp() >= -49)
	{
	    

		Check = false;
	}
	if ((RGB(0, 255, 255) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 255))))
	{
		ChangeState(RebelState::MOVEFINISH);
	}



	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || (RGB(255, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(255, 0, 0))) && Wall::wall->GetHp() >= -49)
			{
				continue;
			}

			if (50.0f <= abs(MoveDir.y))
			{
				if (0 > MoveDir.y)
				{
					MoveDir.y = -100.0f;
				}
				else
				{
					MoveDir.y = 0.0f;
				}
			}
			Check = true;
			break;
		}
	}

	SetMove(MoveDir * _DeltaTime);
}

void Rebel::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName);
}

void Rebel::Render(float _Time)
{
	//MonsterCollision->DebugRender();
}

