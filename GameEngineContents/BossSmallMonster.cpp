#include "BossSmallMonster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Boss.h"
#include "BulletEffect.h"
BossSmallMonster::BossSmallMonster()
{
}

BossSmallMonster::~BossSmallMonster()
{
}



void BossSmallMonster::Start()
{
	AnimationRender = CreateRender(MetalSlugOrder::BossMonster);
	AnimationRender->SetScale({ 500,500 });
	AnimationRender->CreateAnimation({ .AnimationName = "RightMonsterAttack",  .ImageName = "RightMonsterAttack.bmp", .Start = 0, .End = 18, .InterTime = 0.1f,.Loop = true });
	AnimationRender->CreateAnimation({ .AnimationName = "RightMonsterDeath",  .ImageName = "RightMonsterDeath.bmp", .Start = 0, .End = 19, .InterTime = 0.1f,.Loop = true });
	AnimationRender->CreateAnimation({ .AnimationName = "RightMonsterIdle",  .ImageName = "RightMonsterIdle.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
	AnimationRender->CreateAnimation({ .AnimationName = "RightMonsterJump",  .ImageName = "RightMonsterJump.bmp", .Start = 0, .End = 8, .InterTime = 0.1f,.Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "RightMonsterMove",  .ImageName = "RightMonsterMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f,.Loop = true });

	AnimationRender->CreateAnimation({ .AnimationName = "MonsterAttack",  .ImageName = "MonsterAttack.bmp", .Start = 0, .End = 18, .InterTime = 0.1f,.Loop = true });
	AnimationRender->CreateAnimation({ .AnimationName = "MonsterDeath",  .ImageName = "DeathOne.bmp", .Start = 0, .End = 11, .InterTime = 0.1f,.Loop = true });
	AnimationRender->CreateAnimation({ .AnimationName = "MonsterJump",  .ImageName = "MonsterJump.bmp", .Start = 0, .End = 8, .InterTime = 0.1f,.Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "MonsterIdle",  .ImageName = "MonsterIdle.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
	AnimationRender->CreateAnimation({ .AnimationName = "MonsterMove",  .ImageName = "MonsterMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f,.Loop = true });

	ChangeState(SmallMonsterState::LEFTMOVE);
	
	{
		MonsterCollision = CreateCollision(MetalSlugOrder::BossMonster);
		MonsterCollision->SetScale({ 50, 100 });
		MonsterCollision->SetPosition({ 0,-70 });
	}

}



void BossSmallMonster::Movecalculation(float _DeltaTime)
{

	MoveDir += float4::Down * 1000.0f * _DeltaTime;

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


	


	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0 )))
	{
		if (StateValue == SmallMonsterState::RIGHTJUMP && AttackCheck == false)
		{
			ChangeState(SmallMonsterState::RIGHTIDLE);
			AttackCheck = true;
			MoveDir = { 0,0 };
		}
		if (StateValue == SmallMonsterState::LEFTJUMP && AttackCheck == false)
		{
			ChangeState(SmallMonsterState::LEFTIDLE);
			AttackCheck = true;
			MoveDir = { 0,0 };
		}
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
	
		SetMove( MoveDir * _DeltaTime );
	

}

void BossSmallMonster::AnimationCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName.data()); 

}
void BossSmallMonster::Update(float _DeltaTime)
{
	



	if (nullptr != MonsterCollision && StateValue != SmallMonsterState::LEFTJUMP  && StateValue != SmallMonsterState::RIGHTJUMP)
	{
		std::vector<GameEngineCollision*> collision;

		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Boss), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision) )
		{
			if (CollisionCheck == false)
			{
				CurMoveDir = GetPos();
				CollisionCheck = true;
			}
			
			
			MoveDir.y = 0;
			

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
			
			}


		}
	}
	if (CurMoveDir.x - 170 > GetPos().x  && StateValue == SmallMonsterState::LEFTMOVE)
	{
		
		ChangeState(SmallMonsterState::LEFTJUMP);
		MoveDir += float4::Up * 450;
		JumpCheck = true;
		
	}
	 if (12000 <  GetPos().x && StateValue == SmallMonsterState::RIGHTMOVE)
	{
		
		ChangeState(SmallMonsterState::RIGHTJUMP);
		MoveDir += float4::Up * 450;
		JumpCheck = true;

	}


	if (nullptr != MonsterCollision && StateValue == SmallMonsterState::LEFTJUMP)
	{
		std::vector<GameEngineCollision*> collision;

		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Tent), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			if (CollisionCheck == true)
			{
				MoveDir.y = 0;
				ChangeState(SmallMonsterState::RIGHTJUMP);
				MoveDir += float4::Up * 450;
				JumpCheck = true;

				CollisionCheck = false;
			}


		}
	}
	if (nullptr != MonsterCollision && StateValue == SmallMonsterState::RIGHTJUMP)
	{
		std::vector<GameEngineCollision*> collision;

		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Tent), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			if (CollisionCheck == true)
			{
				MoveDir.y = 0;
				ChangeState(SmallMonsterState::LEFTJUMP);
				MoveDir += float4::Up * 450;
				JumpCheck = true;

				CollisionCheck = false;
			}


		}
	}

	if (nullptr != MonsterCollision && (StateValue == SmallMonsterState::LEFTJUMP || StateValue == SmallMonsterState::LEFTIDLE || StateValue == SmallMonsterState::LEFTATTACK))
	{
		std::vector<GameEngineCollision*> collision;

		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
		
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				ColActor->Death();
			}


			if (SoundCheck == false)
			{
				DeathSound = GameEngineResources::GetInst().SoundPlayToControl("RebelDeath.mp3");
				DeathSound.LoopCount(1);
				SoundCheck = true;
			}


			ChangeState(SmallMonsterState::LEFTDEATH);

		}
	}
	if (nullptr != MonsterCollision && (StateValue == SmallMonsterState::RIGHTJUMP || StateValue == SmallMonsterState::RIGHTIDLE || StateValue == SmallMonsterState::RIGHTATTACK))
	{
		std::vector<GameEngineCollision*> collision;

		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				ColActor->Death();
			}


			if (SoundCheck == false)
			{
				DeathSound = GameEngineResources::GetInst().SoundPlayToControl("RebelDeath.mp3");
				DeathSound.LoopCount(1);
				SoundCheck = true;
			}

			ChangeState(SmallMonsterState::RIGHTDEATH);

		}
	}

	if (StateValue == SmallMonsterState::RIGHTDEATH)
	{
		if (AnimationRender->IsAnimationEnd())
		{
			this->Death();
		}
	}


	if (StateValue == SmallMonsterState::LEFTDEATH)
	{
		if (AnimationRender->IsAnimationEnd())
		{
			this->Death(); 
		}
	}
	
	
	Movecalculation(_DeltaTime);
	UpdateState(_DeltaTime);
}

void BossSmallMonster::Render(float _Time)
{
    //	MonsterCollision->DebugRender(); 
}
