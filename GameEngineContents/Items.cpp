#include "Items.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Player.h"
#include "ContentsEnums.h"


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
		Boomb->SetScale({ 600,600 });
		Boomb->Off();
	}
	{
		Effect = CreateRender(MetalSlugOrder::Item);
		Effect->CreateAnimation({ .AnimationName = "Effect",  .ImageName = "ItemEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		Effect->SetScale({ 600,600 });
		Effect->Off();
	}
	{
		HeavyMachineGun = CreateRender(MetalSlugOrder::Item);
		HeavyMachineGun->SetImage("ItemHeavyGun.Bmp");
		HeavyMachineGun->SetScale({ 80,80 });
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
	


	if (Effect->IsAnimationEnd())
	{
		this->Death();
		return;
	}


	

	ItemTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (GunBoombChangeCheck == false && CollisionCheck == false)
	{
		Boomb->On();
	}
	if (GunBoombChangeCheck == true && CollisionCheck == false)
	{
		HeavyMachineGun->On();
	}

	
	if (ItemTime > 0.2)
	{

		if (nullptr != Collision && GunBoombChangeCheck == false)
		{
			
			if (true == Collision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{

				Effect->On();
				Boomb->Off();
				CollisionCheck = true;
				BoombNumber++;
				Collision->Death();
			}
		}

		if (nullptr != Collision && GunBoombChangeCheck == true)
		{
			
			if (true == Collision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{

				Effect->On();
				HeavyMachineGun->Off();
				CollisionCheck = true;
				HeavyMachineGuneNumber++;

				

				Collision->Death();

			}
		}


		if (BoombNumber == 1 && CollisionCheck == true)
		{
			Ok = GameEngineResources::GetInst().SoundPlayToControl("Ok.mp3");
			Ok.LoopCount(1);

			Player::MainPlayer->BombNumber += 10;
			BoombNumber = false;
		}
		if (HeavyMachineGuneNumber == 1 && CollisionCheck == true)
		{
			Heavymachinegun = GameEngineResources::GetInst().SoundPlayToControl("HeavyMachine.mp3");
			Heavymachinegun.LoopCount(1);

			Player::MainPlayer->HeavyMachineGun += 200;
			HeavyMachineGuneNumber = false;
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
}
void Items::Render(float _Time)
{

	//Collision->DebugRender(); 
}
