#include "Items.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Player.h"


Items::Items()
{
}

Items::~Items()
{
}

void Items::Start()
{
	{
		Boomb = CreateRender(MetalSlugOrder::Item);
		Boomb->CreateAnimation({ .AnimationName = "Boomb",  .ImageName = "ItemBoomb.bmp", .Start = 0, .End = 5, .InterTime = 0.15f , .Loop = true });
		Boomb->SetScale({ 800,800 });
		Boomb->Off();
	}
	{
		Effect = CreateRender(MetalSlugOrder::Item);
		Effect->CreateAnimation({ .AnimationName = "Effect",  .ImageName = "ItemEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		Effect->SetScale({ 800,800 });
		Effect->Off();
	}
	{
		HeavyMachineGun = CreateRender(MetalSlugOrder::Item);
		HeavyMachineGun->SetImage("ItemHeavyGun.Bmp");
		HeavyMachineGun->SetScale({ 70,70 });
		HeavyMachineGun->SetPosition({ 0,-30 });
		HeavyMachineGun->Off();
	}

	{
		Collision = CreateCollision(MetalSlugOrder::Item);
		Collision->SetScale({ 50, 50 });
	}

	Boomb->ChangeAnimation("Boomb");
	Effect->ChangeAnimation("Effect");



}

void Items::Update(float _DeltaTime)
{
	if (GunBoombChangeCheck == false && CollisionCheck == false)
	{
		Boomb->On();
	}
	if (GunBoombChangeCheck == true && CollisionCheck == false)
	{
		HeavyMachineGun->On();
	}




	if (nullptr != Collision && GunBoombChangeCheck == false)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == Collision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			
			Effect->On(); 
			Boomb->Off(); 
			CollisionCheck = true; 
		
		}
	}

	if (nullptr != Collision && GunBoombChangeCheck == true)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == Collision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			Effect->On();
			HeavyMachineGun->Off();
			CollisionCheck = true;
		}
	}
	
	
	
	
	
	if (Effect->IsAnimationEnd())
	{
		if (GunBoombChangeCheck == false)
		{
			Player::MainPlayer->BombNumber += 10;
		}
		if (GunBoombChangeCheck == true)
		{
			Player::MainPlayer->HeavyMachineGun += 20;
		}
		this->Death(); 
		
	}





	MoveDir += float4::Down * 3500.0f * _DeltaTime;

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




	if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))) || ((RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)))))
	{

		Check = false;
	}



	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if (((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))) || ((RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)))))
			{
				continue;
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

	SetMove(MoveDir * _DeltaTime);

}
void Items::Render(float _Time)
{

	//Collision->DebugRender(); 
}
