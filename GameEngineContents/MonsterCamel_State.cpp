#include "MonsterCamel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MonsterCamelEffect.h"
#include "MonsterCamelBullet.h"
void MonsterCamel::ChangeState(MonsterCamelState _State)
{
	{
		MonsterCamelState NextState = _State;
		MonsterCamelState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{
		case MonsterCamelState::IDLESTART:
			MonsterStart();
			break;



		case MonsterCamelState::IDLE:
			IdleStart();
			break;
		case MonsterCamelState::MOVE:
			MoveStart();
			break;
		case MonsterCamelState::ATTACKPRE:
			AttackPreStart();
			break;
		
		case MonsterCamelState::ATTACK:
			AttackStart();
			break;
		case MonsterCamelState::UP:
			UpStart();
			break;
		case MonsterCamelState::DEATH:
			DeathStart();
			break;

		default:
			break;
		}


	}

}






void MonsterCamel::UpdateState(float _Time)
{
	switch (StateValue)
	{

	case MonsterCamelState::IDLESTART:
		MonsterUpdate(_Time);
		break;
	case MonsterCamelState::IDLE:
		IdleUpdate(_Time);
		break;
	case MonsterCamelState::MOVE:
		MoveUpdate(_Time);
		break;
	case MonsterCamelState::ATTACKPRE:
		AttackPreUpdate(_Time);
		break;
	case MonsterCamelState::UP:
		UpUpdate(_Time);
		break;


	case MonsterCamelState::ATTACK:
		AttackUpdate(_Time);
		break;
	case MonsterCamelState::DEATH:
		DeathUpdate(_Time);
		break;


	default:
		break;
	}
}
void MonsterCamel::MonsterStart()
{
	DirBodyCheck("Body_Idle","Reg_Move");
}
void MonsterCamel::IdleStart()
{

	DirBodyCheck("Body_Idle", "Reg_Idle");
}

void MonsterCamel::MoveStart()
{
	
	DirBodyCheck("Body_Move", "Reg_Move");

}
void MonsterCamel::AttackPreStart()
{
	DirBodyCheck("Reg_AttackPre" ,"Body_AttackPre");
}

void MonsterCamel::AttackStart()
{
	DirBodyCheck("Reg_Attack", "Body_Attack");
}

void MonsterCamel::UpStart()
{
	DirBodyCheck("Reg_Up", "Body_Up");
}
void MonsterCamel::DeathStart()
{
	DirBodyCheck("Body_Death", "Reg_Death");
}

void MonsterCamel::MonsterUpdate(float _Time)
{
	MoveDir += float4::Left * 600;

}


void MonsterCamel::IdleUpdate(float _Time)
{
	MoveDir = { 0,0 };
	if (AnimationRegRender->GetFrame() == 2)
	{
		//Effect = GetLevel()->CreateActor<MonsterCamelEffect>(); 
		if (EffectCheck == false)
		{
			MonsterCamelEffect *Effect = GetLevel()->CreateActor<MonsterCamelEffect>();
			EffectCheck = true;

		}
		
	}

	if (AnimationRegRender->IsAnimationEnd())
	{
		ChangeState(MonsterCamelState::MOVE);
		return;
	}

}



void MonsterCamel::MoveUpdate(float _Time)
{
	//float4 CorPos = MoveDir;
	float a = GetPos().x;
	
	LeftRightTimeCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 

	if( LeftRightTimeCheck > 0)
	{
		if (LeftRightTimeCheck < 1)
		{
			
			MoveDir.x = 0;
			MoveDir = float4::Right * 300;
		}
	}
	if (  LeftRightTimeCheck> 1)
	{
		if ( LeftRightTimeCheck < 2)
		{
			
			MoveDir.x = 0;
			MoveDir = float4::Left * 300;
			
		}

		if (LeftRightTimeCheck > 2)
		{
			LeftRightTimeCheck = 0;
			LeftRightCount += 1;
			
		}
			

	}
	

	if (LeftRightCount == 2)
	{
		ChangeState(MonsterCamelState::ATTACKPRE);
		LeftRightCount = 0;
		return;
	}
	
	


	
}



void MonsterCamel::AttackUpdate(float _Time)
{
	if (AnimationRegRender->GetFrame() == 5 && AttackCheck == false)
	{
		MonsterCamelBullet* Bullet = GetLevel()->CreateActor<MonsterCamelBullet>();
		Bullet->SetMove({ GetPos().x-100, GetPos().y-85 });
		AttackCheck = true;
	}
	if (AnimationRegRender->GetFrame() > 5)
	{
		AttackCheck = false;
	}


	if (AnimationRegRender->IsAnimationEnd())
	{
		ChangeState(MonsterCamelState::UP);
		
		return; 
	}
}



void MonsterCamel::AttackPreUpdate(float _Time)
{
	MoveDir = { 0,0 }; 

	if (AnimationRegRender->IsAnimationEnd())
	{
		ChangeState(MonsterCamelState::ATTACK);
		return; 
	}
}



void MonsterCamel::UpUpdate(float _Time)
{
	if (AnimationRegRender->IsAnimationEnd())
	{
		ChangeState(MonsterCamelState::MOVE);
		return;
	}
}



void MonsterCamel::DeathUpdate(float _Time)
{
	
	if (DeathSound == false)
	{
		DeathOne = GameEngineResources::GetInst().SoundPlayToControl("DeathTwo.mp3");
		DeathOne.LoopCount(1);
		DeathSound = true;
	}

	float4 a = float4::Left * 800 * _Time; 

	if (true == AnimationBodyRender->IsAnimationEnd())
	{
		AnimationBodyRender->Off();
	}
	AnimationRegRender->SetMove({ a });
}



