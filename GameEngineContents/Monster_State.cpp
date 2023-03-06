#include "Monster.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineTime.h>
#include "MonsterBullet.h"
#include "Player.h"
void Monster::ChangeState(MonsterState _State)
{
	{
		MonsterState NextState = _State;
		MonsterState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{
		case MonsterState::IDLE:
			 IdleStart();
			 break;
		case MonsterState::MOVE:
			 MoveStart();
			 break;	
		case MonsterState::ATTACKPRE:
			AttackPreStart();
			break;
		case MonsterState::PlAYERCHECK:
			PlayerCheckStart(); 
			break;
		case MonsterState::ATTACK:
			AttackStart(); 
			break;
		case MonsterState::MONSTERBULLET:
			MonsterBulletStart(); 
			break;
		case MonsterState::JUMP:
			MonsterJumpStart();
			break;
		case MonsterState::JUMPBACK:
			MonsterBackJumpStart();
			break;
		case MonsterState::DEATHONE:
			MonsterDeathOneStart();
			break;
		case MonsterState::DEATHTWO:
			MonsterDeathTwoStart();
			break;
			default:
				break;
		}

			
	}
	
}

void Monster::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case MonsterState::IDLE:
		IdleUpdate(_Time);
		break;
	case MonsterState::MOVE:
		MoveUpdate(_Time);
		break;
	case MonsterState::ATTACKPRE:
		AttackPreUpdate(_Time);
		break;
	case MonsterState::PlAYERCHECK:
		PlayerCheckUpdate(_Time);
		break;
	case MonsterState::ATTACK:
		AttackUpdate(_Time);
		break;
	case MonsterState::MONSTERBULLET:
		MonsterBulletUpdate(_Time);
		break;
	case MonsterState::JUMP:
		MonsterJumpUpdate(_Time);
		break;
	case MonsterState::JUMPBACK:
		MonsterBackJumpUpdate(_Time);
		break;
	case MonsterState::DEATHONE:
		MonsterDeathOneUpdate(_Time);
		break;
	case MonsterState::DEATHTWO:
		MonsterDeathTwoUpdate(_Time);
		break;
	default:
		break;
	}
}

void Monster::IdleStart()
{
	DirCheck("Idle"); 
}
void Monster::MoveStart()
{
	DirCheck("Move");
}
void Monster::AttackStart()
{
	DirCheck("Attack");
}
void Monster::AttackPreStart()
{
	DirCheck("AttackPre");
}
void Monster::PlayerCheckStart()
{
	DirCheck("PlayerCheck");
}
void Monster::MonsterBulletStart()
{
	DirCheck("MonsterNife");
}
void Monster::MonsterJumpStart()
{
	DirCheck("MonsterJump");
}
void Monster::MonsterBackJumpStart()
{
	DirCheck("MonsterBackJump");
}

void Monster::MonsterDeathOneStart()
{
	DirCheck("DeathOne");
}

void Monster::MonsterDeathTwoStart()
{
	DirCheck("DeathTwo");
}

void Monster::IdleUpdate(float _Time)
{	
	if (RunCheck == false)
	{
		ChangeState(MonsterState::IDLE);
		return; 
	}


	else if (MoveDir.y < 0)
	{
		ChangeState(MonsterState::MOVE);
		return;
	}



}



void Monster::MoveUpdate(float _Time)
{
	if (RunCheck == false)
	{
		MoveDir = { 0,0 }; 
	}
	else if(RunCheck == true)
	{
		MoveDir += float4::Left * JumpSpeed;
	}
	
	
}


void Monster::AttackPreUpdate(float _Time)
{
	MoveDir = { 0,0 };
	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(MonsterState::ATTACK);
		return; 
	}
}


void Monster::PlayerCheckUpdate(float _Time)
{
	MoveDir = { 0,0 };

	AnimationCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();

	if (AnimationCheck > 0.5)
	{
		ChangeState(MonsterState::ATTACKPRE);
		AnimationCheck = 0;
		return;
	}
	
}

void Monster::AttackUpdate(float _Time)
{


	if (AnimationRender->GetFrame() == 7)
	{
		if (a == 0)
		{
			Actor = GetLevel()->CreateActor<MonsterBullet>();
			Actor->SetPos(GetPos());
			BulletRange = GetPos().x - Player::MainPlayer->GetPos().x;
				
			Actor->MoveDir += float4::Left * (10 + BulletRange);
			
			Actor->MoveDir += float4::Up* (250 + BulletRange);
			Actor->MonsterBulletMove = true;
		}
		
		a++;		
	}

	if (true == AnimationRender->IsAnimationEnd())
	{
		a = 0;
		ChangeState(MonsterState::PlAYERCHECK);
		return;
	}
}

void Monster::MonsterBulletUpdate(float _Time)
{
	
	
}


void Monster::MonsterJumpUpdate(float _Time)
{
	//if (MoveDir.y > 0)
	//{
	//	ChangeState(MonsterState::IDLE);
	//}
}


void Monster::MonsterBackJumpUpdate(float _Time)
{
	MoveDir.x = 0;

	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(MonsterState::JUMP);
		return;
	}
}

void Monster::MonsterDeathOneUpdate(float _Time)
{
	
	SetMove(-MoveDir * _Time);

	if (true == AnimationRender->IsAnimationEnd())
	{
		DeathCheck = true;
		
	}
}


void Monster::MonsterDeathTwoUpdate(float _Time)
{
	SetMove(-MoveDir * _Time);
	

	if (true == AnimationRender->IsAnimationEnd())
	{
		DeathCheck = true;	
	}
}


