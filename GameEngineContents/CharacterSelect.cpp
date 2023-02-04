#include "CharacterSelect.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineCore/GameEngineCore.h>
CharacterSelect::CharacterSelect()
{
}

CharacterSelect::~CharacterSelect()
{
}

void CharacterSelect::Start()
{
	

	if (false == GameEngineInput::IsKey("SelectLeft"))
	{
		GameEngineInput::CreateKey("SelectLeft", VK_LEFT);
		GameEngineInput::CreateKey("SelectRight", VK_RIGHT);
		GameEngineInput::CreateKey("SelectChoice", VK_RETURN);
	}



	float4 Size = GameEngineWindow::GetScreenSize();

	{
		BackGround = CreateRender("SelectBackGround.bmp", MetalSlugSelect::BackGround);
		BackGround->SetPosition(GameEngineWindow::GetScreenSize().half());
		BackGround->SetScale(GameEngineWindow::GetScreenSize());
	}

	{
		Marco = CreateRender("ColorMarco.bmp", MetalSlugSelect::Select);
		Marco->SetPosition({164,475});
		Marco->SetScale({200,430});
	}

	{
		Eri = CreateRender("ColorEri.bmp", MetalSlugSelect::Select);
		//Eri->SetPosition({ 379,475 });
		Eri->SetPosition({ 0,0 });
		Eri->SetScale({ 200,430 });
	}

	{
		FinishEri = CreateRender("FinishEri.bmp", MetalSlugSelect::Select);
		//Eri->SetPosition({ 379,475 });
		FinishEri->SetPosition({ 0,0 });
		FinishEri->SetScale({ 205,430 });
	}

	{
		Tarma = CreateRender("ColorTarma.bmp", MetalSlugSelect::Select);

	//	Tarma->SetPosition({ 594,475 });
		Tarma->SetPosition({0,0 });
		Tarma->SetScale({ 200,430 });
	}

	{
		Fio = CreateRender("ColorFio.bmp", MetalSlugSelect::Select);
		Fio->SetPosition({ 0,0 });
	//	Fio->SetPosition({ 815,490 });
		Fio->SetScale({ 200,380 });
	}

	
	{
		Door1 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door1->SetPosition({ 160,480 });
		Door1->SetScale({ 200,440 });
	}

	{
		Door2 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door2->SetPosition({ 377,480 });
		Door2->SetScale({ 200,440 });
	}

	{
		Door3 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door3->SetPosition({ 591,480 });
		Door3->SetScale({ 200,440 });
	}

	{
		Door4 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door4->SetPosition({ 814,480 });
		Door4->SetScale({ 200,440 });
	}

	{
		FinishDoor = CreateRender("FinishDoor.bmp", MetalSlugSelect::Door);
		FinishDoor->SetPosition({ 377,25 });
		FinishDoor->SetScale({ 200,440 });
	}

	{
		GameEngineRender* Render = CreateRender("1234.bmp", MetalSlugSelect::FrontBackGround);
		
		Render->SetPosition(GameEngineWindow::GetScreenSize().half());
		Render->SetScale(GameEngineWindow::GetScreenSize());
	}

	
	
	{
		AnimationRender = CreateRender(MetalSlugSelect::YellowRedP1);
		AnimationRender->SetPosition({  -300,200 });

		AnimationRender->SetScale({ 81,54 });

		AnimationRender->CreateAnimation({ .AnimationName = "YellowRedP1",  .ImageName = "RedYellowP1.bmp", .Start = 0, .End = 1, .InterTime = 0.5f });
	}

	


	AnimationRender->ChangeAnimation("YellowRedP1");

}

void CharacterSelect::Update(float _DeltaTime)
{
	if (P1Check == false)
	{
		P1Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	}

	if (P1Time > 0.5 && DoorCheck == false)
	{

		Door1->SetMove({ 0,-2.4 });
		Door2->SetMove({ 0,-2.8 });
		Door3->SetMove({ 0,-3.0 });
		Door4->SetMove({ 0,-2.5 });

	}
	
		
	if (P1Time > 1.6)
	{
		if (Door1->GetPosition().y < 25)
		{
			AnimationRender->SetPosition({ 155,200 });
			P1Check = true;
			P1Time = 0;
		}
		DoorCheck = true;	
	}

	if (true == GameEngineInput::IsDown("SelectLeft") )
	{
		
		if (Fio->GetPosition().x != 0)
		{
			if (Fio->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 583,200 });
				Fio->SetPosition({ 0,0 });
				Tarma->SetPosition({ 594,475 });
			}
		}


		else if (Tarma->GetPosition().x != 0)
		{
			if (Tarma->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 367,200 });
				Tarma->SetPosition({ 0,0 });
				Eri->SetPosition({ 379,475 });
			}
		}

		else if (Eri->GetPosition().x != 0)
		{
			if (Eri->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 155,200 });
				Eri->SetPosition({ 0,0 });
				Marco->SetPosition({ 164,475 });

			}
		}


	}
	if (true == GameEngineInput::IsDown("SelectRight"))
	{
		if (Marco->GetPosition().x != 0)
		{
			if (Marco->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 367,200 });
				Marco->SetPosition({ 0,0 });
				Eri->SetPosition({ 379,475 });
				
			}
		}

		else if (Eri->GetPosition().x != 0)
		{
			if (Eri->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 583,200 });
				Eri->SetPosition({ 0,0 });
				Tarma->SetPosition({ 594,475 });
			}
		}

		else if (Tarma->GetPosition().x != 0)
		{
			if (Tarma->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 798,200 });
				Tarma->SetPosition({ 0,0 });
				Fio->SetPosition({ 815,495 });
			
			}
		}

	}
	if (true == GameEngineInput::IsDown("SelectChoice") && Eri->GetPosition().y != 0)
	{
		
		Eri->SetPosition({ 0,0 });
		FinishEri->SetPosition({ 372,475 });
		EnterCheck = true; 
	}

	if (EnterCheck == true)
	{
		ChoiceTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		if (ChoiceTime > 0.4)
		{
			FinishDoor->SetMove({ 0,3 });
		}
		
	}

	if (FinishDoor->GetPosition().y > 480)
	{
		FinishTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
     	EnterCheck = false;

		if (FinishTime > 2.0)
		{
        	GameEngineCore::GetInst()->ChangeLevel("PlayLevel");
		}
	}
}
