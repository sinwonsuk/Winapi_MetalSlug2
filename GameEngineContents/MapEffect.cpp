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
		MiddleTent->CreateAnimation({ .AnimationName = "MiddleJumpTent",  .ImageName = "MapTentJump.bmp", .Start = 0, .End = 3, .InterTime = 0.2f,.Loop = true});
		MiddleTent->ChangeAnimation("MiddleJumpTent");
		MiddleTent->SetPosition({ -520,-250 });
	}
	{
		RightTent = CreateRender(MetalSlugOrder::Map);
		RightTent->SetScale({ 1000,1000 });

		RightTent->CreateAnimation({ .AnimationName = "RightTent",  .ImageName = "MapRightTent.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		RightTent->CreateAnimation({ .AnimationName = "RightJumpTent",  .ImageName = "MapRightTentJump.bmp", .Start = 0, .End = 3, .InterTime = 0.2f,.Loop = true });
		RightTent->ChangeAnimation("RightJumpTent");
		RightTent->SetPosition({ 380,-250 });
	}

}

void MapEffect::Update(float _DeltaTime)
{

}

void MapEffect::Render(float _Time)
{

}
