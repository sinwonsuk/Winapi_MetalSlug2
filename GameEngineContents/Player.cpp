#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

Player* Player::MainPlayer;

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());


	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
	}

	{
		//body
		RightSetBody({ 0,0 });
		AnimationBodyRender = CreateRender(1);
		AnimationBodyRender->SetScale({ 200, 200 });
		AnimationBodyRender->SetPosition({ body });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdlePlayer.bmp", .Start = 0, .End = 3, .InterTime = 0.2f });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "RightBodyMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "LeftIdlePlayer.bmp", .Start = 0, .End = 3, .InterTime = 0.25f });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "LeftBodyMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });

	}


	{
		//reg
		AnimationRegRender = CreateRender(0);
		AnimationRegRender->SetScale({ 200, 200 });
		AnimationRegRender->SetPosition({ Reg });

		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "RightReg.bmp", .Start = 0, .End = 0, .InterTime = 0.2f });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "RightReg.bmp", .Start = 3, .End = 15, .InterTime = 0.1f });

		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "LeftReg.bmp", .Start = 0, .End = 0, .InterTime = 0.2f });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "LeftReg.bmp", .Start = 3, .End = 15, .InterTime = 0.1f });
		
	}








	ChangeState(PlayerState::IDLE);

}

void Player::Update(float _DeltaTime) 
{
	DirCheck();
	UpdateState(_DeltaTime);
}

void Player::DirCheck()
{
	if (GameEngineInput::IsPress("LeftMove"))
	{
		LeftSetBody({ 0,0 });
		AnimationRegRender->SetPosition({ Reg });
		DirString = "Left_";
	}
	else if(GameEngineInput::IsPress("RightMove"))
	{
		RightSetBody({ 0,0 });
		AnimationRegRender->SetPosition({ Reg});
		DirString = "Right_";
	}

}

void Player::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC, 
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
		);

	
}