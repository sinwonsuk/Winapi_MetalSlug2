#include "BossSmallMonster.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MonsterBullet.h"
#include "Player.h"


void BossSmallMonster::ChangeState(SmallMonsterState _State)
{
	{
		SmallMonsterState NextState = _State;
		SmallMonsterState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case SmallMonsterState::LEFTIDLE:
			LeftIdleStart();
			break;
		case SmallMonsterState::RIGHTIDLE:
			RightIdleStart();
			break;
		case SmallMonsterState::LEFTMOVE:
			LeftMoveStart();
			break;
		case SmallMonsterState::RIGHTMOVE:
			RightMoveStart();
			break;
		case SmallMonsterState::LEFTJUMP:
			LeftJumpStart();
			break;
		case SmallMonsterState::RIGHTJUMP:
			RightJumpStart();
			break;
		case SmallMonsterState::LEFTATTACK:
			LeftAttackStart();
			break;
		case SmallMonsterState::RIGHTATTACK:
			RightAttackStart();
			break;
		case SmallMonsterState::LEFTDEATH:
			LeftDeathStart();
			break;
		case SmallMonsterState::RIGHTDEATH:
			RightDeathStart();
			break;
	

		default:
			break;
		}


	}

}
void BossSmallMonster::LeftIdleStart()
{
	AnimationCheck("MonsterIdle");
}

void BossSmallMonster::RightIdleStart()
{
	AnimationCheck("RightMonsterIdle");
}

void BossSmallMonster::LeftMoveStart()
{
	AnimationCheck("MonsterMove");
}

void BossSmallMonster::RightMoveStart()
{
	AnimationCheck("RightMonsterMove");
}

void BossSmallMonster::LeftJumpStart()
{
	AnimationCheck("MonsterJump");
}

void BossSmallMonster::RightJumpStart()
{
	AnimationCheck("RightMonsterJump");
}

void BossSmallMonster::LeftAttackStart()
{
	AnimationCheck("MonsterAttack");
}
void BossSmallMonster::RightAttackStart()
{
	AnimationCheck("RightMonsterAttack");
}
void BossSmallMonster::LeftDeathStart()
{
	AnimationCheck("MonsterDeath");
}
void BossSmallMonster::RightDeathStart()
{
	AnimationCheck("RightMonsterDeath");
}

void BossSmallMonster::LeftIdleUpdate(float _Time)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(SmallMonsterState::LEFTATTACK);
		return;
	}
}

void BossSmallMonster::RightIdleUpdate(float _Time)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(SmallMonsterState::RIGHTATTACK);
		return;
	}
}

void BossSmallMonster::LeftMoveUpdate(float _Time)
{
	MoveDir += float4::Left * 200.0f;
}

void BossSmallMonster::RightMoveUpdate(float _Time)
{
	MoveDir += float4::Right * 200.0f;
}

void BossSmallMonster::LeftJumpUpdate(float _Time)
{	
	MoveDir += float4::Left * 200.0f;
}

void BossSmallMonster::RightJumpUpdate(float _Time)
{
	MoveDir += float4::Right * 200.0f;
}

void BossSmallMonster::LeftAttackUpdate(float _Time)
{
	if (AnimationRender->GetFrame() == 7)
	{
		if (AttackNumber == 0)
		{
			MonsterBullet *Actor = GetLevel()->CreateActor<MonsterBullet>();
			Actor->SetPos(GetPos());
			BulletRange = GetPos().x - Player::MainPlayer->GetPos().x;

			Actor->MoveDir += float4::Left * (50 + BulletRange);
			Actor->MoveDir += float4::Up * 600;
			Actor->MonsterBulletMove = true;
		}

		AttackNumber++;
		return;
	}
	if (true == AnimationRender->IsAnimationEnd())
	{
		AttackNumber = 0;
		
		return;
	}

}

void BossSmallMonster::RightAttackUpdate(float _Time)
{
	if (AnimationRender->GetFrame() == 7)
	{
		if (AttackNumber == 0)
		{
			MonsterBullet* Actor = GetLevel()->CreateActor<MonsterBullet>();
			Actor->SetPos(GetPos());
			BulletRange = GetPos().x - Player::MainPlayer->GetPos().x;

			Actor->MoveDir += float4::Right * (50 + abs(BulletRange));
			Actor->MoveDir += float4::Up * 600;
		//	Actor->MonsterBulletMove = true;
		}

		AttackNumber++;
		return;
	}
	if (true == AnimationRender->IsAnimationEnd())
	{
		AttackNumber = 0;

		return;
	}
}

void BossSmallMonster::LeftDeathUpdate(float _Time)
{
	

	SetMove(-MoveDir * _Time);	
}

void BossSmallMonster::RightDeathUpdate(float _Time)
{

	SetMove(-MoveDir * _Time);
	
}



void BossSmallMonster::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case SmallMonsterState::LEFTIDLE:
		LeftIdleUpdate(_Time);
		break;
	case SmallMonsterState::RIGHTIDLE:
		RightIdleUpdate(_Time);
		break;
	case SmallMonsterState::LEFTMOVE:
		LeftMoveUpdate(_Time);
		break;
	case SmallMonsterState::RIGHTMOVE:
		RightMoveUpdate(_Time);
		break;
	case SmallMonsterState::LEFTJUMP:
		LeftJumpUpdate(_Time);
		break;
	case SmallMonsterState::LEFTATTACK:
		LeftAttackUpdate(_Time);
		break;
	case SmallMonsterState::RIGHTATTACK:
		RightAttackUpdate(_Time);
		break;
	case SmallMonsterState::RIGHTJUMP:
		RightJumpUpdate(_Time);
		break;
	case SmallMonsterState::LEFTDEATH:
		LeftDeathUpdate(_Time);
		break;
	case SmallMonsterState::RIGHTDEATH:
		RightDeathUpdate(_Time);
		break;
	default:
		break;
	}
}
