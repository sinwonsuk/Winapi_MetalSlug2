#include "RebelBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Player.h"

RebelBullet::RebelBullet()
{
}

RebelBullet::~RebelBullet()
{
}


void RebelBullet::Start()
{
	{
		BulletRender = CreateRender(MetalSlugOrder::MonsterBullet);
		BulletRender->SetScale({ 800,500 });
		BulletRender->CreateAnimation({ .AnimationName = "Bomb", .ImageName = "RebelWeapon.bmp", .Start = 0, .End = 4, .InterTime = 0.1f , .Loop = true});
		BulletRender->CreateAnimation({ .AnimationName = "Stop", .ImageName = "RebelWeapon.bmp", .Start = 5, .End = 13, .InterTime = 0.1f, .Loop = false });
		BulletRender->ChangeAnimation("Bomb");
	}
}

void RebelBullet::Update(float _DeltaTime)
{
	MoveDir += float4::Down * 1000.0f * _DeltaTime;


	if (BulletMove == true)
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
		DeathCheck = true; 
		

		Check = false;
		MoveDir = { 0,0 };

	}
	if (DeathCheck == true)
	{
		TimeCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (TimeCheck > 0.7)
		{
			this->Death(); 
		}


	}

	


	SetMove(MoveDir * _DeltaTime);



}
