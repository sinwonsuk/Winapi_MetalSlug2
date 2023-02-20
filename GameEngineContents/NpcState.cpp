#include "NPC.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
void NPC::ChangeState(NpcState _State)
{
	{
		NpcState NextState = _State;
		NpcState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case NpcState::IDLE:
			IdleStart();
			break;
		case NpcState::MOVEPRE:
			MovePreStart();
			break;

		case NpcState::LEFTMOVE:
			MoveLeftStart();
			break;
		case NpcState::RIGHTMOVE:
			MoveRightStart();
			break;


		case NpcState::COLLISION:
			CollisionStart();
			break;
		case NpcState::COLLISIONAFTER:
			CollisionAfterStart();
			break;
		case NpcState::DEATH:
			DeathStart(); 
			break;
	
		default:
			break;
		}


	}

}








void NPC::UpdateState(float _Time)
{
	switch (StateValue)
	{

	
	case NpcState::IDLE:
		IdleUpdate(_Time);
		break;
	case NpcState::MOVEPRE:
		MovePreUpdate(_Time);
		break;
	case NpcState::LEFTMOVE:
		MoveLeftUpdate(_Time);
		break;
	case NpcState::RIGHTMOVE:
		MoveRightUpdate(_Time);
		break;
	case NpcState::COLLISION:
		CollisionUpdate(_Time);
		break;
	case NpcState::COLLISIONAFTER:
		CollisionAfterUpdate(_Time);
		break;

	case NpcState::DEATH:
		DeathUpdate(_Time);
		break;
	//case NpcState::UP:
	//	UpUpdate(_Time);
	//	break;


	//case NpcState::ATTACK:
	//	AttackUpdate(_Time);
	//	break;
	
	default:
		break;
	}
}


void NPC::IdleStart()
{
	DirCheck("Npc_Idle");
}
void NPC::MovePreStart()
{
	DirCheck("Npc_MovePre");
}
void NPC::MoveLeftStart()
{
	DirCheck("Left_Npc_Move");
}
void NPC::MoveRightStart()
{
	DirCheck("Right_Npc_Move");
}
void NPC::CollisionStart()
{
	DirCheck("Npc_Collision");
}
void NPC::CollisionAfterStart()
{
	DirCheck("Npc_CollisionAfter");
}
void NPC::DeathStart()
{
	DirCheck("Npc_Death");
}


void NPC::IdleUpdate(float _Time)
{

}

void NPC::MovePreUpdate(float _Time)
{
	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(NpcState::LEFTMOVE);
		return; 
	}
}



void NPC::MoveLeftUpdate(float _Time)
{
	MoveDir += float4::Left * MoveSpeed;
	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(NpcState::RIGHTMOVE);
		return;
	}

}


void NPC::MoveRightUpdate(float _Time)
{
	MoveDir += float4::Right * MoveSpeed;
	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(NpcState::LEFTMOVE);
		return; 
	}
}


void NPC::CollisionUpdate(float _Time)
{

	MoveDir.x = 0;
	if (true == AnimationRender->IsAnimationEnd() )
	{ 
		
		TimeCheck = 0;
		ChangeState(NpcState::COLLISIONAFTER);
		return;
	}
}


void NPC::CollisionAfterUpdate(float _Time)
{
	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(NpcState::DEATH);
		return;
	}
}

void NPC::DeathUpdate(float _Time)
{
	MoveDir += float4::Left * MoveSpeed;
}