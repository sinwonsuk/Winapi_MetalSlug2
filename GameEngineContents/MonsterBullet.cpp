#include "MonsterBullet.h"
#include "Monster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Player.h"

MonsterBullet::MonsterBullet()
{

}

MonsterBullet::~MonsterBullet()
{

}

void MonsterBullet::Start()
{
	

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

	
	if (MonsterBulletMove == true)
	{
		
		MoveDir += float4::Left * 20;
		
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


	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;
	
	
	
		if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))
		{

			BulletRender->ChangeAnimation("Stop");
			Check = false;
			MoveDir = { 0,0 };
			MonsterBulletMove = false;

			DeathCheck = true;
		}
		if (DeathCheck == true)
		{
			DeathTime += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 

			if (DeathTime > 0.5)
			{
				this->Death(); 
			}
		}

		
	
	SetMove(MoveDir* _DeltaTime);
	
}
