#include "PalaceBullet.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MiddleBoss.h"
#include "Player.h"
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

	/*{
		BulletRender = CreateRender(10);
		BulletRender->CreateAnimation({ .AnimationName = "Bullet",  .ImageName = "PalaceMissileIdle.bmp", .Start = 0, .End = 19, .InterTime = 0.1f,.Loop = true });
		BulletRender->SetScale({ 600,600 });
		BulletRender->ChangeAnimation("Bullet");
	}*/





}

void PalaceBullet::Update(float _DeltaTime)
{

	//LeftTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	//if (LeftTime < 0.4)
	//{
	//	Check = 1;
	//}
	//if (LeftTime > 0.4)
	//{
	//	if (LeftTime < 0.8)
	//	{
	//		Check = 2;
	//		
	//	}
	//	

	//}
	//if (LeftTime > 0.8)
	//{
	//	LeftTime = 0;
	//}
	



	//MoveDir.AngleToDirection2DToDeg(_DeltaTime)



	/*LeftMoveDir = float4{ Player::MainPlayer->GetPos().x - 100,Player::MainPlayer->GetPos().y  } - GetPos();

	RightMoveDir = float4{ Player::MainPlayer->GetPos().x + 100,Player::MainPlayer->GetPos().y } - GetPos();


	switch (Check)
	{
	case 1:
	{
		MoveDir = LeftMoveDir;
		break;
	}
	case 2:
	{
		MoveDir = RightMoveDir;
		break;
	}
	default:
		break;
	}*/

	Time += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 

	if (Time < 1)
	{
		MoveDir = float4::Right;
		//BulletRender->SetMove({ 0,-10 });
		BulletRender->ChangeAnimation("IdleBullet");
		
	}

	if (Time > 1)
	{

		//MoveDir.AngleToDirection2DToDeg(-a);
		if (sds == false)
		{
			MoveDir = float4::AngleToDirection2DToDeg(a++);

			float d = MoveDir.GetAnagleDeg();

			MoveDir1 = float4{ Player::MainPlayer->GetPos().x,Player::MainPlayer->GetPos().y } - GetPos();
			float f = MoveDir1.GetAnagleDeg();

		}
		if (MoveDir1.GetAnagleDeg() > MoveDir.GetAnagleDeg())
		{
			

			MoveDir = float4{ Player::MainPlayer->GetPos().x,Player::MainPlayer->GetPos().y } - GetPos();
			sds = true;
		}



		//float a = MoveDir.GetAnagleDeg() - 1;
	}

	if(sds == true)
	{
		MoveDir = float4{ Player::MainPlayer->GetPos().x,Player::MainPlayer->GetPos().y } - GetPos();
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


		


		// MoveDir =  Player::MainPlayer->GetPos() - GetPos(); 




		MoveDir.Normalize();
		SetMove(MoveDir * _DeltaTime * 50);




	
}

void PalaceBullet::Render()
{
	
}
