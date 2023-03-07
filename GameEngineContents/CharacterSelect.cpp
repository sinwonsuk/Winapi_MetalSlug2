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

void CharacterSelect::BackGroundSound()
{
	BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("mslug_character_select.wav");
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
		Marco->SetPosition({ 162,450 });
		Marco->SetScale({200,410});
	}

	{
		Eri = CreateRender("ColorEri.bmp", MetalSlugSelect::Select);
		//Eri->SetPosition({ 379,475 });
		Eri->SetPosition({ 0,0 });
		Eri->SetScale({ 200,410 });
	}

	{
		FinishEri = CreateRender("FinishEri.bmp", MetalSlugSelect::Select);
		//Eri->SetPosition({ 379,475 });
		FinishEri->SetPosition({ 0,0 });
		FinishEri->SetScale({ 205,410 });
	}

	{
		Tarma = CreateRender("ColorTarma.bmp", MetalSlugSelect::Select);

	//	Tarma->SetPosition({ 594,475 });
		Tarma->SetPosition({0,0 });
		Tarma->SetScale({ 200,410 });
	}

	{
		Fio = CreateRender("ColorFio.bmp", MetalSlugSelect::Select);
		Fio->SetPosition({ 0,0 });
	//	Fio->SetPosition({ 815,490 });
		Fio->SetScale({ 200,360 });
	}

	
	{
		Door1 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door1->SetPosition({ 160,480 });
		Door1->SetScale({ 200,480 });
	}

	{
		Door2 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door2->SetPosition({ 377,480 });
		Door2->SetScale({ 200,480 });
	}

	{
		Door3 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door3->SetPosition({ 591,480 });
		Door3->SetScale({ 200,480 });
	}

	{
		Door4 = CreateRender("Door.bmp", MetalSlugSelect::Door);
		Door4->SetPosition({ 814,480 });
		Door4->SetScale({ 200,480 });
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
		AnimationRender->SetPosition({  -300,190 });

		AnimationRender->SetScale({ 81,54 });

		AnimationRender->CreateAnimation({ .AnimationName = "YellowRedP1",  .ImageName = "RedYellowP1.bmp", .Start = 0, .End = 1, .InterTime = 0.5f });
	}

	


	AnimationRender->ChangeAnimation("YellowRedP1");

}

void CharacterSelect::Update(float _DeltaTime)
{
	if (BackGroundSoundCheck == false)
	{
		BackGroundSound();
		BackGroundSoundCheck = true;
	}
	

	if (P1Check == false)
	{
		P1Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	}

	if (P1Time > 0.5 && DoorCheck == false)
	{
		Door1->SetMove(MoveDir * _DeltaTime);
		Door2->SetMove(MoveDir2 * _DeltaTime);
		Door3->SetMove(MoveDir3 * _DeltaTime);
		Door4->SetMove(MoveDir4 * _DeltaTime);
	}
	
	
	
	if (P1Time > 2.0)
	{
		if (Door1->GetPosition().y < 25)
		{
			AnimationRender->SetPosition({ 155,190 });
			P1Check = true;
			P1Time = 0;
		}
		DoorCheck = true;	
	}

	if (true == GameEngineInput::IsDown("SelectLeft") && DoorCheck == true)
	{
		cursor = GameEngineResources::GetInst().SoundPlayToControl("cursor.wav");
		cursor.LoopCount(1);

		if (Fio->GetPosition().x != 0)
		{
			if (Fio->GetPosition().y != 0)
			{
				
				AnimationRender->SetPosition({ 583,190 });
				Fio->SetPosition({ 0,0 });
				Tarma->SetPosition({ 594,450 });
			}
		}


		else if (Tarma->GetPosition().x != 0)
		{
			if (Tarma->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 367,190 });
				Tarma->SetPosition({ 0,0 });
				Eri->SetPosition({ 379,450 });
			}
		}

		else if (Eri->GetPosition().x != 0)
		{
			if (Eri->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 155,190 });
				Eri->SetPosition({ 0,0 });
				Marco->SetPosition({ 162,450 });

			}
		}


	}
	if (true == GameEngineInput::IsDown("SelectRight") && DoorCheck == true )
	{
		cursor = GameEngineResources::GetInst().SoundPlayToControl("cursor.wav");
		cursor.LoopCount(1);
		if (Marco->GetPosition().x != 0)
		{
			if (Marco->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 367,190 });
				Marco->SetPosition({ 0,0 });
				Eri->SetPosition({ 379,450 });
				
			}
		}

		else if (Eri->GetPosition().x != 0)
		{
			if (Eri->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 583,190 });
				Eri->SetPosition({ 0,0 });
				Tarma->SetPosition({ 594,450 });
			}
		}

		else if (Tarma->GetPosition().x != 0)
		{
			if (Tarma->GetPosition().y != 0)
			{
				AnimationRender->SetPosition({ 798,190 });
				Tarma->SetPosition({ 0,0 });
				Fio->SetPosition({ 815,470 });
			
			}
		}

	}
	if (true == GameEngineInput::IsDown("SelectChoice") && Eri->GetPosition().y != 0 && DoorCheck == true )
	{
		CharacterSelectSound = GameEngineResources::GetInst().SoundPlayToControl("mslug_eri.wav");
		CharacterSelectSound.LoopCount(1);
		Eri->SetPosition({ 0,0 });
		FinishEri->SetPosition({ 372,450 });
		

		EnterCheck = true; 
	}

	if (EnterCheck == true)
	{
		ChoiceTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		if (ChoiceTime > 0.4)
		{
			FinishDoor->SetMove({MoveDir5 *_DeltaTime});
		}
		
	}

	if (FinishDoor->GetPosition().y > 460)
	{
		FinishTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
     	EnterCheck = false;

		if (FinishTime > 2.0)
		{
			BGMPlayer.PauseOn();
        	GameEngineCore::GetInst()->ChangeLevel("PlayLevel");
		}
	}
}
