#include "MiniBoss.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"

MiniBoss* MiniBoss::miniboss;

MiniBoss::MiniBoss()
{
}

MiniBoss::~MiniBoss()
{
}





void MiniBoss::Start()
{
	miniboss = this;

	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "MiniBossIdle.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "MiniBossRightMove.bmp", .Start = 0, .End = 5, .InterTime = 0.1f ,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Attack",  .ImageName = "MiniBossAttack.bmp", .Start = 0, .End = 6, .InterTime = 0.15f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "MiniBossLeftMove.bmp", .Start = 0, .End = 5, .InterTime = 0.1f ,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Surrender",  .ImageName = "MiniBossSurrender.bmp", .Start = 0, .End = 10, .InterTime = 0.1f,.Loop = false });
	}


	{
		MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MonsterCollision->SetScale({ 300,100 });
	}

	ChangeState(MiniMonsterState::LEFTMOVE);
}
void MiniBoss::Movecalculation(float _DeltaTime)
{
	MoveDir += float4::Down * 3500.0f * _DeltaTime;

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

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	


	if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))))
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
void MiniBoss::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName);
}
void MiniBoss::Update(float _DeltaTime)
{
	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}

void MiniBoss::Render(float _Time)
{
	//MonsterCollision->DebugRender();
}

