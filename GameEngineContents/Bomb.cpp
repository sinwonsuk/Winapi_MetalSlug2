#include "Bomb.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
Bomb::Bomb()
{

}

Bomb::~Bomb()
{
}

void Bomb::Start()
{
	{
		BoombRender = CreateRender(MetalSlugOrder::Boomb);
		//BoombRender->SetPosition({ 0,-200 });
		BoombRender->SetScale({ 500,500 });
		BoombRender->CreateAnimation({ .AnimationName = "Boomb", .ImageName = "Boom.bmp", .Start = 0, .End = 15, .InterTime = 0.1f });
		BoombRender->CreateAnimation({ .AnimationName = "BoombExploision", .ImageName = "Exploision1.bmp", .Start = 0, .End = 26, .InterTime = 0.05f });
		//BoombRender->CreateAnimation({ .AnimationName = "Stop", .ImageName = "MonsterNife.bmp", .Start = 11, .End = 11, .InterTime = 0.1f });
		//BoombRender->EffectCameraOff();
		BoombRender->ChangeAnimation("Boomb");
	}
	{
		Collision = CreateCollision(MetalSlugOrder::Boomb);
		Collision->SetScale({ 30, 30 });
	}
}

void Bomb::Update(float _DeltaTime)
{
	if (BoomDeath == false)
	{

		MoveDir += float4::Down * 3000.0f * _DeltaTime;


		if (DirCheck == false)
		{
			MoveDir += float4::Left * 500;
		}
		if (DirCheck == true)
		{
			MoveDir += float4::Right * 500;
		}

		if (MoveCheck == false)
		{
			if (500.0f <= abs(MoveDir.x))
			{
				if (0 > MoveDir.x)
				{
					MoveDir.x = -450.0f;
				}
				else
				{
					MoveDir.x = 450.0f;
				}
			}
		}
		if (MoveCheck == true)
		{
			if (500.0f <= abs(MoveDir.x))
			{
				if (0 > MoveDir.x)
				{
					MoveDir.x = -550.0f;
				}
				else
				{
					MoveDir.x = 550.0f;
				}
			}

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
		++GroundCheck;

		//BoombRender->ChangeAnimation("Boomb");
		Check = false;
		MoveDir = { 0,0 };
		MoveDir += float4::Up * 700;
	}
	if (GroundCheck == 2)
	{
		MoveDir = { 0,0 };
		BoomDeath = true;
		BoombRender->SetScale({ 750,750 });
		BoombRender->ChangeAnimation("BoombExploision");
		
		if (true == BoombRender->IsAnimationEnd())
		{
			this->Death(); 
		}

	}


	SetMove(MoveDir * _DeltaTime);
}

void Bomb::Render(float _Time)
{

}
