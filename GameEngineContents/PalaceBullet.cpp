#include "PalaceBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineCore/GameEngineResources.h>
#include "MiddleBoss.h"
#include "Player.h"
#include "BulletEffect.h"
PalaceBullet::PalaceBullet()
{
}

PalaceBullet::~PalaceBullet()
{
}

void PalaceBullet::Start()
{
	{
		BulletRender = CreateRender(10);
		BulletRender->CreateAnimation({ .AnimationName = "IdleBullet",  .ImageName = "PalaceMissileIdle.bmp", .Start = 0, .End = 19, .InterTime = 0.1f,.Loop = true ,.FrameIndex{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		BulletRender->CreateAnimation({ .AnimationName = "RightBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 0, .End = 1, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "RightABullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 2, .End = 3, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "RightBBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 4, .End = 5, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "RightCBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 6, .End = 7, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "DownBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 8, .End = 9, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "LeftBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 16, .End = 17, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "LeftABullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 14, .End = 15, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "LeftBBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 12, .End = 13, .InterTime = 0.1f,.Loop = true });
		BulletRender->CreateAnimation({ .AnimationName = "LeftCBullet",  .ImageName = "PalaceMissileMove.bmp", .Start = 10, .End = 11, .InterTime = 0.1f,.Loop = true });
	
		
		BulletRender->SetScale({ 500,500 });
		BulletRender->ChangeAnimation("IdleBullet");
	}
	{
		Exploision = CreateRender(10);
		Exploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "SmallExploision.bmp", .Start = 0, .End = 26, .InterTime = 0.1f,.Loop = false });


		Exploision->SetScale({ 800,800 });
		Exploision->ChangeAnimation("Exploision");
		Exploision->Off(); 

	}
	{
		CollisionBullet = CreateCollision(MetalSlugOrder::PalaceBullet);
		CollisionBullet->SetPosition({ 0,0, });
		CollisionBullet->SetScale({ 100,100 });
	}
	
	




}

void PalaceBullet::Update(float _DeltaTime)
{
	 
	if (nullptr != CollisionBullet)
	{

		std::vector<GameEngineCollision*> collision;
		if (true == CollisionBullet->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();			
				ColActor->Death();	
			}


			BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
			Effect->SetMove(GetPos());
			Effect->ExploisionCheck = true;
			this->Death();	   
		}
	}
	
	
	



	
		Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (Time < 1)
		{
			MoveDir = float4::Right;
			BulletRender->ChangeAnimation("IdleBullet");
		}

		if (Time > 1)
		{
			if (sds == false)
			{
				MoveDir = float4::AngleToDirection2DToDeg(a++);
				MoveDir1 = float4{ Player::MainPlayer->GetPos().x,Player::MainPlayer->GetPos().y } - GetPos();

				if (MoveDir1.GetAnagleDeg() > MoveDir.GetAnagleDeg())
				{
					MoveDir = float4{ Player::MainPlayer->GetPos().x,Player::MainPlayer->GetPos().y } - GetPos();
					MoveDir1 = float4{ Player::MainPlayer->GetPos().x - 100,Player::MainPlayer->GetPos().y } - GetPos();
					MoveDir2 = float4{ Player::MainPlayer->GetPos().x + 100,Player::MainPlayer->GetPos().y } - GetPos();
					sds = true;
					d = a;
				}
			}
		}

		


			LeftTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();




			if (LeftTime <= 0.2)
			{
				MoveDir = float4::AngleToDirection2DToDeg(a);
			}
			if (LeftTime > 0.2)
			{
				if (LeftTime <= 0.4)
				{
					MoveDir = float4::AngleToDirection2DToDeg(a - 20);
				}


			}

			if (LeftTime > 0.4)
			{
				if (LeftTime <= 0.6)
				{
					MoveDir = float4::AngleToDirection2DToDeg(a);
				}

			}
			if (LeftTime > 0.6)
			{
				if (LeftTime <= 0.8)
				{
					MoveDir = float4::AngleToDirection2DToDeg(a + 20);
				}

				if (LeftTime > 0.8)
				{
					LeftTime = 0;
				}
			}


		if (MoveDir.GetAnagleDeg() < 360)
	{
		if (MoveDir.GetAnagleDeg() > 340)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("RightBullet");
		}
	}
	if (MoveDir.GetAnagleDeg() < 340)
	{
		if (MoveDir.GetAnagleDeg() > 320)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("RightABullet");
		}
	}
	if (MoveDir.GetAnagleDeg() < 320)
	{
		if (MoveDir.GetAnagleDeg() > 300)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("RightBBullet");
		}
	}
	if (MoveDir.GetAnagleDeg() < 300)
	{
		if (MoveDir.GetAnagleDeg() > 280)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("RightCBullet");
		}
	}
	if (MoveDir.GetAnagleDeg() < 280)
	{
		if (MoveDir.GetAnagleDeg() > 260)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("DownBullet");
		}

	}

	if (MoveDir.GetAnagleDeg() < 260)
	{
		if (MoveDir.GetAnagleDeg() > 240)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("LeftCBullet");
		}
	}

	if (MoveDir.GetAnagleDeg() < 240)
	{
		if (MoveDir.GetAnagleDeg() > 220)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("LeftBBullet");
		}
	}


	if (MoveDir.GetAnagleDeg() < 220)
	{
		if (MoveDir.GetAnagleDeg() > 200)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("LeftABullet");
		}
	}

	if (MoveDir.GetAnagleDeg() < 200)
	{
		if (MoveDir.GetAnagleDeg() > 180)
		{
			BulletRender->SetScale({ 600,600 });
			BulletRender->ChangeAnimation("LeftBullet");
		}
	}

		float4 NextPos = GetPos() + MoveDir * _DeltaTime;

		GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

		if (MiddleBoss::middleBoss->LeftHp <= 0 && MiddleBoss::middleBoss->RightHp <= 0 && MiddleBoss::middleBoss->MiddleHp <= 0)
		{
			Exploision->On();
			BulletRender->Off();
			SetMove(-MoveDir * _DeltaTime * 100);
		}

		if (Exploision->IsAnimationEnd())
		{
			this->Death(); 
		}
		if (Player::MainPlayer->GetPos().y < GetPos().y)
		{
			Exploision->On();
			BulletRender->Off();
			SetMove(-MoveDir * _DeltaTime * 100);
		}

		MoveDir.Normalize();
		SetMove(MoveDir * _DeltaTime * 100);




	
}

void PalaceBullet::Render(float _Time)
{
	//CollisionBullet->DebugRender();
}
