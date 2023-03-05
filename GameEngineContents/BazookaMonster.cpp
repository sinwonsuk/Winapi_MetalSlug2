#include "BazookaMonster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Boss.h"
#include "BazookaBullet.h"
BazookaMonster::BazookaMonster()
{
}

BazookaMonster::~BazookaMonster()
{
}

void BazookaMonster::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "LeftMove",  .ImageName = "LeftBazookaMove.bmp", .Start = 0, .End = 10, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "RightMove",  .ImageName = "RightBazookaMove.bmp", .Start = 0, .End = 10, .InterTime = 0.1f ,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "LeftPreAttack",  .ImageName = "LeftBazookaAttack.bmp", .Start = 0, .End = 8, .InterTime = 0.15f,.Loop = true , .FrameIndex{0,2,4} });
		AnimationRender->CreateAnimation({ .AnimationName = "RighPretAttack",  .ImageName = "RightBazookaAttack.bmp", .Start = 0, .End = 8, .InterTime = 0.15f,.Loop = true, .FrameIndex{0,2,4} });
		AnimationRender->CreateAnimation({ .AnimationName = "LeftAttack",  .ImageName = "LeftBazookaAttack.bmp", .Start = 0, .End = 8, .InterTime = 0.15f,.Loop = false, .FrameIndex{4,5,4} });
		AnimationRender->CreateAnimation({ .AnimationName = "RightAttack",  .ImageName = "RightBazookaAttack.bmp", .Start = 0, .End = 8, .InterTime = 0.15f,.Loop = false, .FrameIndex{4,5,4} });
	
	}
	{
		Effect = CreateRender(MetalSlugOrder::BulletEffect);
		Effect->SetScale({ 800,800 });
		Effect->SetPosition({ 65,-20 });
		Effect->CreateAnimation({ .AnimationName = "Effect",  .ImageName = "BazookaAttackEffect.bmp", .Start = 0, .End = 17, .InterTime = 0.1f,.Loop = false });
		Effect->ChangeAnimation("Effect");
		Effect->Off(); 
	}
	{
		MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MonsterCollision->SetPosition({ 0,0 });
		MonsterCollision->SetScale({ 50,100 });
	}
	ChangeState(BazookaMonsterState::LEFTMOVE);
}


void BazookaMonster::Movecalculation(float _DeltaTime)
{
	MoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (250.0f <= abs(MoveDir.x))
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

	


	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;


	


	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))
	{


		Check = false;
	}
	

	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))
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
	if (LeftMoveCheck == false)
	{
		SetMove(MoveDir * _DeltaTime);
	}
	if (LeftMoveCheck == true)
	{
		
		SetPos({ Boss::boss->GetPos().x-210 , Boss::boss->GetPos().y-500 });
	}
	if (RightMoveCheck == true)
	{

		SetPos({ Boss::boss->GetPos().x + 210 , Boss::boss->GetPos().y - 500 });

	}
}


void BazookaMonster::Update(float _DeltaTime)
{
	if (nullptr != MonsterCollision )
	{
		std::vector<GameEngineCollision*> collision;

		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Boss), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			
			MoveDir.y = 0;

			if (CollisionCheck == false)
			{
				CurMoveDir = GetPos();
				CollisionCheck = true;
			}

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();

			}

		}
	}
	if (Boss::boss->Hp <= 0)
	{
		this->Death();
	}


	if (CurMoveDir.x - 210 > GetPos().x && StateValue == BazookaMonsterState::LEFTMOVE && StateValue != BazookaMonsterState::LEFTATTACKPRE)
	{
		ChangeState(BazookaMonsterState::LEFTATTACKPRE);	
	}
	if (12000 < GetPos().x && StateValue == BazookaMonsterState::RIGHTMOVE && StateValue != BazookaMonsterState::RIGHTATTACKPRE)
	{
		ChangeState(BazookaMonsterState::RIGHTATTACKPRE);
	}

	Movecalculation(_DeltaTime);
	 UpdateState(_DeltaTime);
}



void BazookaMonster::AnimationCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName.data(),true);

	if (StateValue == BazookaMonsterState::LEFTATTACK)
	{
		Effect->On();
		Effect->ChangeAnimation("Effect", true);
		BazookaBullet* Attor = GetLevel()->CreateActor<BazookaBullet>();
		Attor->SetPos({ GetPos().x+80 ,GetPos().y });
		Attor->MoveDir = float4::AngleToDirection2DToDeg(60);
	}
	if (StateValue == BazookaMonsterState::RIGHTATTACK)
	{
		Effect->On();
		Effect->ChangeAnimation("Effect", true);
		Effect->SetPosition({ -80,-10 });
		BazookaBullet* Attor = GetLevel()->CreateActor<BazookaBullet>();
		Attor->SetPos({ GetPos().x - 80 ,GetPos().y });
		Attor->MoveDir = float4::AngleToDirection2DToDeg(110);
	}
}

void BazookaMonster::Render(float _Time)
{
	//MonsterCollision->DebugRender(); 
}
