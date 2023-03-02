#include "NPC.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Items.h"
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
		case NpcState::BIND:
			BindStart();
			break;
		case NpcState::DOWN:
			DownStart();
			break;
		case NpcState::MOVEDOWN:
			MoveDownStart();
			break;
		case NpcState::BINDMOVEPRE:
			BindMovePre(); 
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
	case NpcState::BIND:
		BindUpdate(_Time);
		break;
	case NpcState::DOWN:
		DownUpdate(_Time);
		break;
	case NpcState::MOVEDOWN:
		MoveDownUpdate(_Time);
		break;
	case NpcState::BINDMOVEPRE:
		BindMovePreUpdate(_Time);
		break;
	case NpcState::DEATH:
		DeathUpdate(_Time);
		break;
	
	
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
void NPC::BindStart()
{
	DirCheck("Npc_Bind");
}
void NPC::DownStart()
{
	DirCheck("Npc_Down");
}
void NPC::MoveDownStart()
{
	DirCheck("Npc_MoveDown");
}
void NPC::BindMovePre()
{
	DirCheck("Npc_BindMovePre");
}

void NPC::IdleUpdate(float _Time)
{

}


void NPC::MovePreUpdate(float _Time)
{

	if (true == AnimationRender->IsAnimationEnd() &&DownCheck == false)
	{
		ChangeState(NpcState::LEFTMOVE);
		return; 
	}

	if (true == AnimationRender->IsAnimationEnd() && DownCheck == true)
	{
		DownCheck = false;
		ChangeState(NpcState::MOVEDOWN);
		return;
	}

}



void NPC::MoveLeftUpdate(float _Time)
{

	MoveDir += float4::Left * MoveSpeed;
	if (Turn == true)
	{
		if (true == AnimationRender->IsAnimationEnd())
		{
			ChangeState(NpcState::RIGHTMOVE);
			return;
		}
	}



	if(MoveDir.y -2> 0)
	{
		ChangeState(NpcState::DOWN);
		return; 
	}
	/*float CurPos = GetPos().y;

	float4 NextPos = GetPos() + MoveDir * _Time;
	if (MoveDir.y < -0.5)
	{
		ChangeState(NpcState::DOWN);
	}*/



}


void NPC::MoveRightUpdate(float _Time)
{
	MoveDir += float4::Right * MoveSpeed;
	if (Turn == true)
	{

		if (true == AnimationRender->IsAnimationEnd())
		{
			ChangeState(NpcState::LEFTMOVE);
			return;
		}
	}
	if (MoveDir.y-2 > 0)
	{
		ChangeState(NpcState::DOWN);
		return;

	}
	/*float CurPos = GetPos().y;

	float4 NextPos = GetPos() + MoveDir * _Time;
	if (CurPos-2 < NextPos.y)
	{
		ChangeState(NpcState::DOWN);
		return;
	}*/


}


void NPC::CollisionUpdate(float _Time)
{

	MoveDir.x = 0;
	if (true == AnimationRender->IsAnimationEnd())
	{
		if (ItemCheck == true)
		{
			TimeCheck = 0;
			Items* Actor = GetLevel()->CreateActor<Items>();
			Actor->SetPos({ GetPos().x - 50,GetPos().y });
			Actor->SetGunBoombChangeCheck(true);
			ChangeState(NpcState::COLLISIONAFTER);
			return;
		}

		if (ItemCheck == false)
		{
			TimeCheck = 0;
			Items* Actor = GetLevel()->CreateActor<Items>();
			Actor->SetPos({ GetPos().x - 50,GetPos().y });
			Actor->SetGunBoombChangeCheck(true);
			ChangeState(NpcState::COLLISIONAFTER);
			return;
		}










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



void NPC::BindUpdate(float _Time)
{
}



void NPC::DownUpdate(float _Time)
{	
	Turn = true;	
}


void NPC::MoveDownUpdate(float _Time)
{
	MoveDir = float4::Down * 50;


	if (AnimationRender->IsAnimationEnd())
	{
		//MoveDir = { 0,0 };
		ChangeState(NpcState::DOWN);
		return; 
	}
}

void NPC::DeathUpdate(float _Time)
{
	death = true; 
	MoveDir += float4::Left * MoveSpeed;
}



void NPC::BindMovePreUpdate(float _Time)
{
	if (true == AnimationRender->IsAnimationEnd())
	{
		ChangeState(NpcState::LEFTMOVE);
		return;
	}

}
