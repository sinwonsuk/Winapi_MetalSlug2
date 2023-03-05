#include "InterFace.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Player.h"
InterFace::InterFace()
{
}

InterFace::~InterFace()
{
}

void InterFace::Start()
{
	TestNumber.SetOwner(this);
	TestNumber.SetImage("Number.BMp", { 25, 25 }, 10, RGB(255, 255, 255), "");
	TestNumber.SetValue(Value);
	TestNumber.SetRenderPos({ 360,57 });

	TestNumber1.SetOwner(this);
	TestNumber1.SetImage("Number.BMp", { 25, 25 }, 10, RGB(255, 255, 255), "");
	TestNumber1.SetValue(Value1);
	TestNumber1.SetRenderPos({ 250,57 });
	TestNumber1.Off();


	{
		BaseBullet = CreateRender(2);
		BaseBullet->SetImage("BaseGunBullet.Bmp");
		BaseBullet->SetPosition({ 275,57 });
		BaseBullet->SetScale({ 80, 22 });
		BaseBullet->EffectCameraOff();
	}

	{
		GameEngineRender* AnimationRender = CreateRender(2);
		AnimationRender->SetImage("Score.Bmp");
		AnimationRender->SetPosition({ 110,60 });
		AnimationRender->SetScale({ 201,76 }); 
		AnimationRender->EffectCameraOff();
	}



	{
		GameEngineRender* AnimationRender = CreateRender(2);
		AnimationRender->SetImage("Bullets.Bmp");
		AnimationRender->SetPosition({ 310,45 });
		AnimationRender->SetScale({ 185,51 });
		AnimationRender->EffectCameraOff();

	}

	

	{
		GameEngineRender* AnimationRender = CreateRender(2);
		AnimationRender->SetImage("00.Bmp");
		AnimationRender->SetPosition({ 470,45 });
		AnimationRender->SetScale({ 99,66 });
		AnimationRender->EffectCameraOff();
	}

	{
		GameEngineRender* AnimationRender = CreateRender(2);
		AnimationRender->SetPosition({ 750,45 });
		AnimationRender->SetScale({ 320,67 });
		AnimationRender->CreateAnimation({ .AnimationName = "PressGame",  .ImageName = "PressStart.bmp", .Start = 0, .End = 1, .InterTime = 1.0f });
		AnimationRender->EffectCameraOff();
		AnimationRender->ChangeAnimation("PressGame");
	}

	{
		M = CreateRender(2);
		M->SetImage("M.Bmp");
		M->SetPosition({ -600,0});
		M->SetScale({ 96,96 });
		M->EffectCameraOff();
	}
	{
		I = CreateRender(2);
		I->SetImage("I.Bmp");
		I->SetPosition({ -600,0});
		I->SetScale({ 48,96 });
		I->EffectCameraOff();
	}
	{
		S = CreateRender(2);
		S->SetImage("S.Bmp");
		S->SetPosition({ -600,0 });
		S->SetScale({ 96,96 });
		S->EffectCameraOff();
	}
	{
		S1 = CreateRender(2);
		S1->SetImage("S.Bmp");
		S1->SetPosition({ -600,0 });
		S1->SetScale({ 96,96 });
		S1->EffectCameraOff();
	}
	{
		I1 = CreateRender(2);
		I1->SetImage("I.Bmp");
		I1->SetPosition({ -600,0 });
		I1->SetScale({ 48,96 });
		I1->EffectCameraOff();
	}
	{
		O = CreateRender(2);
		O->SetImage("O.Bmp");
		O->SetPosition({ -600,0 });
		O->SetScale({ 96,96 });
		O->EffectCameraOff();
	}
	{
		N = CreateRender(2);
		N->SetImage("N.Bmp");
		N->SetPosition({ -600,0 });
		N->SetScale({ 96,96 });
		N->EffectCameraOff();
	}

	{
		S2 = CreateRender(2);
		S2->SetImage("S.Bmp");
		S2->SetPosition({ -600,0 });
		S2->SetScale({ 96,96 });
		S2->EffectCameraOff();
	}
	{
		T = CreateRender(2);
		T->SetImage("T.Bmp");
		T->SetPosition({ -600,0 });
		T->SetScale({ 96,96 });
		T->EffectCameraOff();
	}
	{
		A = CreateRender(2);
		A->SetImage("A.Bmp");
		A->SetPosition({ -600,0 });
		A->SetScale({ 96,96 });
		A->EffectCameraOff();
	}
	{
		R = CreateRender(2);
		R->SetImage("R.Bmp");
		R->SetPosition({ -600,0 });
		R->SetScale({ 96,96 });
		R->EffectCameraOff();
	}
	{
		T1 = CreateRender(2);
		T1->SetImage("T.Bmp");
		T1->SetPosition({ -600,0 });
		T1->SetScale({ 96,96 });
		T1->EffectCameraOff();
	} {
		Sign = CreateRender(2);
		Sign->SetImage("!.Bmp");
		Sign->SetPosition({ -600,0 });
		Sign->SetScale({ 96,96 });
		Sign->EffectCameraOff();
	}
}

void InterFace::Update(float _DeltaTime)
{
//	Value = Player::MainPlayer->GetBombNumber();

	TestNumber.SetValue(Player::MainPlayer->GetBombNumber());
	TestNumber.SetAlign(Align::Right);

	TestNumber1.SetValue(Player::MainPlayer->GetHeavyMachineGun());
	TestNumber1.SetAlign(Align::Left);

	if (Player::MainPlayer->GetGunChange() == false)
	{
		TestNumber1.Off();
		BaseBullet->On(); 
	}

	if (Player::MainPlayer->GetGunChange() == true)
	{
		TestNumber1.On();
		BaseBullet->Off();
	}


	if (Time == false)
	{
		TimeCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (TimeCheck > 0.2)
		{			
			M->SetPosition({ 220,290 });
		}
		if (TimeCheck > 0.4)
		{
			I->SetPosition({ 300,290 });
		}
		if (TimeCheck > 0.6)
		{
			S->SetPosition({ 370,290 });
		}
		if (TimeCheck > 0.8)
		{
			S1->SetPosition({ 460,290 });
		}
		if (TimeCheck > 1)
		{
			I1->SetPosition({ 530,290 });
		}
		if (TimeCheck > 1.2)
		{
			O->SetPosition({ 600,290 });
		}
		if (TimeCheck > 1.4)
		{
			N->SetPosition({ 680,290 });
		}
		if (TimeCheck > 1.6)
		{
			S2->SetPosition({ 250,390 });
		}
		if (TimeCheck > 1.8)
		{
			T->SetPosition({ 330,390 });
		}
		if (TimeCheck > 2)
		{
			A->SetPosition({ 410,390 });
		}
		if (TimeCheck > 2.2)
		{
			R->SetPosition({ 500,390 });
		}
		if (TimeCheck > 2.4)
		{
			T1->SetPosition({ 580,390 });
		}
		if (TimeCheck > 2.6)
		{
			Sign->SetPosition({ 660,390 });	
		}
		if (TimeCheck > 2.8)
		{			
			M->SetPosition({ -60,0 });
			I->SetPosition({ -60,0 });
			S->SetPosition({ -60,0 });
			S1->SetPosition({ -60,0 });
			I1->SetPosition({ -60,0 });
			O->SetPosition({ -60,0 });
			N->SetPosition({ -60,0 });
			S2->SetPosition({ -60,0 });
			T->SetPosition({ -60,0 });
			A->SetPosition({ -60,0 });
			R->SetPosition({ -60,0 });
			T1->SetPosition({ -60,0 });
			Sign->SetPosition({ -60,0 });
		}
		if (TimeCheck > 3.2)
		{
			M->SetPosition({ 220,290 });
            I->SetPosition({ 300,290 });
            S->SetPosition({ 370,290 });
            S1->SetPosition({ 460,290 });
            I1->SetPosition({ 530,290 });
            O->SetPosition({ 600,290 });
            N->SetPosition({ 680,290 });
            S2->SetPosition({ 250,390 });
            T->SetPosition({ 330,390 });
            A->SetPosition({ 410,390 });
            R->SetPosition({ 500,390 });
            T1->SetPosition({ 580,390 });
            Sign->SetPosition({ 660,390 });
		}

		if (TimeCheck > 3.6)
		{
			M->SetPosition({ -60,0 });
			I->SetPosition({ -60,0 });
			S->SetPosition({ -60,0 });
			S1->SetPosition({ -60,0 });
			I1->SetPosition({ -60,0 });
			O->SetPosition({ -60,0 });
			N->SetPosition({ -60,0 });
			S2->SetPosition({ -60,0 });
			T->SetPosition({ -60,0 });
			A->SetPosition({ -60,0 });
			R->SetPosition({ -60,0 });
			T1->SetPosition({ -60,0 });
			Sign->SetPosition({ -60,0 });
		}
		if (TimeCheck > 4.0)
		{
			M->SetPosition({ 220,290 });
			I->SetPosition({ 300,290 });
			S->SetPosition({ 370,290 });
			S1->SetPosition({ 460,290 });
			I1->SetPosition({ 530,290 });
			O->SetPosition({ 600,290 });
			N->SetPosition({ 680,290 });
			S2->SetPosition({ 250,390 });
			T->SetPosition({ 330,390 });
			A->SetPosition({ 410,390 });
			R->SetPosition({ 500,390 });
			T1->SetPosition({ 580,390 });
			Sign->SetPosition({ 660,390 });
		}
		if (TimeCheck > 4.4)
		{
			M->SetPosition({ -60,0 });
			I->SetPosition({ -60,0 });
			S->SetPosition({ -60,0 });
			S1->SetPosition({ -60,0 });
			I1->SetPosition({ -60,0 });
			O->SetPosition({ -60,0 });
			N->SetPosition({ -60,0 });
			S2->SetPosition({ -60,0 });
			T->SetPosition({ -60,0 });
			A->SetPosition({ -60,0 });
			R->SetPosition({ -60,0 });
			T1->SetPosition({ -60,0 });
			Sign->SetPosition({ -60,0 });
			Time = true;
		}
		
	}	
}
