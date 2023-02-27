#include "Rebel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Player.h"
#include "RebelBullet.h"
void Rebel::ChangeState(RebelState _State)
{
	{
		RebelState NextState = _State;
		RebelState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case RebelState::IDLE:
			IdleStart();
			break;
		case RebelState::IDLE2:
			Idle2Start();
			break;
		case RebelState::MOVEPRE:
			MovePreStart();
			break;
		case RebelState::MOVE:
			MoveStart();
			break;
		case RebelState::MOVEFINISH:
			MoveFinsihStart();
			break;
		case RebelState::ATTACK:
			AttackStart();
			break;
		case RebelState::DEATH:
			DeathStart();
			break;

		default:
			break;
		}


	}
	
}
void Rebel::UpdateState(float _Time)
{
	switch (StateValue)
	{


	case RebelState::IDLE:
		IdleUpdate(_Time);
		break;
	case RebelState::IDLE2:
		Idle2Update(_Time);
		break;
	case RebelState::MOVEPRE:
		MovePreUpdate(_Time);
		break;
	case RebelState::MOVE:
		MoveUpdate(_Time);
		break;
	case RebelState::MOVEFINISH:
		MoveFinsihUpdate(_Time);
		break;
	case RebelState::ATTACK:
		AttackUpdate(_Time);
		break;
	case RebelState::DEATH:
		DeathUpdate(_Time);
		break;


	default:
		break;
	}
}

void Rebel::IdleStart()
{
	DirCheck("Idle");
}


void Rebel::Idle2Start()
{
	DirCheck("Idle2");
}

void Rebel::MovePreStart()
{
	DirCheck("MovePre");
}


void Rebel::MoveStart()
{
	DirCheck("Move");
}

void Rebel::MoveFinsihStart()
{
	DirCheck("MoveFinish");
}

void Rebel::AttackStart()
{
	DirCheck("Attack");
}


void Rebel::DeathStart()
{
	DirCheck("Death");
}

void Rebel::IdleUpdate(float _Time)
{
	if (Player::MainPlayer->GetRebelStart() == true)
	{
		ChangeState(RebelState::MOVEPRE);
		return; 
	}
}

void Rebel::Idle2Update(float _Time)
{
	if (Player::MainPlayer->GetRebelStart() == true)
	{
		ChangeState(RebelState::MOVEPRE);
		return;
	}

}
void Rebel::MovePreUpdate(float _Time)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(RebelState::MOVE);
		return; 
	}
}
void Rebel::MoveUpdate(float _Time)
{
	MoveDir += float4::Right * 100; 
	
}

void Rebel::MoveFinsihUpdate(float _Time)
{
	MoveDir = { 0,0 }; 
}
void Rebel::AttackUpdate(float _Time)
{

	if (AnimationRender->GetFrame() == 10)
	{
		if (a == 0)
		{
			Actor = GetLevel()->CreateActor<RebelBullet>();
			Actor->SetPos(GetPos());
			BulletRange = GetPos().x - Player::MainPlayer->GetPos().x;


			//float BulletRange = Player::MainPlayer->GetMonsterBulletRange();
			//float a = Player::MainPlayer->GetPos().x;



			Actor->MoveDir += float4::Up * (100 + BulletRange);


			Actor->BulletMove = true;
		}
		a ++;
	}
	if (AnimationRender->GetFrame() > 12)
	{
		a = 0;
	}
	

	
}
void Rebel::DeathUpdate(float _Time)
{
}
