#include "Monster.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include "Bullets.h"
Monster::Monster() 
{
}

Monster::~Monster() 
{
}

void Monster::Start()
{
	SetMove({500, 500});
	AnimationRender = CreateRender(MetalSlugOrder::Monster);
	AnimationRender->SetScale({ 400,400 });
	AnimationRender->CreateAnimation({ .AnimationName = "AAA",  .ImageName = "MonsterAttack.bmp", .Start = 0, .End = 18, .InterTime = 0.1f });

	AnimationRender->ChangeAnimation("AAA");

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MonsterCollision->SetScale({ 100, 100 });
		MonsterCollision->SetPosition({ 0,-100 });

	}
}

void Monster::Update(float _DeltaTime)
{
	if (nullptr != MonsterCollision)
	{
	/*	std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}
		}*/
	}




}

void Monster::Render(float _Time)
{
	MonsterCollision->DebugRender();
}

