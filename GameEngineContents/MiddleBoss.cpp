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
	srand(static_cast<unsigned int>(time(nullptr)));
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
	

	AnimationLeftHumanAttackRender->On();
	

	AnimationLeftHumanAttackRender->ChangeAnimation(_AnimationName.data());



}

void MiddleBoss::RightAttackCheck(const std::string_view& _AnimationName)
{
	AnimationRightHumanAttackRender->On();




	AnimationRightHumanAttackRender->ChangeAnimation(_AnimationName.data());
}

void MiddleBoss::MiddleAttackCheck(const std::string_view& _AnimationName)
{
	
	AnimationMiddleHumanAttackRender->On();

	AnimationMiddleHumanAttackRender->ChangeAnimation(_AnimationName.data());



}

void MiddleBoss::LeftSmokeCheck(const std::string_view& _AnimationName)
{

	AnimationLeftSmokeRender->On(); 

	AnimationLeftSmokeRender->ChangeAnimation(_AnimationName.data());
}

void MiddleBoss::RightSmokeCheck(const std::string_view& _AnimationName)
{
	AnimationRightSmokeRender->On();

	AnimationRightSmokeRender->ChangeAnimation(_AnimationName.data());
}

void MiddleBoss::MiddleSmokeCheck(const std::string_view& _AnimationName)
{
	AnimationMiddleSmokeRender->On();

	AnimationMiddleSmokeRender->ChangeAnimation(_AnimationName.data());
}



void MiddleBoss::DoorUpdate(float _Time)
{
}


void MiddleBoss::Update(float _DeltaTime)
{
	if (nullptr != LeftMonsterCollision)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == LeftMonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			LeftHp--;

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}

			if (LeftHp == 0)
			{
				AnimationLeftDoorRender->Off();
				AnimationLeftHumanAttackRender->Off();
				AnimationLeftHumanRender->Off();
				AnimationLeftSmokeRender->Off();
				AnimationLeftWindowRender->Off();
			
				AnimationLeftSmokeRender->Off(); 
				PalaceLeft->Off(); 
				PalaceLeftDestory->On();
			}
		}
	}
	if (nullptr != RightMonsterCollision)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == RightMonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			RightHp--;

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}

			if (RightHp == 0)
			{
				AnimationRightDoorRender->Off();
				AnimationRightHumanAttackRender->Off();
				AnimationRightHumanRender->Off();
				AnimationRightSmokeRender->Off();
				AnimationRightWindowRender->Off();
				PalaceRight->Off();
				PalaceRightDestory->On();
				//RightMonsterCollision->Death(); 
			}
		}
	}
	if (nullptr != MiddleMonsterCollision)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MiddleMonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			MiddleHp--;

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}

			if (MiddleHp == 0)
			{
				AnimationMiddleDoorRender->Off();
				AnimationMiddleHumanAttackRender->Off();
				AnimationMiddleHumanRender->Off();
				AnimationMiddleSmokeRender->Off();
				AnimationMiddleWindowRender->Off();
				PalaceMiddle->Off();
				PalaceMiddleDestory->On();

			}
		}
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
		MoveDirLeft = float4::AngleToDirection2DToDeg(-110)*100;
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

	AttackTime += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 

	/*if (AttackTime > 1.5)
	{
		int a = rand() % 3;

		if (a == 0)
		{

		}
		if (a == 1)
		{

		}
		if (a == 2)
		{

		}



	}*/


	if (MoveCheck > 1.0 &&StateValue == MiddleBossState::IDLESTART )
	{
		ChangeState(MiddleBossState::IDLE);
		return;
	}


	UpdateState(_DeltaTime);

	
}

void MiddleBoss::Render(float _Time)
{



	/*LeftMonsterCollision->DebugRender();
	RightMonsterCollision->DebugRender(); 
	MiddleMonsterCollision->DebugRender();*/



}

