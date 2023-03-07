#include "MapEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"

MapEffect* MapEffect::mapEffect;

MapEffect::MapEffect()
{
}

MapEffect::~MapEffect()
{
}

void MapEffect::Start()
{
	mapEffect = this;

	{
		BackGroundRender = CreateRender(MetalSlugOrder::Map);
		BackGroundRender->SetScale({ 1550,1550 });

		BackGroundRender->CreateAnimation({ .AnimationName = "BackGround",  .ImageName = "MapBackGround.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });	
		BackGroundRender->ChangeAnimation("BackGround");
	}
	{
		MiddleTent = CreateRender(MetalSlugOrder::Map);
		MiddleTent->SetScale({ 1000,1000 });
		MiddleTent->CreateAnimation({ .AnimationName = "MiddleTent",  .ImageName = "MapTent.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		MiddleTent->CreateAnimation({ .AnimationName = "MiddleJumpTent",  .ImageName = "MapTentJump.bmp", .Start = 0, .End = 3, .InterTime = 0.f,.Loop = false});
		MiddleTent->ChangeAnimation("MiddleTent");
		MiddleTent->SetPosition({ -520,-250 });
	}
	{
		RightTent = CreateRender(MetalSlugOrder::Map);
		RightTent->SetScale({ 1000,1000 });

		RightTent->CreateAnimation({ .AnimationName = "RightTent",  .ImageName = "MapRightTent.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		RightTent->CreateAnimation({ .AnimationName = "RightJumpTent",  .ImageName = "MapRightTentJump.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = false });
		RightTent->ChangeAnimation("RightTent");
		RightTent->SetPosition({ 380,-250 });
	}

	{
		LeftEffect = CreateCollision(MetalSlugOrder::Tent);
		LeftEffect->SetScale({ 100, 50 });
		LeftEffect->SetPosition({ -520,-250 });

	}

	{
		RightEffect = CreateCollision(MetalSlugOrder::Tent);
		RightEffect->SetScale({ 100, 50 });
		RightEffect->SetPosition({ 380,-250 });

	}



}

void MapEffect::Update(float _DeltaTime)
{
	if (nullptr != LeftEffect && LeftCheck == false)
	{
		std::vector<GameEngineCollision*> collision;

		if (true == LeftEffect->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::BossMonster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			MiddleTent->ChangeAnimation("MiddleJumpTent");
			LeftCheck = true;
		}
	}


	if (LeftCheck == true)
	{
		if (MiddleTent->IsAnimationEnd())
		{
			MiddleTent->ChangeAnimation("MiddleTent");
			LeftCheck = false;
		}
	}


	if (nullptr != RightEffect && RightCheck == false)
	{
		std::vector<GameEngineCollision*> collision;

		if (true == RightEffect->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::BossMonster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			RightTent->ChangeAnimation("RightJumpTent");
			RightCheck = true;
		}
	}

	if (RightCheck == true)
	{
		if (RightTent->IsAnimationEnd())
		{
			RightTent->ChangeAnimation("RightTent");
			RightCheck = false;
		}
	}




}

void MapEffect::Render(float _Time)
{
	//RightEffect->DebugRender(); 
	//LeftEffect->DebugRender(); 
}
