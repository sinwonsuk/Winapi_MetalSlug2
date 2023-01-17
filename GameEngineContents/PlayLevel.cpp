#include "PlayLevel.h"
#include "Player.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading() 
{
	// ����� Ž��
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// �̹��� �ε�
	{
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Player.BMP"));
			Image->Cut(5, 17);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Player.BMP"));
			Image->Cut(5, 17);
		}
	}

	// ���� ����
	CreateActor<Player>();

	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
	}
}

void PlayLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Player::MainPlayer->OnOffSwtich();
		// Player::MainPlayer->Death()p;
	}
}

