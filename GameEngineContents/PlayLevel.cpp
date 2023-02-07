
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>


#include "PlayLevel.h"
#include "Player.h"
#include "Map.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading() 
{
	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	{

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBodyMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdlePlayer.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightReg.BMP"));
			Image->Cut(5, 4);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBodyMove.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftIdlePlayer.BMP"));
			Image->Cut(5, 1);
		}


		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftReg.BMP"));
			Image->Cut(5, 4);
		}
		
		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map12.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map11.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightJumpReg.BMP"));
			Image->Cut(5, 3);
		}

		

		{
			GameEngineImage * Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightIdleJumpBody.BMP"));
			Image->Cut(6, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftIdleJumpBody.BMP"));
			Image->Cut(6, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftJumpReg.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftJumpBody.BMP"));
			Image->Cut(6, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightJumpBody.BMP"));
			Image->Cut(6, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightUp.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftUp.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightDown.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftDown.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightUpAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftUpAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightThrow.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftThrow.BMP"));
			Image->Cut(5, 2);
		}

	}

	// 액터 생성
	{
		CreateActor<Player>();
	}

	{
		CreateActor<Map>();
	}

	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
	}
	if (false == GameEngineInput::IsKey("CameraLeftMove"))
	{
		// VK 알파뱃과 숫자를 제외한 키를 표현하는데 쓰고 있다. 
		GameEngineInput::CreateKey("CameraLeftMove", VK_LEFT);
		GameEngineInput::CreateKey("CameraRightMove", VK_RIGHT);
		GameEngineInput::CreateKey("CameraDownMove", VK_DOWN);
		GameEngineInput::CreateKey("CameraUpMove", VK_UP);
	}

}

void PlayLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Player::MainPlayer->OnOffSwtich();
		// Player::MainPlayer->Death()p;
	}

	float CameraMoveSpeed = 400.0f;

	//if (GameEngineInput::IsPress("CameraLeftMove"))
	//{
	//	SetCameraMove(float4::Left * _DeltaTime * CameraMoveSpeed);
	//}
	//if (GameEngineInput::IsPress("CameraRightMove"))
	//{
	//	SetCameraMove(float4::Right * _DeltaTime * CameraMoveSpeed);
	//}
	//if (GameEngineInput::IsPress("CameraDownMove"))
	//{
	//	SetCameraMove(float4::Down * _DeltaTime * CameraMoveSpeed);
	//}
	//if (GameEngineInput::IsPress("CameraUpMove"))
	//{
	//	SetCameraMove(float4::Up * _DeltaTime * CameraMoveSpeed);
	//}
}

