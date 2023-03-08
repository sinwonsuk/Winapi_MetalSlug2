#include "BazookaBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"

BazookaBullet::BazookaBullet()
{
}

BazookaBullet::~BazookaBullet()
{
}

void BazookaBullet::Start()
{
	{
		BulletRender = CreateRender(MetalSlugOrder::Bullet);
		BulletRender->CreateAnimation({ .AnimationName = "BazookaBullet",  .ImageName = "BazookaBullet.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "MiddleExploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.1f,.Loop = true });
		BulletRender->SetScale({ 800,800 });
	
		BulletRender->ChangeAnimation("BazookaBullet"); 

	}

	
}

void BazookaBullet::Update(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;



	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))
	{

		BulletRender->ChangeAnimation("MiddleExploision");
		DeathCheck = true;


		Check = false;
		SetMove(-MoveDir * _DeltaTime * 500);

	}
	if (DeathCheck == true)
	{
		if (BulletRender->IsAnimationEnd())
		{
			this->Death(); 
		}
	}


	SetMove(MoveDir * _DeltaTime * 500);
}
