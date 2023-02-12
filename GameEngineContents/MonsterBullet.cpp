#include "MonsterBullet.h"
#include "Monster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>
#include "ContentsEnums.h"

MonsterBullet::MonsterBullet()
{

}

MonsterBullet::~MonsterBullet()
{

}

void MonsterBullet::Start()
{
	SetMove({ 800, 0 });

	{
		BulletRender = CreateRender(MetalSlugOrder::MonsterBullet);
		BulletRender->SetScale({ 500,500 });
		BulletRender->CreateAnimation({ .AnimationName = "Left_MonsterNife", .ImageName = "MonsterNife.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
		BulletRender->CreateAnimation({ .AnimationName = "Stop", .ImageName = "MonsterNife.bmp", .Start = 11, .End = 11, .InterTime = 0.1f });
		BulletRender->ChangeAnimation("Left_MonsterNife");
	}
}

void MonsterBullet::Update(float _DeltaTime)
{

	MoveDir += float4::Down * 1000.0f * _DeltaTime;

	if (test == false)
	{

	}


	if (test == true)
	{
		
		MoveDir += float4::Left * 10;
		
	}

	if (300.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -300.0f;
		}
		else
		{
			MoveDir.x = 300.0f;
		}
	}


	//ColMap.BMP �̰� �������ϸ� 
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("�浹�� �� �̹����� �����ϴ�.");
	}

	//// �� �̷��� ��ġ�� �����ε�/.

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;
	


	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) )
	{

		BulletRender->ChangeAnimation("Stop");
		//ChangeState(MonsterState::IDLE);
		Check = false;
		MoveDir = { 0,0 };
		test = false;
	}


	/*if (false == Check)
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
					MoveDir.y = -80.0f;
				}
				else
				{
					MoveDir.y = 0.0f;
				}

			}
			Check = true;
			break;
		}
	}*/

	SetMove(MoveDir* _DeltaTime);
	
}
