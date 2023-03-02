#include "RunMonster.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MiniBoss.h"
void RunMonster::ChangeState(RunMonsterState _State)
{
	{
		RunMonsterState NextState = _State;
		RunMonsterState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case RunMonsterState::IDLE:
			IdleStart();
			break;
		case RunMonsterState::MOVE:
			MoveStart();
			break;
		case RunMonsterState::DEATHTWO:
			DeathTwoStart();
			break;
		case RunMonsterState::DEATH:
			DeathStart();
			break;

		default:
			break;
		}


	}

}

void RunMonster::MoveUpdate(float _Time)
{
	MoveCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	MoveDir += float4::Left * 100; 





	if (MoveCheck > 3.5 && Idle == true)
	{
		//MoveCheck = 0;
		ChangeState(RunMonsterState::IDLE);
		return; 
	}
}

void RunMonster::MoveStart()
{
	DirCheck("Move");
}

void RunMonster::IdleStart()
{
	DirCheck("Idle"); 
}

void RunMonster::DeathTwoStart()
{
	DirCheck("DeathTwo");
}

void RunMonster::DeathStart()
{
	DirCheck("Death");
}

void RunMonster::IdleUpdate(float _Time)
{
	
	MoveDir.x = 0;



	if (MiniBoss::miniboss->GetAttackCheck() ==true)
	{
		Idle = false;
		ChangeState(RunMonsterState::MOVE);
		return;
	}
}


void RunMonster::DeathUpdate(float _Time)
{
	//MoveDir = { 0,0 };
}



void RunMonster::DeathTwoUpdate(float _Time)
{
	MoveDir = { 0,0 };
}

void RunMonster::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case RunMonsterState::IDLE:
		IdleUpdate(_Time);
		break;
	
	case RunMonsterState::DEATH:
		DeathUpdate(_Time);
		break;
	case RunMonsterState::MOVE:
		MoveUpdate(_Time);
		break;
	case RunMonsterState::DEATHTWO:
		DeathTwoUpdate(_Time);
		break;
	default:
		break;
	}
}