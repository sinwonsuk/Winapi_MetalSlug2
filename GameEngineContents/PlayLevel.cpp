
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

#include "PlayLevel.h"
#include "Player.h"
#include "Map.h"
#include "InterFace.h"
#include "Bullets.h"
#include "Monster.h"
#include "MonsterBullet.h"
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
		


		// 맵 
		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map12.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map11.BMP"));
		}
	
		
		//캐릭터 모션 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightJumpReg.BMP"));
			Image->Cut(5, 3);
		}


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


	     //인터페이스 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bullets.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Score.BMP"));
		}		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PressStart.BMP"));
			Image->Cut(2, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("00.BMP"));
		}

		// 글자 

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("I.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("S.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("O.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("N.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("T.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("A.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("R.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("!.BMP"));
		}
		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bullet.BMP"));
		}
		// 몬스터 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("AttackPre.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterIdle.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterAttack.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterNife.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerCheck.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DeathOne.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DeathTwo.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterJump.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterBackJump.BMP"));
			Image->Cut(5, 3);
		}
		// 무기 
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Boom.BMP"));
		Image->Cut(5, 4);
	}
	



	// 액터 생성

	{
		Player* Actor = CreateActor<Player>();
	}

	{
		Map* Actor = CreateActor<Map>();
	}
	{
		InterFace* Actor = CreateActor<InterFace>();
	}

	{
		//Monster* Actor = CreateActor<Monster>();
				
	}

	


	for (size_t i = 0; i < 100; i++)
	{
		Bullets* Actor = CreateActor<Bullets>(MetalSlugOrder::Bullet);
		//Actor->SetMove({ 100,500 });

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

