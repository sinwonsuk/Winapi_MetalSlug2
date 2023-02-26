#include "Carriage.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
void Carriage::ChangeState(CarriageState _State)
{
	{
		CarriageState NextState = _State;
		CarriageState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case CarriageState::IDLE:
			IdleStart();
			break;
		case CarriageState::STOP:
			StopStart();
			break;

	


		case CarriageState::DEATH:
			DeathStart();
			break;

		default:
			break;
		}


	}

}

void Carriage::StopStart()
{
	DirCheck("Carriage");
}

void Carriage::StopUpdate(float _Time)
{
	
}

void Carriage::IdleStart()
{
	DirCheck("CarriageMove");
}

void Carriage::IdleUpdate(float _Time)
{
	

	if (GetPos().x > 5000)
	{
		MoveDir += float4::Left * 1000;
	}

	if (GetPos().x < 5000)
	{
		MoveDir.x = 0;
		if (true == AnimationRender->IsAnimationEnd())
		{
			ChangeState(CarriageState::STOP); 
			return;
		}
	
	}




}

void Carriage::DeathStart()
{
	DirCheck("CarriageDestory");
}

void Carriage::DeathUpdate(float _Time)
{

}








void Carriage::UpdateState(float _Time)
{
	switch (StateValue)
	{


	case CarriageState::IDLE:
		IdleUpdate(_Time);
		break;
	case CarriageState::STOP:
		StopUpdate(_Time);
		break;
	case CarriageState::DEATH:
		DeathUpdate(_Time);
		break;

	default:
		break;
	}
}