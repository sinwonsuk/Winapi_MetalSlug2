#include "MachineMonster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"

MachineMonster::MachineMonster()
{
}


MachineMonster::~MachineMonster()
{
}


void MachineMonster::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });
		AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "MachineMonster.bmp", .Start = 0, .End = 7, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Move",  .ImageName = "MachineMonsterMove.bmp", .Start = 0, .End = 1, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "AttackPre",  .ImageName = "MachineMonsterAttackPre.bmp", .Start = 0, .End = 5, .InterTime = 0.1f ,.Loop = true , .FrameIndex{5,4,3,2,1,0} });
		AnimationRender->CreateAnimation({ .AnimationName = "AttackPre2",  .ImageName = "MachineMonsterAttack.bmp", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = true , .FrameIndex{5,4,3,2,1,0} });
		AnimationRender->CreateAnimation({ .AnimationName = "Attack",  .ImageName = "MachineMonsterAttack.bmp", .Start = 0, .End = 6, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Death",  .ImageName = "MachineMonsterDeath.bmp", .Start = 0, .End = 19, .InterTime = 0.1f,.Loop = false });
	}
	{
		Effect = CreateRender(16);
		Effect->SetScale({ 1000,1000 });
		Effect->SetPosition({ 0,-100 });
		Effect->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });
		Effect->ChangeAnimation("Exploision");
		Effect->Off(); 
	}
	ChangeState(MachineState::IDLE);

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetScale({ 250,300 });
	}



}


void MachineMonster::Movecalculation(float _DeltaTime)
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





	if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0))))
	{
		Check = false;
	}


	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0))))
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

void MachineMonster::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName);
}


void MachineMonster::Update(float _DeltaTime)
{

	if (nullptr != MonsterCollision)
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
	if (Hp <= -30)
	{
		ChangeState(MachineState::DEATH);
	}

	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);

}

void MachineMonster::Render(float _Time)
{
	//MonsterCollision->DebugRender();
}
