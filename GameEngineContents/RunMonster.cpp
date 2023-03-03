#include "RunMonster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "BulletEffect.h"
RunMonster::RunMonster()
{
}

RunMonster::~RunMonster()
{
}

void RunMonster::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "RunMonsterIdle.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Move",  .ImageName = "RunMonsterMove.bmp", .Start = 0, .End = 4, .InterTime = 0.2f ,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Body_Attack",  .ImageName = "RunMonsterBodyAttack.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Death",  .ImageName = "RunMonsterDeath.bmp", .Start = 0, .End = 8, .InterTime = 0.1f,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "DeathTwo",  .ImageName = "DeathTwo.bmp", .Start = 0, .End = 19, .InterTime = 0.1f,.Loop = false });
	}
	{
		AnimationBloodRender = CreateRender(MetalSlugOrder::Monster);
		AnimationBloodRender->SetScale({ 800,800 });

		AnimationBloodRender->CreateAnimation({ .AnimationName = "Blood",  .ImageName = "Blood.bmp", .Start = 0, .End = 8, .InterTime = 0.1f,.Loop = false });
		AnimationBloodRender->SetPosition({ -50,-50 });
	}
	//{
	//	AnimationRegRender = CreateRender(MetalSlugOrder::Monster);
	//	AnimationRegRender->SetScale({ 800,800 });
	//	AnimationRender->CreateAnimation({ .AnimationName = "Reg_Attack",  .ImageName = "RunMonsterRegAttack.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
	//	
	//}
	{
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetPosition({ 0,-80 });
		MonsterCollision->SetScale({ 50,150 });
	}
	AnimationBloodRender->ChangeAnimation("Blood");
	AnimationBloodRender->Off(); 

	ChangeState(RunMonsterState::MOVE);

}
void RunMonster::Movecalculation(float _DeltaTime)
{
	MoveDir += float4::Down * 1500.0f * _DeltaTime;
	
	if (50.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -200.0f;
		}
		else
		{
			MoveDir.x = 300.0f;
		}
	}

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	if (CarriageMonster == true  && CarriageMonsterSee == false)
	{
		AnimationRender->Off();
	}
	


	if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || (RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)))) && CarriageMonster == false ))
	{
		if (StateValue == RunMonsterState::DEATH)
		{
			MoveDir = { 0,0 };
		}
		Check = false;
	}
	if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || (RGB(255, 100, 0) == ColImage->GetPixelColor(NextPos, RGB(255, 100, 0)))) && CarriageMonster == true))
	{
		if (StateValue == RunMonsterState::DEATH)
		{
			MoveDir = { 0,0 };
		}
		Check = false;
	}
	if ((RGB(255, 100, 0) == ColImage->GetPixelColor(NextPos, RGB(255, 100, 0))))
	{
		AnimationRender->On();
		CarriageMonsterSee = true;
	}

	if (StateValue == RunMonsterState::DEATH)
	{
		DeathTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		if (DeathTime > 2)
		{
			this->Death(); 
		}
	}

	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || (RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)))) && CarriageMonster == false))
			{
				continue;
			}
			if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || (RGB(255, 100, 0) == ColImage->GetPixelColor(NextPos, RGB(255, 100, 0)))) && CarriageMonster == true))
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
	if (CarriageMonster == true)
	{
		Idle = false;
	}
	SetMove(MoveDir * _DeltaTime);
}
void RunMonster::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName);
}
void RunMonster::Update(float _DeltaTime)
{
	if (nullptr != MonsterCollision && StateValue != RunMonsterState::DEATH)
	{
		
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision) && Idle == false)
		{
			Hp--;
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();

				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				

				ColActor->Death();
			}			

			if (Hp <= 0)
			{
				MoveDir += float4::Right * 1000;
				MoveDir += float4::Up * 350;
			}
		}
	}

	if (nullptr != MonsterCollision && StateValue != RunMonsterState::DEATH)
	{

		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Boomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			Hp -= 5;
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();

				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				Effect->BoobBulletCheck = true; 
				ColActor->Death();
			}
			if (Hp <= 0)
			{				
				MoveDir += float4::Right * 1000;
				MoveDir += float4::Up * 350;
			}

		}
	}









	if (Hp <= 0)
	{
	//	MonsterCollision->Death();
		ChangeState(RunMonsterState::DEATH);
		AnimationBloodRender->On();
	}
	

	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}

void RunMonster::Render(float _Time)
{
	//MonsterCollision->DebugRender();
}
