#include "Bullets.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Player.h"
#include "ContentsEnums.h"
#include "Monster.h"
Bullets::Bullets()
{
}

Bullets::~Bullets()
{
}

void Bullets::Start()
{



	{
		AnimationRender = CreateRender(MetalSlugOrder::Bullet);
		AnimationRender->SetImage("Bullet.Bmp");
		//AnimationRender->SetPosition({500,500 });
		AnimationRender->SetScale({ 48,48 });
		AnimationRender->On();


	}
	
	{
		Collision = CreateCollision(MetalSlugOrder::Bullet);
		Collision->SetScale({ 30, 30 });
	}
}

void Bullets::Update(float _DeltaTime)
{	
	

	DeathCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (DeathCheck >0.4)
	{
		this->Death();
	}

	SetMove(MoveDir * _DeltaTime * 1500);
}

void Bullets::Render(float _Time)
{

}
