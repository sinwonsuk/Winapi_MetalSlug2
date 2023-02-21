#include "MonsterCamelBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentsEnums.h"
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
		BulletRender->SetImage("HeavyBullet.Bmp");
		//AnimationRender->SetPosition({ 500,500 });
		BulletRender->SetScale({ 132,60 });
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
	MoveDir = float4::Left;
	SetMove(MoveDir * _DeltaTime * 500);

}
