#include "MiddleBoss.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"
#include "Player.h"
#include "BulletEffect.h"
#include "PalaceRebel.h"
MiddleBoss* MiddleBoss::middleBoss;


MiddleBoss::MiddleBoss()
{
}

MiddleBoss::~MiddleBoss()
{

}




void MiddleBoss::Start()
{
	middleBoss = this;
	
	{
		PalaceBase = CreateRender(MetalSlugOrder::Palace);
		PalaceBase->SetImage("PalaceBase.Bmp");
		PalaceBase->SetScale({ 1200,430 });
		
	}
	{
		PalaceLeft = CreateRender(MetalSlugOrder::Pillar);
		PalaceLeft->SetImage("PalaceLeft.Bmp");
		PalaceLeft->SetScale({ 300,450 });
		PalaceLeft->SetPosition({ -160,-220 });
	}
	{
		PalaceRight = CreateRender(MetalSlugOrder::Pillar);
		PalaceRight->SetImage("PalaceRight.Bmp");	
		PalaceRight->SetScale({ 300,450 });
		PalaceRight->SetPosition({ 410,-220 });
	}
	{
		PalaceMiddle = CreateRender(MetalSlugOrder::Pillar);
		PalaceMiddle->SetImage("PalaceMiddle.Bmp");
		PalaceMiddle->SetScale({ 300,450 });
		PalaceMiddle->SetPosition({ 130,-220 });

	}

	{
		PalaceLeftDestory = CreateRender(MetalSlugOrder::Pillar);
		PalaceLeftDestory->SetImage("PalaceLeftDestory.Bmp");
		PalaceLeftDestory->SetScale({ 300,450 });
		PalaceLeftDestory->SetPosition({ -160,-220 });
		PalaceLeftDestory->Off(); 

	}

	{
		PalaceRightDestory = CreateRender(MetalSlugOrder::Pillar);
		PalaceRightDestory->SetImage("PalaceRightDestory.Bmp");
		PalaceRightDestory->SetScale({ 300,450 });
		PalaceRightDestory->SetPosition({ 410,-220 });
		PalaceRightDestory->Off();
	}
	{
		PalaceMiddleDestory = CreateRender(MetalSlugOrder::Pillar);
		PalaceMiddleDestory->SetImage("PalaceMiddleDestory.Bmp");
		PalaceMiddleDestory->SetScale({ 300,450 });
		PalaceMiddleDestory->SetPosition({ 130,-220 });
		PalaceMiddleDestory->Off();
	}
	


	{
		AnimationLeftDoorRender = CreateRender(MetalSlugOrder::Door);
		AnimationLeftDoorRender->SetScale({ 700,700 });
		AnimationLeftDoorRender->SetPosition({ -172,-210});
		AnimationLeftDoorRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "PalaceDoor.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = false });

	}

	{
		AnimationRightDoorRender = CreateRender(MetalSlugOrder::Door);
		AnimationRightDoorRender->SetScale({ 700,700 });
		AnimationRightDoorRender->SetPosition({ 422,-210 });
		AnimationRightDoorRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "PalaceDoor.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = false });

	}
	{
		AnimationMiddleDoorRender = CreateRender(MetalSlugOrder::Door);
		AnimationMiddleDoorRender->SetScale({ 700,700 });
		AnimationMiddleDoorRender->SetPosition({ 132,-210 });
		AnimationMiddleDoorRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "PalaceDoor.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = false });
	}




	{
		AnimationLeftWindowRender = CreateRender(MetalSlugOrder::Window);
		AnimationLeftWindowRender->SetScale({ 600,600 });
		AnimationLeftWindowRender->SetPosition({ -172,-210 });
		AnimationLeftWindowRender->CreateAnimation({ .AnimationName = "Window",  .ImageName = "PalaceWindow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
	}


	{
		AnimationRightWindowRender = CreateRender(MetalSlugOrder::Window);
		AnimationRightWindowRender->SetScale({ 600,600 });
		AnimationRightWindowRender->SetPosition({ 422,-210 });
		AnimationRightWindowRender->CreateAnimation({ .AnimationName = "Window",  .ImageName = "PalaceWindow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
	}

	{
		AnimationMiddleWindowRender = CreateRender(MetalSlugOrder::Window);
		AnimationMiddleWindowRender->SetScale({ 600,600 });
		AnimationMiddleWindowRender->SetPosition({ 132,-210 });
		AnimationMiddleWindowRender->CreateAnimation({ .AnimationName = "Window",  .ImageName = "PalaceWindow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
	}






	{
		AnimationLeftHumanRender = CreateRender(MetalSlugOrder::WindowHuman);
		AnimationLeftHumanRender->SetScale({ 600,600 });
		AnimationLeftHumanRender->SetPosition({ -172,-210 });
		AnimationLeftHumanRender->CreateAnimation({ .AnimationName = "Open",  .ImageName = "PalaceHumanIdle.bmp", .Start = 0, .End = 12, .InterTime = 0.1f,.Loop = false });
	}
	{
		AnimationRightHumanRender = CreateRender(MetalSlugOrder::WindowHuman);
		AnimationRightHumanRender->SetScale({ 600,600 });
		AnimationRightHumanRender->SetPosition({ 422,-210 });
		AnimationRightHumanRender->CreateAnimation({ .AnimationName = "Open",  .ImageName = "PalaceHumanIdle.bmp", .Start = 0, .End = 12, .InterTime = 0.1f,.Loop = false });
	}

	{
		AnimationMiddleHumanRender = CreateRender(MetalSlugOrder::WindowHuman);
		AnimationMiddleHumanRender->SetScale({ 600,600 });
		AnimationMiddleHumanRender->SetPosition({ 132,-210 });
		AnimationMiddleHumanRender->CreateAnimation({ .AnimationName = "Open",  .ImageName = "PalaceHumanIdle.bmp", .Start = 0, .End = 12, .InterTime = 0.1f,.Loop = false });
	}


	{
		AnimationLeftHumanAttackRender = CreateRender(MetalSlugOrder::WindowHuman);
		AnimationLeftHumanAttackRender->SetScale({ 600,600 });
		AnimationLeftHumanAttackRender->SetPosition({ -172,-210 });
		AnimationLeftHumanAttackRender->CreateAnimation({ .AnimationName = "Attack",  .ImageName = "PalaceHuman.bmp", .Start = 13, .End = 17, .InterTime = 0.1f,.Loop = false ,.FrameIndex{13,14,15,16,17,16,15,14,13} });
	}
	{
		AnimationRightHumanAttackRender = CreateRender(MetalSlugOrder::WindowHuman);
		AnimationRightHumanAttackRender->SetScale({ 600,600 });
		AnimationRightHumanAttackRender->SetPosition({ 422,-210 });
		AnimationRightHumanAttackRender->CreateAnimation({ .AnimationName = "Attack",  .ImageName = "PalaceHuman.bmp",.Start = 13, .End = 17, .InterTime = 0.1f,.Loop = false,.FrameIndex{13,14,15,16,17,16,15,14,13} });
	}

	{
		AnimationMiddleHumanAttackRender = CreateRender(MetalSlugOrder::WindowHuman);
		AnimationMiddleHumanAttackRender->SetScale({ 600,600 });
		AnimationMiddleHumanAttackRender->SetPosition({ 132,-210 });
		AnimationMiddleHumanAttackRender->CreateAnimation({ .AnimationName = "Attack",  .ImageName = "PalaceHuman.bmp", .Start = 13, .End = 17, .InterTime = 0.1f,.Loop = false,.FrameIndex{13,14,15,16,17,16,15,14,13} });
	}



	{
		LeftDoorRender = CreateRender(MetalSlugOrder::Door);
		LeftDoorRender->SetScale({ 700,700 });
		LeftDoorRender->SetPosition({ -172,-210 });
		LeftDoorRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "PalaceDoor.bmp", .Start = 0, .End = 0, .InterTime = 0.1f,.Loop = false });
		//LeftDoorRender->ChangeAnimation("Door");
	}

	{
		RightDoorRender = CreateRender(MetalSlugOrder::Door);
		RightDoorRender->SetScale({ 700,700 });
		RightDoorRender->SetPosition({ 422,-210 });
		RightDoorRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "PalaceDoor.bmp", .Start = 0, .End = 0, .InterTime = 0.1f,.Loop = false });
	 //   RightDoorRender->ChangeAnimation("Door");
	}

	{
		MiddleDoorRender = CreateRender(MetalSlugOrder::Door);
		MiddleDoorRender->SetScale({ 700,700 });
		MiddleDoorRender->SetPosition({ 132,-210 });
		MiddleDoorRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "PalaceDoor.bmp", .Start = 0, .End = 0, .InterTime = 0.1f,.Loop = false });
		//MiddleDoorRender->ChangeAnimation("Door");
	}


	{
		AnimationLeftSmokeRender = CreateRender(MetalSlugOrder::Smoke);
		AnimationLeftSmokeRender->SetScale({ 600,600 });
		AnimationLeftSmokeRender->SetPosition({ -192,-290 });
		AnimationLeftSmokeRender->CreateAnimation({ .AnimationName = "Smoke",  .ImageName = "PalaceSmoke.bmp", .Start = 0, .End = 31, .InterTime = 0.1f,.Loop = false });
		//MiddleDoorRender->ChangeAnimation("Door");
	}


	{
		AnimationRightSmokeRender = CreateRender(MetalSlugOrder::Smoke);
		AnimationRightSmokeRender->SetScale({ 600,600 });
		AnimationRightSmokeRender->SetPosition({ 402,-290 });
		AnimationRightSmokeRender->CreateAnimation({ .AnimationName = "Smoke",  .ImageName = "PalaceSmoke.bmp", .Start = 0, .End = 31, .InterTime = 0.1f,.Loop = false });
		//MiddleDoorRender->ChangeAnimation("Door");
	}


	{
		AnimationMiddleSmokeRender = CreateRender(MetalSlugOrder::Smoke);
		AnimationMiddleSmokeRender->SetScale({ 600,600 });
		AnimationMiddleSmokeRender->SetPosition({ 112,-290 });
		AnimationMiddleSmokeRender->CreateAnimation({ .AnimationName = "Smoke",  .ImageName = "PalaceSmoke.bmp", .Start = 0, .End = 31, .InterTime = 0.1f,.Loop = false });
		//MiddleDoorRender->ChangeAnimation("Door");
	}

	{
		SmallExploision = CreateRender(MetalSlugOrder::Exploision);
		SmallExploision->SetScale({ 700,700 });
		SmallExploision->SetPosition({ 112,-290 });
		SmallExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "SmallExploision.bmp", .Start = 0, .End = 26, .InterTime = 0.1f,.Loop = false });

		SmallExploision2 = CreateRender(MetalSlugOrder::Exploision);
		SmallExploision2->SetScale({ 700,700 });
		SmallExploision2->SetPosition({ 112,-290 });
		SmallExploision2->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "SmallExploision.bmp", .Start = 0, .End = 26, .InterTime = 0.1f,.Loop = false });

		SmallExploision3 = CreateRender(MetalSlugOrder::Exploision);
		SmallExploision3->SetScale({ 700,700 });
		SmallExploision3->SetPosition({ 112,-290 });
		SmallExploision3->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "SmallExploision.bmp", .Start = 0, .End = 26, .InterTime = 0.1f,.Loop = false });

		MiddleExploision = CreateRender(MetalSlugOrder::Exploision);
		MiddleExploision->SetScale({ 700,700 });
		MiddleExploision->SetPosition({ 112,-290 });
		MiddleExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });

		MiddleExploision2 = CreateRender(MetalSlugOrder::Exploision);
		MiddleExploision2->SetScale({ 700,700 });
		MiddleExploision2->SetPosition({ 112,-290 });
		MiddleExploision2->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });

		MiddleExploision3 = CreateRender(MetalSlugOrder::Exploision);
		MiddleExploision3->SetScale({ 700,700 });
		MiddleExploision3->SetPosition({ 112,-290 });
		MiddleExploision3->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });

		MiddleExploision4 = CreateRender(MetalSlugOrder::Exploision);
		MiddleExploision4->SetScale({ 700,700 });
		MiddleExploision4->SetPosition({ 112,-290 });
		MiddleExploision4->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });

		MiddleExploision5 = CreateRender(MetalSlugOrder::Exploision);
		MiddleExploision5->SetScale({ 700,700 });
		MiddleExploision5->SetPosition({ 112,-290 });
		MiddleExploision5->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });

		MiddleExploision6 = CreateRender(MetalSlugOrder::Exploision);
		MiddleExploision6->SetScale({ 700,700 });
		MiddleExploision6->SetPosition({ 112,-290 });
		MiddleExploision6->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });






		BigExploision = CreateRender(MetalSlugOrder::Exploision);
		BigExploision->SetScale({ 900,900 });
		BigExploision->SetPosition({ 112,-290 });
		BigExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });

		BigExploision2 = CreateRender(MetalSlugOrder::Exploision);
		BigExploision2->SetScale({ 900,900 });
		BigExploision2->SetPosition({ 112,-290 });
		BigExploision2->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });

		BigExploision3 = CreateRender(MetalSlugOrder::Exploision);
		BigExploision3->SetScale({ 900,900 });
		BigExploision3->SetPosition({ 112,-290 });
		BigExploision3->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });

		LeftBigExploision = CreateRender(MetalSlugOrder::Exploision);
		LeftBigExploision->SetScale({ 900,900 });
		LeftBigExploision->SetPosition({ -172,-330 });
		LeftBigExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });

		RightBigExploision = CreateRender(MetalSlugOrder::Exploision);
		RightBigExploision->SetScale({ 900,900 });
		RightBigExploision->SetPosition({ 422,-330 });
		RightBigExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });


		MiddleBigExploision = CreateRender(MetalSlugOrder::Exploision);
		MiddleBigExploision->SetScale({ 900,900 });
		MiddleBigExploision->SetPosition({ 132,-330 });
		MiddleBigExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });


	}
	{
		PalaceLeftDoorEffect = CreateRender(MetalSlugOrder::Exploision);
		PalaceLeftDoorEffect->SetScale({ 200,200 });
		PalaceLeftDoorEffect->SetPosition({ -200,100 });
		PalaceLeftDoorEffect->CreateAnimation({ .AnimationName = "DoorEffect",  .ImageName = "PalaceDoorEffect.bmp", .Start = 0, .End = 13, .InterTime = 0.05f,.Loop = true });

		PalaceRightDoorEffect = CreateRender(MetalSlugOrder::Exploision);
		PalaceRightDoorEffect->SetScale({200,200 });
		PalaceRightDoorEffect->SetPosition({ 400,100 });
		PalaceRightDoorEffect->CreateAnimation({ .AnimationName = "DoorEffect",  .ImageName = "PalaceDoorEffect.bmp", .Start = 0, .End = 13, .InterTime = 0.05f,.Loop = true });
	}


	PalaceRightDoorEffect->Off(); 
	PalaceLeftDoorEffect->Off();
	SmallExploision ->ChangeAnimation("Exploision"); 
	SmallExploision2->ChangeAnimation("Exploision");
	SmallExploision3->ChangeAnimation("Exploision");

	MiddleExploision->ChangeAnimation("Exploision");
	MiddleExploision2->ChangeAnimation("Exploision");
	MiddleExploision3->ChangeAnimation("Exploision");
	MiddleExploision4->ChangeAnimation("Exploision");
	MiddleExploision5->ChangeAnimation("Exploision");
	MiddleExploision6->ChangeAnimation("Exploision");

	BigExploision->ChangeAnimation("Exploision");
	BigExploision2->ChangeAnimation("Exploision");
	BigExploision3->ChangeAnimation("Exploision");

	LeftBigExploision->ChangeAnimation("Exploision");
	RightBigExploision->ChangeAnimation("Exploision");
	MiddleBigExploision->ChangeAnimation("Exploision");

	AnimationMiddleDoorRender->ChangeAnimation("Door");
	AnimationRightDoorRender->ChangeAnimation("Door");
	AnimationLeftDoorRender->ChangeAnimation("Door");

	AnimationMiddleHumanRender->ChangeAnimation("Open");
	AnimationRightHumanRender->ChangeAnimation("Open");
	AnimationLeftHumanRender->ChangeAnimation("Open");
	
	AnimationLeftHumanAttackRender->ChangeAnimation("Attack");
	AnimationRightHumanAttackRender->ChangeAnimation("Attack");
	AnimationMiddleHumanAttackRender->ChangeAnimation("Attack");


	AnimationLeftSmokeRender->ChangeAnimation("Smoke");
	AnimationRightSmokeRender->ChangeAnimation("Smoke");
	AnimationMiddleSmokeRender->ChangeAnimation("Smoke");

	PalaceLeftDoorEffect->ChangeAnimation("DoorEffect");
	PalaceRightDoorEffect->ChangeAnimation("DoorEffect");


	AnimationMiddleDoorRender->Off();
	AnimationRightDoorRender->Off();
	AnimationLeftDoorRender->Off();

	AnimationLeftHumanAttackRender->Off(); 
	AnimationRightHumanAttackRender->Off();
	AnimationMiddleHumanAttackRender->Off();


	AnimationMiddleHumanRender->Off(); 
	AnimationRightHumanRender->Off();
	AnimationLeftHumanRender->Off();

	AnimationLeftSmokeRender->Off(); 
	AnimationRightSmokeRender->Off(); 
	AnimationMiddleSmokeRender->Off(); 

	SmallExploision ->Off();
	SmallExploision2->Off();
	SmallExploision3->Off();

	MiddleExploision ->Off();
	MiddleExploision2->Off();
	MiddleExploision3->Off();
	MiddleExploision4->Off();
	MiddleExploision5->Off();
	MiddleExploision6->Off();

	BigExploision ->Off();
	BigExploision2->Off();
	BigExploision3->Off();

	LeftBigExploision->Off();
	RightBigExploision->Off();
	MiddleBigExploision->Off();


	{
		LeftMonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		LeftMonsterCollision->SetScale({ 200, 200 });
		LeftMonsterCollision->SetPosition({-190,-350});
	}
	{
		RightMonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		RightMonsterCollision->SetScale({ 200, 200 });
		RightMonsterCollision->SetPosition({ 430, -350 });		
	}
	{
		MiddleMonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MiddleMonsterCollision->SetScale({ 200, 200 });
		MiddleMonsterCollision->SetPosition({ 120,-350 });
	}


	/*{
		PlayerCollision = CreateCollision(MetalSlugOrder::MonsterCheck);

		PlayerCollision->SetScale({ 500, 500 });
	}*/



	ChangeState(MiddleBossState::IDLESTART);
}




void MiddleBoss::test(const std::string_view& _AnimationName)
{
	


}

void MiddleBoss::AnimationCheck(const std::string_view& _AnimationName)
{

	if (StateValue == MiddleBossState::IDLESTART)
	{

		LeftDoorRender->ChangeAnimation(_AnimationName.data());			
		RightDoorRender->ChangeAnimation(_AnimationName.data());
		MiddleDoorRender->ChangeAnimation(_AnimationName.data());
			
	}


	


	  
	if (StateValue == MiddleBossState::IDLE)
	{
		LeftDoorRender->Off(); 
		RightDoorRender->Off(); 
		MiddleDoorRender->Off(); 

		AnimationLeftDoorRender->On(); 
		AnimationMiddleDoorRender->On(); 
		AnimationRightDoorRender->On(); 

		AnimationLeftDoorRender->ChangeAnimation(_AnimationName.data());
		AnimationMiddleDoorRender->ChangeAnimation(_AnimationName.data());
		AnimationRightDoorRender->ChangeAnimation(_AnimationName.data());

		AnimationLeftWindowRender->ChangeAnimation("Window");
		AnimationRightWindowRender->ChangeAnimation("Window");
		AnimationMiddleWindowRender->ChangeAnimation("Window");
	}


	LeftDoorRender->ChangeAnimation(_AnimationName.data());
	RightDoorRender->ChangeAnimation(_AnimationName.data());
	MiddleDoorRender->ChangeAnimation(_AnimationName.data());

	AnimationLeftDoorRender->ChangeAnimation(_AnimationName.data());
	AnimationMiddleDoorRender->ChangeAnimation(_AnimationName.data());
	AnimationRightDoorRender->ChangeAnimation(_AnimationName.data());

	AnimationLeftWindowRender->ChangeAnimation("Window");
	AnimationRightWindowRender->ChangeAnimation("Window");
	AnimationMiddleWindowRender->ChangeAnimation("Window");

}

void MiddleBoss::OpenCheck(const std::string_view& _AnimationName)
{
	AnimationLeftWindowRender->Off(); 
	AnimationRightWindowRender->Off();
	AnimationMiddleWindowRender->Off();

	AnimationLeftHumanRender->On(); 
	AnimationRightHumanRender->On();
	AnimationMiddleHumanRender->On();

	AnimationLeftHumanRender->ChangeAnimation(_AnimationName.data());
	AnimationRightHumanRender->ChangeAnimation(_AnimationName.data());
	AnimationMiddleHumanRender->ChangeAnimation(_AnimationName.data());

}

void MiddleBoss::LeftAttackCheck(const std::string_view& _AnimationName)
{
	if (LeftHp > 0)
	{

		AnimationLeftHumanAttackRender->On();


		AnimationLeftHumanAttackRender->ChangeAnimation(_AnimationName.data(), true);

	}

}

void MiddleBoss::RightAttackCheck(const std::string_view& _AnimationName)
{
	if (RightHp > 0)
	{
		AnimationRightHumanAttackRender->On();




		AnimationRightHumanAttackRender->ChangeAnimation(_AnimationName.data(), true);
	}
}

void MiddleBoss::MiddleAttackCheck(const std::string_view& _AnimationName)
{
	if (MiddleHp > 0)
	{
		AnimationMiddleHumanAttackRender->On();

		AnimationMiddleHumanAttackRender->ChangeAnimation(_AnimationName.data(), true);
	}


}

void MiddleBoss::LeftSmokeCheck(const std::string_view& _AnimationName)
{
	
	AnimationLeftSmokeRender->On();

	AnimationLeftSmokeRender->ChangeAnimation(_AnimationName.data(),true);
}

void MiddleBoss::RightSmokeCheck(const std::string_view& _AnimationName)
{
	
	AnimationRightSmokeRender->On();
	AnimationRightSmokeRender->ChangeAnimation(_AnimationName.data(),true);
}

void MiddleBoss::MiddleSmokeCheck(const std::string_view& _AnimationName)
{
	/*AnimationLeftSmokeRender->Off();
	AnimationRightSmokeRender->Off();
	AnimationMiddleSmokeRender->On();*/

	AnimationMiddleSmokeRender->On();
	AnimationMiddleSmokeRender->ChangeAnimation(_AnimationName.data(), true);
}



void MiddleBoss::DoorUpdate(float _Time)
{
}


void MiddleBoss::Update(float _DeltaTime)
{
	

	if (LeftHp <= 0 && RightHp <= 0 && MiddleHp <= 0)
	{
		if (DeathSoundCheck == false)
		{
			PalaceDeath = GameEngineResources::GetInst().SoundPlayToControl("PalaceDeath.mp3");
			PalaceDeath.LoopCount(1);
			PalaceDeath.Volume(2.0f);

			PalaceExploision = GameEngineResources::GetInst().SoundPlayToControl("PalaceExl.mp3");
			PalaceExploision.Volume(1.5f);
			PalaceExploision.LoopCount(3);
			DeathSoundCheck = true;
		}
	}

	if (Player::MainPlayer->GetPos().x > GetPos().x)
	{
		SetMiddleBossStart(true);
		Player::MainPlayer->CameraMoveCheck = Player::MainPlayer->GetPos();
		Player::MainPlayer->SetCameraCheck(false);

		if (CurPosCheck == false)
		{
			CurPos = GetLevel()->GetCameraPos();
			CurPosCheck = true;

		}


	}


	if (MiddleBossStart == true)
	{
		if (SildeSounCheck == false)
		{
			PalaceSlide = GameEngineResources::GetInst().SoundPlayToControl("PalaceSlide.mp3");
			PalaceSlide.LoopCount(1);
			SildeSounCheck = true;
		}



		if (nullptr != LeftMonsterCollision && LeftHp>0)
		{
			std::vector<GameEngineCollision*> collision;
			if (true == LeftMonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
			{

				LeftHp--;

				for (size_t i = 0; i < collision.size(); i++)
				{
					GameEngineActor* ColActor = collision[i]->GetActor();
					BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
					Effect->SetPos(ColActor->GetPos());
					


					ColActor->Death();
				}
				if (LeftHp == 0)
				{
					PalaceRebel* Actor = GetLevel()->CreateActor<PalaceRebel>();
					Actor->SetPos({ GetPos().x-190,  GetPos().y -230});
				}
			
			}
		}

		if (LeftHp <= 0)
		{
		//	LeftMonsterCollision->Death();
			AnimationLeftDoorRender->Off();
			AnimationLeftHumanAttackRender->Off();
			AnimationLeftHumanRender->Off();
			AnimationLeftSmokeRender->Off();
			AnimationLeftWindowRender->Off();
			LeftBigExploision->On(); 
			AnimationLeftSmokeRender->Off();
			PalaceLeft->Off();
			PalaceLeftDestory->On();
		
			
		}

		if (nullptr != RightMonsterCollision && RightHp > 0)
		{
			std::vector<GameEngineCollision*> collision;
			if (true == RightMonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
			{

				RightHp--;

				for (size_t i = 0; i < collision.size(); i++)
				{
					GameEngineActor* ColActor = collision[i]->GetActor();

					BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
					Effect->SetMove(ColActor->GetPos());
					

					ColActor->Death();
				}
				if (RightHp == 0)
				{
					PalaceRebel* Actor = GetLevel()->CreateActor<PalaceRebel>();
					Actor->SetPos({ GetPos().x +422,  GetPos().y - 230 });
				}
			
			}
		}

		if (RightHp <= 0)
		{
			//RightMonsterCollision->Death();
			AnimationRightDoorRender->Off();
			AnimationRightHumanAttackRender->Off();
			AnimationRightHumanRender->Off();
			AnimationRightSmokeRender->Off();
			AnimationRightWindowRender->Off();
			RightBigExploision->On();
			PalaceRight->Off();
			PalaceRightDestory->On();
			

		}

		if (nullptr != MiddleMonsterCollision  && MiddleHp > 0)
		{
			std::vector<GameEngineCollision*> collision;
			if (true == MiddleMonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
			{

				MiddleHp--;

				for (size_t i = 0; i < collision.size(); i++)
				{
					GameEngineActor* ColActor = collision[i]->GetActor();

					BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
					Effect->SetMove(ColActor->GetPos());

					ColActor->Death();
				}
				if (MiddleHp == 0)
				{
					PalaceRebel* Actor = GetLevel()->CreateActor<PalaceRebel>();
					Actor->SetPos({ GetPos().x + 132,  GetPos().y - 230 });
				}
			}
		}

		if (MiddleHp <= 0)
		{
			//MiddleMonsterCollision->Death();
			AnimationMiddleDoorRender->Off();
			AnimationMiddleHumanAttackRender->Off();
			AnimationMiddleHumanRender->Off();
			AnimationMiddleSmokeRender->Off();
			AnimationMiddleWindowRender->Off();
			MiddleBigExploision->On(); 
			PalaceMiddle->Off();
			PalaceMiddleDestory->On();
			
		}

		if (LeftHp <= 0 && MiddleHp <= 0 && RightHp <= 0)
		{
			

			ChangeState(MiddleBossState::DEATH);
		}


		MoveCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();




		if (MoveCheck < 0.7)
		{
			MoveDirMiddle = float4::Up * 100;
			PalaceMiddle->SetMove(MoveDirMiddle * _DeltaTime);
			AnimationMiddleDoorRender->SetMove(MoveDirMiddle * _DeltaTime);
			AnimationMiddleWindowRender->SetMove(MoveDirMiddle * _DeltaTime);
			AnimationMiddleHumanRender->SetMove(MoveDirMiddle * _DeltaTime);
			AnimationMiddleHumanAttackRender->SetMove(MoveDirMiddle * _DeltaTime);
			MiddleDoorRender->SetMove(MoveDirMiddle * _DeltaTime);
			AnimationMiddleSmokeRender->SetMove(MoveDirMiddle * _DeltaTime);
			PalaceMiddleDestory->SetMove(MoveDirMiddle * _DeltaTime);

		}
		if (MoveCheck < 0.7)
		{
			MoveDirLeft = float4::AngleToDirection2DToDeg(-110) * 100;
			PalaceLeft->SetMove(MoveDirLeft * _DeltaTime);
			AnimationLeftDoorRender->SetMove(MoveDirLeft * _DeltaTime);
			AnimationLeftWindowRender->SetMove(MoveDirLeft * _DeltaTime);
			AnimationLeftHumanRender->SetMove(MoveDirLeft * _DeltaTime);
			AnimationLeftHumanAttackRender->SetMove(MoveDirLeft * _DeltaTime);
			LeftDoorRender->SetMove(MoveDirLeft * _DeltaTime);
			AnimationLeftSmokeRender->SetMove(MoveDirLeft * _DeltaTime);
			PalaceLeftDestory->SetMove(MoveDirLeft * _DeltaTime);
		}
		if (MoveCheck < 0.7)
		{
			MoveDirRight = float4::AngleToDirection2DToDeg(-70) * 100;
			PalaceRight->SetMove(MoveDirRight * _DeltaTime);
			AnimationRightDoorRender->SetMove(MoveDirRight * _DeltaTime);
			AnimationRightWindowRender->SetMove(MoveDirRight * _DeltaTime);
			AnimationRightHumanRender->SetMove(MoveDirRight * _DeltaTime);
			AnimationRightHumanAttackRender->SetMove(MoveDirRight * _DeltaTime);
			RightDoorRender->SetMove(MoveDirRight * _DeltaTime);
			AnimationRightSmokeRender->SetMove(MoveDirRight * _DeltaTime);
			PalaceRightDestory->SetMove(MoveDirRight * _DeltaTime);
		}

		

		//if (AttackCheck == true)
		//{			
		//	
		//	
		//	
		//	RightAttackTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		//	MiddleAttackTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();


		//	if (LeftAttackTime > 0.5)
		//	{
		//		ChangeState(MiddleBossState::LEFTATTACK);
		//		LeftAttackTime = 0; 				
		//	}
		//	if (RightAttackTime > 0.7)
		//	{
		//		ChangeState(MiddleBossState::RIGHTATTACK);
		//		RightAttackTime = 0;			
		//	}

		//	if (MiddleAttackTime > 1.1)
		//	{
		//		ChangeState(MiddleBossState::MIDDLEATTACK);
		//		MiddleAttackTime = 0;

		//	}


		//}


		if (MoveCheck > 1.0 && StateValue == MiddleBossState::IDLESTART)
		{
			ChangeState(MiddleBossState::IDLE);
			return;
		}

		
		UpdateState(_DeltaTime);
	}
	
}

void MiddleBoss::Render(float _Time)
{



	//LeftMonsterCollision->DebugRender();
	LeftMonsterCollision->On();

	//RightMonsterCollision->DebugRender(); 
	//MiddleMonsterCollision->DebugRender();



}

