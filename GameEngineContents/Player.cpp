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
	MainPlayer = this;

	SetMove(GameEngineWindow::GetScreenSize().half());


	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
	}

	{
		AnimationRender = CreateRender(BubbleRenderOrder::BackGround);
		AnimationRender->SetScale({ 256, 256 });
		AnimationRender->SetTransColor(RGB(0, 0, 255));

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Right_Player.bmp", .Start = 0, .End = 2, .InterTime = 0.3f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Right_Player.bmp", .Start = 3, .End = 7 });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Left_Player.bmp", .Start = 0, .End = 2, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Left_Player.bmp", .Start = 3, .End = 7 });
	}


	ChangeState(PlayerState::IDLE);
	// Render->SetPosition({0.0f, -100.0f});

	// CreateRender("PlayerCharacter.Bmp");

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
		DirString = "Left_";
	}
	else if(GameEngineInput::IsPress("RightMove"))
	{
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

	// µð¹ö±ë¿ë.
}