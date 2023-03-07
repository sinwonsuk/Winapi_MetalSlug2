#include "MiniBoss.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Carriage.h"
#include "Player.h"
#include "Boss.h"
void MiniBoss::ChangeState(MiniMonsterState _State)
{
	{
		MiniMonsterState NextState = _State;
		MiniMonsterState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case MiniMonsterState::IDLE:
			IdleStart();
			break;
		case MiniMonsterState::IDLE2:
			IdleStart();
			break;
		case MiniMonsterState::LEFTMOVE:
			LeftMoveStart(); 
			break;
		case MiniMonsterState::RIGHTMOVE:
			RightMoveStart();
			break;
		case MiniMonsterState::ATTACK:
			AttackStart();
			break;
		case MiniMonsterState::SURRENDER:
			SurrenderStart();
			break;
		default:
			break;
		}


	}

}

void MiniBoss::Idle2Update(float _Time)
{
}

void MiniBoss::IdleStart()
{
	DirCheck("Idle"); 
}
void MiniBoss::LeftMoveStart()
{
	DirCheck("Left_Move");
}
void MiniBoss::RightMoveStart()
{
	DirCheck("Right_Move");
}
void MiniBoss::AttackStart()
{
	DirCheck("Attack");
}
void MiniBoss::SurrenderStart()
{
	DirCheck("Surrender");
}



void MiniBoss::IdleUpdate(float _Time)
{
	IdleCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	MoveDir.x = 0;
	if (compulsionAttack != true)
	{

		if (IdleCheck > 2 && Idle == false)
		{
			ChangeState(MiniMonsterState::ATTACK);
			return;
		}
	}
	
	if (compulsionAttack != true)
	{
		if (Carriage::carriage->GetDeath() == true)
		{
			ChangeState(MiniMonsterState::RIGHTMOVE);
		}
	}


	if (Player::MainPlayer->GetPos().x > 6500)
	{
		ChangeState(MiniMonsterState::ATTACK);
		return;
	}

}
void MiniBoss::LeftMoveUpdate(float _Time)
{
	MoveCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	MoveDir += float4::Left * 100;


	if (MoveCheck > 4.5)
	{
		ChangeState(MiniMonsterState::IDLE);
		return;
	}

}
void MiniBoss::RightMoveUpdate(float _Time)
{
	MoveDir += float4::Right * 1000;

	DeathTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (DeathTime > 1)
	{
		this->Death(); 
	}


}
void MiniBoss::AttackUpdate(float _Time)
{
	if (FinishCheck == true)
	{
		if (Boss::boss->Hp <= 0)
		{
			
			ChangeState(MiniMonsterState::SURRENDER);
			
		}
	}



	if (FinishCheck == false)
	{
		if (AnimationRender->IsAnimationEnd())
		{
			if (compulsionAttack == false)
			{
				Idle = true;
				AttackCheck = true;
				ChangeState(MiniMonsterState::IDLE);
				return;
			}

			if (compulsionAttack == true)
			{
				AttackCheck = true;
				ChangeState(MiniMonsterState::RIGHTMOVE);
				return;
			}


		}
	}
}
void MiniBoss::SurrenderUpdate(float _Time)
{
}




void MiniBoss::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case MiniMonsterState::IDLE:
		IdleUpdate(_Time);
		break;
	case MiniMonsterState::IDLE2:
		Idle2Update(_Time);
		break;
	case MiniMonsterState::LEFTMOVE:
		LeftMoveUpdate(_Time);
		break;
	case MiniMonsterState::RIGHTMOVE:
		RightMoveUpdate(_Time);
		break;
	case MiniMonsterState::ATTACK:
		AttackUpdate(_Time);
		break;
	case MiniMonsterState::SURRENDER:
		SurrenderUpdate(_Time);
		break;
	default:
		break;
	}
}