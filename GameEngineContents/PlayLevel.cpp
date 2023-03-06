

#include "STLevel.h"


#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include "PlayLevel.h"
#include "Player.h"
#include "Map.h"
#include "InterFace.h"
#include "MapEffect.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading() 
{
	SoundLoad();

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

	GameEngineDirectory Exploision;
	Exploision.MoveParentToDirectory("ContentsResources");
	Exploision.Move("ContentsResources");
	Exploision.Move("Image");
	Exploision.Move("Exploision");

	GameEngineDirectory items;
	items.MoveParentToDirectory("ContentsResources");
	items.Move("ContentsResources");
	items.Move("Image");
	items.Move("items");




	{
		


		// 맵 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("Map12.BMP"));
		}				
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("Map11.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("Map10.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("Wall.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("StonEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("MapRightTentJump.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("MapBackGround.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("MapTent.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("MapTentJump.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(map.GetPlusFileName("MapRightTent.BMP"));
			Image->Cut(5, 1);
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

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parachute.BMP"));
			Image->Cut(5, 1);
		} 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parachuteDown.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_HeavyGun_Throw.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_HeavyGun_Throw.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerWin.BMP"));
			Image->Cut(5, 2);
		}







	     //인터페이스 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("Bullets.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("Score.BMP"));
		}		
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("BaseGunBullet.BMP"));
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
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("C.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("E.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("P.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(InferFace.GetPlusFileName("L.BMP"));
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
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightMonsterAttack.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightMonsterDeath.BMP"));
			Image->Cut(5, 4);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightMonsterIdle.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightMonsterJump.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightMonsterMove.BMP"));
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

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RunMonsterRegAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RunMonsterMove.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RunMonsterIdle.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RunMonsterDeath.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RunMonsterBodyAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("CarriageMove.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("Carriage.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("CarriageDestory.BMP"));
			Image->Cut(5, 2);
		}
		// Rebel
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelAttack.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelDeath.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelIdle.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelIdle2.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelMoveFinish.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelMovePre.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RebelWeapon.BMP"));
			Image->Cut(5, 3);
		}
		//Machine

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonsterSfx.BMP"));
			Image->Cut(5, 4);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonsterMove.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonsterDeath.BMP"));
			Image->Cut(5, 5);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonsterBullet.BMP"));
			Image->Cut(5, 3);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonsterAttackPre.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonsterAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MachineMonster.BMP"));
			Image->Cut(5, 2);
		}
		//MiniBoss
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MiniBossAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MiniBossLeftMove.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MiniBossSurrender.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MiniBossRightMove.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("MiniBossIdle.BMP"));
			Image->Cut(5, 1);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceRebel.BMP"));
			Image->Cut(5, 4);
		}


		// 궁전 
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceBase.BMP"));
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceLeft.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceRight.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceMiddle.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceDoor.BMP"));			
				Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceWindow.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceHumanIdle.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceHumanAttack.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceHuman.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceMissileIdle.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceMissileMove.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceSmoke.BMP"));
			Image->Cut(5, 7);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceLeftDestory.BMP"));
			
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceMiddleDestory.BMP"));
		
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceRightDestory.BMP"));	

		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("PalaceDoorEffect.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("DestoryBase.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("Blood.BMP"));
			Image->Cut(5, 2);
		}
		//boss

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("Boss.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("LeftBossIdleBoom.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightBossIdleBoom.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("GroundEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("LeftWing.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightWing.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("LeftEngine.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightEngine.BMP"));
			Image->Cut(5, 2);
		}
		//
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BoosAttackPreBlueBoom.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BossAttackPreRedBoom.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BossAttackPreYellowBoom.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BossRedShakeBoom.BMP"));
			Image->Cut(5, 5);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BossShakeBlueBoom.BMP"));
			Image->Cut(5, 5);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BossShakeYellowBoom.BMP"));
			Image->Cut(5, 5);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightBossSmoke.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("LeftBossSmoke.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("GroundSmokeEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("GroundBlueEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("GroundRedEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("GroundYellowEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("Bossmount.BMP"));
			Image->Cut(5, 2);
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("TwoBoss.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("DeathBoss.BMP"));
		}

		// bazooka
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BazookaAttackEffect.BMP"));
			Image->Cut(5, 4);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("BazookaBullet.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("LeftBazookaAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("LeftBazookaMove.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightBazookaAttack.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Monster.GetPlusFileName("RightBazookaMove.BMP"));
			Image->Cut(5, 3);
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
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcBind.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcMoveDown.BMP"));
			Image->Cut(5, 3);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcDown.BMP"));
			Image->Cut(5, 1);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Npc.GetPlusFileName("NpcBindMovePre.BMP"));
			Image->Cut(5, 3);
		}

		//Exploision

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Exploision.GetPlusFileName("BigExploision.BMP"));
			Image->Cut(5, 6);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Exploision.GetPlusFileName("MiddleExploision.BMP"));
			Image->Cut(5, 6);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Exploision.GetPlusFileName("SmallExploision.BMP"));
			Image->Cut(5, 6);
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
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("RightHeavyBullet.BMP"));
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("RightUpHeavyBullet1.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("RightUpHeavyBullet2.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("RightUpHeavyBullet3.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("RightUpHeavyBullet4.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("RightUpHeavyBullet5.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("UpHeavyBullet.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("LeftHeavyBullet.BMP"));
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("LeftUpHeavyBullet1.BMP"));
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("LeftUpHeavyBullet2.BMP"));
		}

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("LeftUpHeavyBullet3.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("LeftUpHeavyBullet4.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("LeftUpHeavyBullet5.BMP"));
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Weapon.GetPlusFileName("BulletEffect.BMP"));
			Image->Cut(5, 2);
		}
		// items
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(items.GetPlusFileName("ItemBoomb.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(items.GetPlusFileName("ItemEffect.BMP"));
			Image->Cut(5, 2);
		}
		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(items.GetPlusFileName("ItemHeavyGun.BMP"));
		}

	}
	
	//6200


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
		MapEffect* Actor = CreateActor<MapEffect>();
		Actor->SetPos({ 11850,700 });
	}
	/*{
		Boss* Actor = CreateActor<Boss>();
		Actor->SetPos({ 11800,300});
	}*/


	/*{
		MiddleBoss* Actor = CreateActor<MiddleBoss>();
		Actor->SetPos({ 6540,500 });
	}*/
	/*{
		PalaceBullet* Actor = CreateActor<PalaceBullet>();
	}*/
	/*{
		NPC* Actor = CreateActor<NPC>();
		Actor->SetMove({ 500,0 });
	}*/
   /* {
		MonsterCamel* Actor = CreateActor<MonsterCamel>();
		Actor->SetMove({ 1000,0 });
	}*/
   /* {
		RunMonster* Actor = CreateActor<RunMonster>();
		Actor->SetMove({ 800,500 });
	}*/
	



	/*for (size_t i = 0; i < 100; i++)
	{
		Bullets* Actor = CreateActor<Bullets>(MetalSlugOrder::Bullet);
	}*/

	


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

void PlayLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	std::vector<GameEngineFile> Files = Dir.GetAllFile();

	for (size_t i = 0; i < Files.size(); i++)
	{
		GameEngineResources::GetInst().SoundLoad(Files[i].GetFullPath());
	}
}

