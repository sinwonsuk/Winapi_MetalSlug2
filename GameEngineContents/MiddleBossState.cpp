#include "MiddleBoss.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MonsterCamelEffect.h"
#include "MonsterCamelBullet.h"
#include "PalaceBullet.h"
#include "Player.h"
void MiddleBoss::ChangeState(MiddleBossState _State)
{
	{
		MiddleBossState NextState = _State;
		MiddleBossState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{


		case MiddleBossState::IDLESTART:
			DoorStart();
			break;

		case MiddleBossState::IDLE:
			IdleStart();
			break;
		case MiddleBossState::OPEN:
			OpenStart();
			break;
		
		case MiddleBossState::LEFTATTACK:
			LeftAttackStart();
			break;
		case MiddleBossState::MIDDLEATTACK:
			MiddleAttackStart();
			break;
		case MiddleBossState::RIGHTATTACK:
			RightAttackStart();
			break;
		case MiddleBossState::LEFTSMOKE:
			LeftSmokeStart();
			break;
		case MiddleBossState::RIGHTSMOKE:
			RightSmokeStart();
			break;
		case MiddleBossState::MIDDLESMOKE:
			MiddleSmokeStart();
			break;




		/*case MiddleBossState::UP:
			UpStart();
			break;
		case MiddleBossState::DEATH:
			DeathStart();
			break;*/

		default:
			break;
		}


	}

}
void MiddleBoss::DoorStart()
{
	AnimationCheck("Door");
}


void MiddleBoss::OpenStart()
{
	OpenCheck("Open");
}



void MiddleBoss::IdleStart()
{
	AnimationCheck("Door");
}


void MiddleBoss::LeftAttackStart()
{
	LeftAttackCheck("Attack");
}
void MiddleBoss::RightAttackStart()
{
	RightAttackCheck("Attack");
}

void MiddleBoss::MiddleAttackStart()
{
	MiddleAttackCheck("Attack");
}

void MiddleBoss::LeftSmokeStart()
{
	LeftSmokeCheck("Smoke");
}

void MiddleBoss::RightSmokeStart()
{
	RightSmokeCheck("Smoke");
}

void MiddleBoss::MiddleSmokeStart()
{
	MiddleSmokeCheck("Smoke");
}



void MiddleBoss::IdleUpdate(float _Time)
{
	if (true == AnimationLeftDoorRender->IsAnimationEnd())
	{
		ChangeState(MiddleBossState::OPEN);
		return; 
	}
}


void MiddleBoss::LeftAttackUpdate(float _Time)
{

	if (LeftHp > 0)
	{
		
		if (true == AnimationLeftHumanAttackRender->IsAnimationEnd())
		{
			if (MissileCheck == false)
			{

				Bullet = GetLevel()->CreateActor<PalaceBullet>();
				Bullet->SetPos({ GetPos().x - 220, GetPos().y - 300 });
				MissileCheck = true;
			}

			
			ChangeState(MiddleBossState::LEFTSMOKE);
			return;
		}
	}


		
	
	



}




void MiddleBoss::RightAttackUpdate(float _Time)
{
	if (RightHp > 0)
	{
		if (true == AnimationRightHumanAttackRender->IsAnimationEnd())
		{
			ChangeState(MiddleBossState::RIGHTSMOKE);
			return;
		}
	}



}


void MiddleBoss::MiddleAttackUpdate(float _Time)
{

	if (MiddleHp > 0)
	{
		if (true == AnimationMiddleHumanAttackRender->IsAnimationEnd())
		{
			ChangeState(MiddleBossState::MIDDLESMOKE);
			return;
		}
	}






}

void MiddleBoss::LeftSmokeUpdate(float _Time)
{
	AttackTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (true == AnimationLeftSmokeRender->IsAnimationEnd())
	{
		int a = rand() % 2;

		
		if (a == 0)
		{
			//AnimationRightHumanAttackRender->SetFrame(14);
			ChangeState(MiddleBossState::RIGHTATTACK);
			return;
		}
		else if (a == 1)
		{
			//AnimationMiddleHumanAttackRender->SetFrame(14);
			ChangeState(MiddleBossState::MIDDLEATTACK);
			return;
		}
	}



}


void MiddleBoss::RightSmokeUpdate(float _Time)
{

	if (true == AnimationRightSmokeRender->IsAnimationEnd())
	{
		int a = rand() % 2;

		if (a == 0)
		{
			//AnimationLeftHumanAttackRender->SetFrame(13);
			ChangeState(MiddleBossState::LEFTATTACK);
			return;
		}
		
		else if (a == 1)
		{
			//AnimationMiddleHumanAttackRender->SetFrame(13);
			ChangeState(MiddleBossState::MIDDLEATTACK);
			return;
		}
	}




	

}



void MiddleBoss::MiddleSmokeUpdate(float _Time)
{

	if (true == AnimationMiddleSmokeRender->IsAnimationEnd())
	{
		int a = rand() % 2;

	
		 if (a == 0)
		{
		//AnimationRightHumanAttackRender->SetFrame(13);
			ChangeState(MiddleBossState::RIGHTATTACK);
			return;
		}
		else if (a == 1)
		{
			//AnimationMiddleHumanAttackRender->SetFrame(13);
			ChangeState(MiddleBossState::LEFTATTACK);
			return;
		}
	}

}



void MiddleBoss::DeathStart()
{
}

void MiddleBoss::DeathUpdate(float _Time)
{

}


void MiddleBoss::OpenUpdate(float _Time)
{
	if (true == AnimationLeftHumanRender->IsAnimationEnd())
	{
		ChangeState(MiddleBossState::LEFTATTACK);
		return; 
	}
}




void MiddleBoss::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case MiddleBossState::IDLESTART:
		DoorUpdate(_Time);
		break;
	
	case MiddleBossState::IDLE:
		IdleUpdate(_Time);
		break;
	case MiddleBossState::OPEN:
		OpenUpdate(_Time);
		break;
	case MiddleBossState::LEFTATTACK:
		LeftAttackUpdate(_Time);
		break;
	case MiddleBossState::MIDDLEATTACK:
		MiddleAttackUpdate(_Time);
		break;
	case MiddleBossState::RIGHTATTACK:
		RightAttackUpdate(_Time);
		break;
	case MiddleBossState::LEFTSMOKE:
		LeftSmokeUpdate(_Time);
		break;
	case MiddleBossState::RIGHTSMOKE:
		RightSmokeUpdate(_Time);
		break;
	case MiddleBossState::MIDDLESMOKE:
		MiddleSmokeUpdate(_Time);
		break;

	default:
		break;
	}
}