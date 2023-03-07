#include "BulletEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentsEnums.h"
BulletEffect::BulletEffect()
{
}

BulletEffect::~BulletEffect()
{
}

void BulletEffect::Start()
{
	{
		AnimationRender = CreateRender(10);
		AnimationRender->SetScale({ 200,200 });
		//AnimationRenderffect->SetPosition({ 500,500 });
		AnimationRender->CreateAnimation({ .AnimationName = "Effect",  .ImageName = "BulletEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.075f,.Loop = true });
	}
	{
		BobmEffect = CreateRender(MetalSlugOrder::Boomb);		
		BobmEffect->SetScale({ 800,800 });
		BobmEffect->CreateAnimation({ .AnimationName = "BoombExploision", .ImageName = "Exploision1.bmp", .Start = 0, .End = 26, .InterTime = 0.05f });
		BobmEffect->ChangeAnimation("BoombExploision");
	}
	{
		Exploision = CreateRender(10);
		Exploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "SmallExploision.bmp", .Start = 0, .End = 24, .InterTime = 0.1f,.Loop = false });


		Exploision->SetScale({ 800,800 });
		Exploision->ChangeAnimation("Exploision");
		Exploision->Off();

	}

	BobmEffect->ChangeAnimation("BoombExploision");
	BobmEffect->Off();

	AnimationRender->ChangeAnimation("Effect");
	AnimationRender->Off(); 

	{
		Collision = CreateCollision(MetalSlugOrder::BulletEffect);
		Collision->SetScale({ 30, 30 });
	}

}

void BulletEffect::Update(float _DeltaTime)
{
	if (ExploisionCheck == true)
	{
		Exploision->On();

	


	}
	if (BoobBulletCheck == false)
	{
		AnimationRender->On();

		if (GunSound == false)
		{
			GunHit = GameEngineResources::GetInst().SoundPlayToControl("GunHit.mp3");
			GunHit.LoopCount(1);
			GunSound = true;
		}
	}

	if (BoobBulletCheck == true)
	{
		BobmEffect->On(); 
		if (boomSound == false)
		{
			BoomSound = GameEngineResources::GetInst().SoundPlayToControl("BoombSound.mp3");
			BoomSound.LoopCount(1);
			boomSound = true;
		}
	
	}

	if (AnimationRender->IsAnimationEnd())
	{
		this->Death();
	}
	
	if (BobmEffect->IsAnimationEnd())
	{
		this->Death();
	}
	if (Exploision->IsAnimationEnd())
	{
		this->Death();
	}
	
	
}

void BulletEffect::Render(float _Time)
{

}
