
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
#include "MonsterCamel.h"
#include "NPC.h"
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





	GameEngineDirectory InferFace;
	InferFace.MoveParentToDirectory("ContentsResources");
	InferFace.Move("ContentsResources");
	InferFace.Move("Image");
	InferFace.Move("Interface");


	GameEngineDirectory map;
	map.MoveParentToDirectory("ContentsResources");
	map.Move("ContentsResources");
	map.Move("Image");
	map.Move("Map");

	GameEngineDirectory Monster;
	Monster.MoveParentToDirectory("ContentsResources");
	Monster.Move("ContentsResources");
	Monster.Move("Image");
	Monster.Move("Monster");

	GameEngineDirectory Npc;
	Npc.MoveParentToDirectory("ContentsResources");
	Npc.Move("ContentsResources");
	Npc.Move("Image");
	Npc.Move("Npc");



	GameEngineDirectory Weapon;
	Weapon.MoveParentToDirectory("ContentsResources");
	Weapon.Move("ContentsResources");
	Weapon.Move("Image");
	Weapon.Move("Weapon");

	{
		


		// 맵 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("Map12.BMP"));
		}				
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("Map11.BMP"));
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

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunUpAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunUpAttack.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeavyGunIdleAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeavyGunIdleAttack.BMP"));
			Image->Cut(5, 2);
		}


		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeavyGunIdle.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeavyGunIdle.BMP"));
			Image->Cut(5, 1);
		}


		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunUp.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunUp.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunThrow.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunThrow.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunMoveJump.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunMoveJump.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunMove.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunDownAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunDownAttack.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeaveGunIdleJump.BMP"));
			Image->Cut(5, 1);
		}		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeaveGunIdleJump.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeavyUpAttack.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeavyUpAttack.BMP"));
			Image->Cut(5, 1);
		}


		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeavyUpChangeIdle.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeavyUpChangeIdle.BMP"));
			Image->Cut(5, 1);
		}
		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftHeavyIdleChangeUp.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightHeavyIdleChangeUp.BMP"));
			Image->Cut(5, 1);
		}
		








	     //인터페이스 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("Bullets.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("Score.BMP"));
		}		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("PressStart.BMP"));
			Image->Cut(2, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("00.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("Number.BMP"));
			Image->Cut(10, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("M.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("I.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("S.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("O.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("N.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("T.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("A.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("R.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("!.BMP"));
		}
		
		


		// 몬스터 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("AttackPre.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterIdle.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterAttack.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterNife.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PlayerCheck.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("DeathOne.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("DeathTwo.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterJump.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterBackJump.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("CamelMonsterStart.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelAttackBody.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelDeathReg.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelDownBody.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelDownReg.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelMoveBody.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelMoveReg.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MonsterCamelEffect.BMP"));
		}


		//NPC

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("RightNpcMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcCollisionAfter.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcIdle.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("LeftNpcMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcCollision.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcDeath.BMP"));
			Image->Cut(5, 2);
		}















		// 무기 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("Boom.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("Exploision1.BMP"));
			Image->Cut(5, 6);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("Bullet.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("HeavyBullet.BMP"));
		}
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
		NPC* Actor = CreateActor<NPC>();
		Actor->SetMove({ 500,0 });
	}
	/*{
		MonsterCamel* Actor = CreateActor<MonsterCamel>();
		Actor->SetMove({ 1000,0 });
	}*/

	


	for (size_t i = 0; i < 100; i++)
	{
		Bullets* Actor = CreateActor<Bullets>(MetalSlugOrder::Bullet);
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

	float CameraMoveSpeed = 
		.0f;

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

