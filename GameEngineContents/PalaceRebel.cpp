#include "PalaceRebel.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
PalaceRebel::PalaceRebel()
{
}

PalaceRebel::~PalaceRebel()
{
}

void PalaceRebel::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::Monster);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "PalaceRebel.bmp", .Start = 0, .End = 13, .InterTime = 0.1f,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Down",  .ImageName = "PalaceRebel.bmp", .Start = 14, .End = 16, .InterTime = 0.1f ,.Loop = false });
	
	}

	AnimationRender->ChangeAnimation("Idle"); 


}

void PalaceRebel::Update(float _DeltaTime)
{


	MoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (50.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -200.0f;
		}
		else
		{
			MoveDir.x = 200.0f;
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
		AnimationRender->ChangeAnimation("Down");
		MoveDir.y = 0;
		Check = false;
	}



	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))
			{

				Check = false;
			}


			if (50.0f <= abs(MoveDir.y))
			{
				if (0 > MoveDir.y)
				{
					MoveDir.y = -100.0f;
				}
				else
				{
					MoveDir.y = 0.0f;
				}
			}
			Check = true;
			break;
		}
	}

	DeathTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (DeathTime > 2)
	{
		this->Death();
	}


	SetMove(MoveDir * _DeltaTime);
}

void PalaceRebel::Render(float _Time)
{

}
