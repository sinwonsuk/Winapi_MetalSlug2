#include "MonsterCamelBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineTime.h>
MonsterCamelBullet::MonsterCamelBullet()
{

}

MonsterCamelBullet::~MonsterCamelBullet()
{

}

void MonsterCamelBullet::Start()
{
	{
		BulletRender = CreateRender(10);
		BulletRender->SetImage("CamelBullet.Bmp");
		//AnimationRender->SetPosition({ 500,500 });
		BulletRender->SetScale({ 30,30 });
		BulletRender->On();
		//	AnimationRender->

	}

	{
		Collision = CreateCollision(MetalSlugOrder::MonsterBullet);
		Collision->SetScale({ 100, 100 });
	}


}

void MonsterCamelBullet::Update(float _DeltaTime)
{
	if (CamelSound == false)
	{
		CamelBullet = GameEngineResources::GetInst().SoundPlayToControl("CamelBullet.mp3");
		CamelBullet.LoopCount(1);
		CamelSound = true;
	}


	MoveDir = float4::Left;
	SetMove(MoveDir * _DeltaTime * 500);
	Time += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 

	if (Time > 5)
	{
		this->Death(); 
	}

}
