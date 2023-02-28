#include "MiniBoss.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Carriage.h"

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
	MoveDir = { 0,0 };
	if (IdleCheck > 2 && Idle == false)
	{
		ChangeState(MiniMonsterState::ATTACK);
		return;
	}

	if (Carriage::carriage->GetDeath() == true)
	{
		ChangeState(MiniMonsterState::RIGHTMOVE);
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
	if (AnimationRender->IsAnimationEnd())
	{
		Idle = true;
		AttackCheck = true;
		ChangeState(MiniMonsterState::IDLE);
		return;

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