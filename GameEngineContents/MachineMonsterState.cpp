#include "MachineMonster.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MachineMonsterBullet.h"
void MachineMonster::ChangeState(MachineState _State)
{
	{
		MachineState NextState = _State;
		MachineState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case MachineState::IDLE:
			IdleStart();
			break;
			
		case MachineState::MOVE:
			MoveStart();
			break;
		case MachineState::ATTACKPRE:
			AttackPreStart();
			break;
		case MachineState::ATTACKPRE2:
			AttackPre2Start();
			break;
		case MachineState::ATTACK:
			AttackStart();
			break;
		case MachineState::DEATH:
			DeathStart();
			break;

		default:
			break;
		}


	}

}
void MachineMonster::IdleStart()
{
	DirCheck("Idle");
}
void MachineMonster::AttackPreStart()
{
	DirCheck("AttackPre");
}
void MachineMonster::MoveStart()
{
	DirCheck("Move");
}
void MachineMonster::AttackStart()
{
	DirCheck("Attack");
}


void MachineMonster::DeathStart()
{
	DirCheck("Death");
}

void MachineMonster::IdleUpdate(float _Time)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(MachineState::MOVE);
		return; 
	}
}

void MachineMonster::AttackPreUpdate(float _Time)
{
	MoveDir = { 0,0 }; 

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(MachineState::ATTACKPRE2);
		return;
	}

}

void MachineMonster::AttackPre2Start()
{
	DirCheck("AttackPre2"); 
}

void MachineMonster::AttackPre2Update(float _Time)
{
	AttackCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (AttackCheck > 2)
	{
		ChangeState(MachineState::ATTACK);
		return;
	}


}

void MachineMonster::MoveUpdate(float _Time)
{
	MoveDir += float4::Left * MoveSpeed;
	if (GetPos().x < 8200)
	{
		ChangeState(MachineState::ATTACKPRE);
		return; 
	}



}

void MachineMonster::AttackUpdate(float _Time)
{
	AttackCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	if (AttackCheck > 0.3)
	{
		MachineMonsterBullet * Actor = GetLevel()->CreateActor<MachineMonsterBullet>();
		Actor->SetPos({ GetPos().x - 100 ,GetPos().y - 100 });

		Actor->MoveDir = float4::Left * 1000;
		AttackNumber++;
		AttackCheck = 0;
	}
	
	if (AttackNumber > 3)
	{
		AttackNumber = 0;
		ChangeState(MachineState::ATTACKPRE2);
		return;
	}

		
		
	
	
}

void MachineMonster::DeathUpdate(float _Time)
{

	if (SoundCheck == false)
	{
		DeathSound = GameEngineResources::GetInst().SoundPlayToControl("MonsterExploision.mp3");
		DeathSound.LoopCount(1);
		SoundCheck = true;
	}



	Effect->On(); 
	DeathCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (DeathCheck > 2)
	{
		this->Death(); 
	}

}



void MachineMonster::UpdateState(float _Time)
{
	switch (StateValue)
	{


	case MachineState::IDLE:
		IdleUpdate(_Time);
		break;
	case MachineState::MOVE:
		MoveUpdate(_Time);
		break;
	case MachineState::ATTACKPRE:
		AttackPreUpdate(_Time);
		break;
	case MachineState::ATTACKPRE2:
		AttackPre2Update(_Time);
		break;
	case MachineState::ATTACK:
		AttackUpdate(_Time);
		break;
	case MachineState::DEATH:
		DeathUpdate(_Time);
		break;


	default:
		break;
	}
}
