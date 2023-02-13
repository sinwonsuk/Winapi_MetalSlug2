#include "Monster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <time.h>
#include "ContentsEnums.h"
#include "Bullets.h"
#include "MonsterBullet.h"



Monster* Monster::MonsterA;

Monster::Monster() 
{
}

Monster::~Monster() 
{
}



void Monster::Start()

{
	
	

	MonsterA = this;

	srand(static_cast<unsigned int>(time(nullptr)));
 	

	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 500,500 });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack",  .ImageName = "MonsterAttack.bmp", .Start = 0, .End = 18, .InterTime = 0.1f,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "MonsterMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "MonsterIdle.bmp", .Start = 0, .End = 5, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_AttackPre",  .ImageName = "AttackPre.bmp", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_PlayerCheck",  .ImageName = "PlayerCheck.bmp", .Start = 0, .End = 3, .InterTime = 0.15f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_DeathOne",  .ImageName = "DeathOne.bmp", .Start = 0, .End = 10, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_DeathTwo",  .ImageName = "DeathTwo.bmp", .Start = 0, .End = 19, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_MonsterJump",  .ImageName = "MonsterJump.bmp", .Start = 0, .End = 8, .InterTime = 0.1f  });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_MonsterBackJump",  .ImageName = "MonsterBackJump.bmp", .Start = 0, .End = 11, .InterTime = 0.075f , .Loop = false });

		//AnimationRender->CreateAnimation({ .AnimationName = "Left_MonsterNife",  .ImageName = "MonsterNife.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });

	}


	/*{
		BulletRender = CreateRender(MetalSlugOrder::MonsterBullet);
		BulletRender->SetScale({ 500,500 });
		BulletRender->CreateAnimation({ .AnimationName = "Left_MonsterNife", .ImageName = "MonsterNife.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
		BulletRender->ChangeAnimation("Left_MonsterNife");
	}*/



	{
		MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MonsterCollision->SetPosition({ 0,-100 });
		MonsterCollision->SetScale({ 100, 100 });

	}
	

	{
		PlayerCollision = CreateCollision(MetalSlugOrder::MonsterCheck);
		PlayerCollision->SetScale({ 500, 500 });
	}

	
	
	ChangeState(MonsterState::IDLE);

}
void Monster::Movecalculation(float _DeltaTime)
{
	

	

	
	MoveDir += float4::Down * 2000.0f * _DeltaTime;

	if (450.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -450.0f;
		}
		else
		{
			MoveDir.x = 450.0f;
		}
	}

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;
	

	if (RGB(0, 0, 255) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 255)) && StateValue == MonsterState::MOVE)
	{
		MoveDir += float4::Up * 550;
		ChangeState(MonsterState::JUMPBACK);

		return;
	}




	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) && StateValue != MonsterState::JUMPBACK)
	{
		if (StateValue == MonsterState::JUMP)
		{
			ChangeState(MonsterState::IDLE);
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

	




      SetMove(MoveDir * _DeltaTime);
}
void Monster::Update(float _DeltaTime)
{
	if (nullptr != MonsterCollision && StateValue != MonsterState::DEATHONE && StateValue != MonsterState::DEATHTWO)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			int Choice = rand() % 2;
			

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}

			if (Choice == 0 )
			{
				ChangeState(MonsterState::DEATHONE);
			}
			if (Choice == 1)
			{
				ChangeState(MonsterState::DEATHTWO);
			}
		}

	}


	if (nullptr != PlayerCollision && (StateValue == MonsterState::MOVE || StateValue == MonsterState::IDLE))
	{
		std::vector<GameEngineCollision*> collision;
		if (true == PlayerCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision) )
		{
			ChangeState(MonsterState::PlAYERCHECK);
			MoveDir = { 0,0 };
			return; 
		}
	}

	
	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}



void Monster::DirCheck(const std::string_view& _AnimationName)
{
	if (StateValue == MonsterState::MONSTERBULLET)
	{
		std::string PrevDirString = DirString;

		//BulletRender->ChangeAnimation(DirString + _AnimationName.data());

		if (GameEngineInput::IsPress("LeftMove"))
		{
			DirString = "Left_";
		}




		if (PrevDirString != DirString)
		{
			//BulletRender->ChangeAnimation(DirString + _AnimationName.data());

		}


	}


	else 
	{
		std::string PrevDirString = DirString;

		AnimationRender->ChangeAnimation(DirString + _AnimationName.data());

		if (GameEngineInput::IsPress("LeftMove"))
		{
			DirString = "Left_";
		}




		if (PrevDirString != DirString)
		{
			AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
			
		}
	}
}

void Monster::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

	//MonsterCollision->DebugRender();
	//PlayerCollision->DebugRender(); 
}


