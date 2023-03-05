#include "BazookaMonster.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Boss.h"
void BazookaMonster::ChangeState(BazookaMonsterState _State)
{
	{
		BazookaMonsterState NextState = _State;
		BazookaMonsterState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{		
		case BazookaMonsterState::LEFTMOVE:
			LeftMoveStart();
			break;
		case BazookaMonsterState::RIGHTMOVE:
			RightMoveStart();
			break;		
		case BazookaMonsterState::LEFTATTACKPRE:
			LeftAttackPreStart();
			break;
		case BazookaMonsterState::RIGHTATTACKPRE:
			RightAttackPreStart();
			break;
		case BazookaMonsterState::LEFTATTACK:
			LeftAttackStart();
			break;
		case BazookaMonsterState::RIGHTATTACK:
			RightAttackStart();
			break;
     	case BazookaMonsterState::DEATH:
			DeathStart();
			break;

		default:
			break;
		}


	}

}

void BazookaMonster::LeftMoveStart()
{
	AnimationCheck("LeftMove");
}

void BazookaMonster::RightMoveStart()
{
	AnimationCheck("RightMove");
}
void BazookaMonster::LeftAttackPreStart()
{
	AnimationCheck("LeftPreAttack");
}
void BazookaMonster::RightAttackPreStart()
{
	AnimationCheck("RighPretAttack");
}
void BazookaMonster::LeftAttackStart()
{
	AnimationCheck("LeftAttack");
}
void BazookaMonster::RightAttackStart()
{
	AnimationCheck("RightAttack");
}

void BazookaMonster::DeathStart()
{

}
void BazookaMonster::LeftMoveUpdate(float _Time)
{
	MoveDir += float4::Left * 200; 



}


void BazookaMonster::RightMoveUpdate(float _Time)
{
	MoveDir += float4::Right * 200;
}


void BazookaMonster::LeftAttackPreUpdate(float _Time)
{
	LeftMoveCheck = true;


	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(BazookaMonsterState::LEFTATTACK);
		return;
	}
}


void BazookaMonster::RightAttackPreUpdate(float _Time)
{
	
	RightMoveCheck = true;

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(BazookaMonsterState::RIGHTATTACK);
		return;
	}
}



void BazookaMonster::LeftAttackUpdate(float _Time)
{
	

	AttackTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (AttackTime > 3)
	{
		
		ChangeState(BazookaMonsterState::LEFTATTACK);

		AttackTime = 0;
	}



}



void BazookaMonster::RightAttackUpdate(float _Time)
{
	AttackTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (AttackTime > 3)
	{

		ChangeState(BazookaMonsterState::RIGHTATTACK);

		AttackTime = 0;
	}



}



void BazookaMonster::DeathUpdate(float _Time)
{
}

void BazookaMonster::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case BazookaMonsterState::LEFTMOVE:
		LeftMoveUpdate(_Time);
		break;
	case BazookaMonsterState::RIGHTMOVE:
		RightMoveUpdate(_Time);
		break;
	case BazookaMonsterState::LEFTATTACKPRE:
		LeftAttackPreUpdate(_Time);
		break;
	case BazookaMonsterState::RIGHTATTACKPRE:
		RightAttackPreUpdate(_Time);
		break;
	case BazookaMonsterState::LEFTATTACK:
		LeftAttackUpdate(_Time);
		break;
	case BazookaMonsterState::RIGHTATTACK:
		RightAttackUpdate(_Time);
		break;
	case BazookaMonsterState::DEATH:
		DeathStart();
		break;

	default:
		break;
	}
}
