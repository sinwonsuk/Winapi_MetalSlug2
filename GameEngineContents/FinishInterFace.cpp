#include "FinishInterFace.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"


FinishInterFace::FinishInterFace()
{
}

FinishInterFace::~FinishInterFace()
{
}

void FinishInterFace::Start()
{
	{
		M = CreateRender(MetalSlugOrder::Finish);
		M->SetImage("M.Bmp");
		M->SetPosition({ -600,0 });
		M->SetScale({ 96,96 });
		M->EffectCameraOn();
	}
	{
		I = CreateRender(MetalSlugOrder::Finish);
		I->SetImage("I.Bmp");
		I->SetPosition({ -600,0 });
		I->SetScale({ 48,96 });
		I->EffectCameraOn();
	}
	{
		S = CreateRender(MetalSlugOrder::Finish);
		S->SetImage("S.Bmp");
		S->SetPosition({ -600,0 });
		S->SetScale({ 96,96 });
		S->EffectCameraOn();
	}
	{
		S1 = CreateRender(MetalSlugOrder::Finish);
		S1->SetImage("S.Bmp");
		S1->SetPosition({ -600,0 });
		S1->SetScale({ 96,96 });
		S1->EffectCameraOn();
	}
	{
		I1 = CreateRender(MetalSlugOrder::Finish);
		I1->SetImage("I.Bmp");
		I1->SetPosition({ -600,0 });
		I1->SetScale({ 48,96 });
		I1->EffectCameraOn();
	}
	{
		O = CreateRender(MetalSlugOrder::Finish);
		O->SetImage("O.Bmp");
		O->SetPosition({ -600,0 });
		O->SetScale({ 96,96 });
		O->EffectCameraOn();
	}
	{
		N = CreateRender(MetalSlugOrder::Finish);
		N->SetImage("N.Bmp");
		N->SetPosition({ -600,0 });
		N->SetScale({ 96,96 });
		N->EffectCameraOn();
	}

	{
		C = CreateRender(MetalSlugOrder::Finish);
		C->SetImage("C.Bmp");
		C->SetPosition({ -600,0 });
		C->SetScale({ 96,96 });
		C->EffectCameraOn();
	}
	{
		O1 = CreateRender(MetalSlugOrder::Finish);
		O1->SetImage("O.Bmp");
		O1->SetPosition({ -600,0 });
		O1->SetScale({ 96,96 });
		O1->EffectCameraOn();
	}
	{
		M1 = CreateRender(MetalSlugOrder::Finish);
		M1->SetImage("M.Bmp");
		M1->SetPosition({ -600,0 });
		M1->SetScale({ 96,96 });
		M1->EffectCameraOn();
	}
	{
		P = CreateRender(MetalSlugOrder::Finish);
		P->SetImage("P.Bmp");
		P->SetPosition({ -600,0 });
		P->SetScale({ 96,96 });
		P->EffectCameraOn();
	}
	{
		L = CreateRender(MetalSlugOrder::Finish);
		L->SetImage("L.Bmp");
		L->SetPosition({ -600,0 });
		L->SetScale({ 96,96 });
		L->EffectCameraOn();
	}
	{
		E = CreateRender(MetalSlugOrder::Finish);
		E->SetImage("E.Bmp");
		E->SetPosition({ -600,0 });
		E->SetScale({ 96,96 });
		E->EffectCameraOn();
	}
	{
		T = CreateRender(MetalSlugOrder::Finish);
		T->SetImage("T.Bmp");
		T->SetPosition({ -600,0 });
		T->SetScale({ 96,96 });
		T->EffectCameraOn();
	}
	{
		E1 = CreateRender(MetalSlugOrder::Finish);
		E1->SetImage("E.Bmp");
		E1->SetPosition({ -600,0 });
		E1->SetScale({ 96,96 });
		E1->EffectCameraOn();
	}
}

void FinishInterFace::Update(float _DeltaTime)
{
	if (SoundCheck == false)
	{
		MissionComplete =GameEngineResources::GetInst().SoundPlayToControl("MissionComplete.mp3");
		MissionComplete.LoopCount(1);

		BackGround = GameEngineResources::GetInst().SoundPlayToControl("StageFinish.mp3");
		BackGround.LoopCount(1);

		SoundCheck = true;
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
			C->SetPosition({ 170,390 });
		}
		if (TimeCheck > 1.8)
		{
			O1->SetPosition({ 250,390 });
		}
		if (TimeCheck > 2)
		{
			M1->SetPosition({ 330,390 });
		}
		if (TimeCheck > 2.2)
		{
			P->SetPosition({ 410,390 });
		}
		if (TimeCheck > 2.4)
		{
			L->SetPosition({ 490,390 });
		}
		if (TimeCheck > 2.6)
		{
			E->SetPosition({ 570,390 });
		}
		if (TimeCheck > 2.8)
		{
			T->SetPosition({ 650,390 });
		}
		if (TimeCheck > 3.0)
		{
			E1->SetPosition({ 730,390 });
		}
	



		if (TimeCheck > 3.4)
		{
			
			M->Off();
			I->Off();
			S->Off();
			S1->Off();
			I1->Off();
			O->Off();
			N->Off();
			C->Off();
			O1->Off();
			M1->Off();
			P->Off();
			L->Off();
			E->Off();
			T->Off();
			E1->Off();
		}
		if (TimeCheck > 3.8)
		{
			M->On();
			I->On();
			S->On();
			S1->On();
			I1->On();
			O->On();
			N->On();
			C->On();
			O1->On();
			M1->On();
			P->On();
			L->On();
			E->On();
			T->On();
			E1->On();
		}

		if (TimeCheck > 4.2)
		{
			M->Off();
			I->Off();
			S->Off();
			S1->Off();
			I1->Off();
			O->Off();
			N->Off();
			C->Off();
			O1->Off();
			M1->Off();
			P->Off();
			L->Off();
			E->Off();
			T->Off();
			E1->Off();
		}
		if (TimeCheck > 4.6)
		{
			M->On();
			I->On();
			S->On();
			S1->On();
			I1->On();
			O->On();
			N->On();
			C->On();
			O1->On();
			M1->On();
			P->On();
			L->On();
			E->On();
			T->On();
			E1->On();
		}
		if (TimeCheck > 5.0)
		{
			M->Off();
			I->Off();
			S->Off();
			S1->Off();
			I1->Off();
			O->Off();
			N->Off();
			C->Off();
			O1->Off();
			M1->Off();
			P->Off();
			L->Off();
			E->Off();
			T->Off();
			E1->Off();
			
		}

	}
}
