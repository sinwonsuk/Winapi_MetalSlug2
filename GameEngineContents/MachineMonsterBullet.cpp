#include "MachineMonsterBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
MachineMonsterBullet::MachineMonsterBullet()
{
}

MachineMonsterBullet::~MachineMonsterBullet()
{
}

void MachineMonsterBullet::Start()
{
	{
		BulletRender = CreateRender(MetalSlugOrder::MonsterBullet);
		BulletRender->SetScale({ 800,800 });
		BulletRender->CreateAnimation({ .AnimationName = "Missile", .ImageName = "MachineMonsterBullet.bmp", .Start = 6, .End = 11, .InterTime = 0.1f , .Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "Exploision", .ImageName = "SmallExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f, .Loop = false });
		BulletRender->ChangeAnimation("Missile");
	}
	{
		Effect = CreateRender(MetalSlugOrder::Effect);
		Effect->SetScale({ 800,800 });
		Effect->SetPosition({ 300,20 });
		Effect->CreateAnimation({ .AnimationName = "Effect", .ImageName = "MachineMonsterSfx.bmp", .Start = 0, .End = 17, .InterTime = 0.1f , .Loop = false });
	
		Effect->ChangeAnimation("Effect");
	}


}

void MachineMonsterBullet::Update(float _DeltaTime)
{
	MoveDir += float4::Down * 1000.0f * _DeltaTime;


	/*if (BulletMove == true)
	{

		MoveDir += float4::Left * 2000;

	}*/

	if (300.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -700.0f;
		}
		else
		{
			MoveDir.x = 700.0f;
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

		BulletRender->ChangeAnimation("Exploision");
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


	Effect->SetMove(-MoveDir * _DeltaTime);

	SetMove(MoveDir * _DeltaTime);

}
