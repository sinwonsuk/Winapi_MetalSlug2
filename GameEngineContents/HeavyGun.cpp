#include "HeavyGun.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Player.h"
#include "ContentsEnums.h"
#include <math.h>

HeavyGun::HeavyGun()
{


}

HeavyGun::~HeavyGun()
{


}

void HeavyGun::Start()
{
	{
		RightHeavyBullet = CreateRender(10);
		RightHeavyBullet->SetImage("RightHeavyBullet.Bmp");
		RightHeavyBullet->SetScale({150,150 });
		RightHeavyBullet->Off(); 
	}

	{
		RightUpHeavyBullet = CreateRender(10);
		RightUpHeavyBullet->SetImage("RightUpHeavyBullet1.Bmp");
		RightUpHeavyBullet->SetScale({ 130,130 });
		RightUpHeavyBullet->Off();
	}

	{
		RightUpHeavyBullet1 = CreateRender(10);
		RightUpHeavyBullet1->SetImage("RightUpHeavyBullet2.Bmp");
		RightUpHeavyBullet1->SetScale({ 130,130 });
		RightUpHeavyBullet1->Off();
	}

	{
		RightUpHeavyBullet2 = CreateRender(10);
		RightUpHeavyBullet2->SetImage("RightUpHeavyBullet3.Bmp");
		RightUpHeavyBullet2->SetScale({ 130,130 });
		RightUpHeavyBullet2->Off();
	}

	{
		RightUpHeavyBullet3 = CreateRender(10);
		RightUpHeavyBullet3->SetImage("RightUpHeavyBullet4.Bmp");
		RightUpHeavyBullet3->SetScale({ 130,130 });
		RightUpHeavyBullet3->Off();
	}

	{
		RightUpHeavyBullet4 = CreateRender(10);
		RightUpHeavyBullet4->SetImage("RightUpHeavyBullet5.Bmp");
		RightUpHeavyBullet4->SetScale({ 130,130 });
		RightUpHeavyBullet4->Off();
	}
	
	{
		UpHeavyBullet = CreateRender(10);
		UpHeavyBullet->SetImage("UpHeavyBullet.Bmp");
		UpHeavyBullet->SetScale({ 120,120 });
		UpHeavyBullet->Off();
	}





	{
		LeftHeavyBullet = CreateRender(10);
		LeftHeavyBullet->SetImage("LeftHeavyBullet.Bmp");
		LeftHeavyBullet->SetScale({ 150,150 });
		LeftHeavyBullet->Off();
	}

	{
		LeftUpHeavyBullet = CreateRender(10);
		LeftUpHeavyBullet->SetImage("LeftUpHeavyBullet1.Bmp");
		LeftUpHeavyBullet->SetScale({ 130,130 });
		LeftUpHeavyBullet->Off();
	}

	{
		LeftUpHeavyBullet1 = CreateRender(10);
		LeftUpHeavyBullet1->SetImage("LeftUpHeavyBullet2.Bmp");
		LeftUpHeavyBullet1->SetScale({ 130,130 });
		LeftUpHeavyBullet1->Off();
	}

	{
		LeftUpHeavyBullet2 = CreateRender(10);
		LeftUpHeavyBullet2->SetImage("LeftUpHeavyBullet3.Bmp");
		LeftUpHeavyBullet2->SetScale({ 130,130 });
		LeftUpHeavyBullet2->Off();
	}

	{
		LeftUpHeavyBullet3 = CreateRender(10);
		LeftUpHeavyBullet3->SetImage("LeftUpHeavyBullet4.Bmp");
		LeftUpHeavyBullet3->SetScale({ 130,130 });
		LeftUpHeavyBullet3->Off();
	}


	{
		LeftUpHeavyBullet4 = CreateRender(10);
		LeftUpHeavyBullet4->SetImage("LeftUpHeavyBullet5.Bmp");
		LeftUpHeavyBullet4->SetScale({ 130,130 });
		LeftUpHeavyBullet4->Off();
	}





	{
		Collision = CreateCollision(MetalSlugOrder::Bullet);
		Collision->SetScale({ 100, 100 });
	}




}

void HeavyGun::Update(float _DeltaTime)
{
	

	

	DeathCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	
	/*if (DeathCheck > 0.46)
	{
		this->Death(); 
	}*/

		switch (Dir)
		{
		case Direction::Left:
			LeftHeavyBullet->On(); 
			DirTime = 0.6;
			break;
		case Direction::Right:
			RightHeavyBullet->On(); 
			DirTime = 0.6;
		
			break;
		case Direction::Down:
			
		
			break;
		case Direction::Up:
			UpHeavyBullet->On();
			DirTime = 0.6;
			break;
		case Direction::A:
			RightUpHeavyBullet->On(); 
			DirTime = 0.75;
			break;
		case Direction::B:
			RightUpHeavyBullet1->On();
			DirTime = 0.95;
			break;
		case Direction::C:
			RightUpHeavyBullet3->On();
			DirTime = 0.9;
			break;
		case Direction::D:
			RightUpHeavyBullet4->On();
			DirTime = 0.9;
			break;
		case Direction::LeftA:
			LeftUpHeavyBullet->On();

			break;
		case Direction::LeftB:
			LeftUpHeavyBullet1->On();

			break;
		case Direction::LeftC:
			LeftUpHeavyBullet3->On();

			break;
		case Direction::LeftD:
			LeftUpHeavyBullet4->On();


			break;


		default:
			break;
		}
		DeathCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (DeathCheck > DirTime)
		{
			this->Death();
		}
		SetMove(MoveDir * _DeltaTime * Speed);
}

void HeavyGun::Render(float _Time)
{


}
