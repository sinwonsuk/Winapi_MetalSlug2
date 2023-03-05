#include "WinPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"




WinPlayer::WinPlayer()
{
}

WinPlayer::~WinPlayer()
{
}

void WinPlayer::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "PlayerWin.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		AnimationRender->ChangeAnimation("Idle"); 
	}


}

void WinPlayer::Update(float _DeltaTime)
{

}

void WinPlayer::Render(float _Time)
{
}
