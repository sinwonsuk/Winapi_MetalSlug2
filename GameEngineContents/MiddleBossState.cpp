#include "MiddleBoss.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "MonsterCamelEffect.h"
#include "MonsterCamelBullet.h"
#include "PalaceBullet.h"
#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
void MiddleBoss::ChangeState(MiddleBossState _State)
{
	{
		MiddleBossState NextState = _State;
		MiddleBossState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{


		case MiddleBossState::IDLESTART:
			DoorStart();
			break;

		case MiddleBossState::IDLE:
			IdleStart();
			break;
		case MiddleBossState::OPEN:
			OpenStart();
			break;
		
		case MiddleBossState::LEFTATTACK:
			LeftAttackStart();
			break;
		case MiddleBossState::MIDDLEATTACK:
			MiddleAttackStart();
			break;
		case MiddleBossState::RIGHTATTACK:
			RightAttackStart();
			break;
		case MiddleBossState::LEFTSMOKE:
			LeftSmokeStart();
			break;
		case MiddleBossState::RIGHTSMOKE:
			RightSmokeStart();
			break;
		case MiddleBossState::MIDDLESMOKE:
			MiddleSmokeStart();
			break;
		case MiddleBossState::DEATH:
			DeathStart(); 
			break;




		/*case MiddleBossState::UP:
			UpStart();
			break;
		case MiddleBossState::DEATH:
			DeathStart();
			break;*/

		default:
			break;
		}


	}

}
void MiddleBoss::DoorStart()
{
	AnimationCheck("Door");
}


void MiddleBoss::OpenStart()
{
	OpenCheck("Open");
}



void MiddleBoss::IdleStart()
{
	AnimationCheck("Door");
}


void MiddleBoss::LeftAttackStart()
{
	LeftAttackCheck("Attack");
}
void MiddleBoss::RightAttackStart()
{
	RightAttackCheck("Attack");
}

void MiddleBoss::MiddleAttackStart()
{
	MiddleAttackCheck("Attack");
}

void MiddleBoss::LeftSmokeStart()
{
	LeftSmokeCheck("Smoke");
}

void MiddleBoss::RightSmokeStart()
{
	RightSmokeCheck("Smoke");
}

void MiddleBoss::MiddleSmokeStart()
{
	MiddleSmokeCheck("Smoke");
}



void MiddleBoss::IdleUpdate(float _Time)
{
	if (true == AnimationLeftDoorRender->IsAnimationEnd())
	{
		ChangeState(MiddleBossState::OPEN);
		return; 
	}
}


void MiddleBoss::LeftAttackUpdate(float _Time)
{

	if (LeftHp > 0)
	{
		
		if (true == AnimationLeftHumanAttackRender->IsAnimationEnd())
		{
			if (MissileCheck == false)
			{

				Bullet = GetLevel()->CreateActor<PalaceBullet>();
				Bullet->SetPos({ GetPos().x - 220, GetPos().y - 320 });
				MissileCheck = true;
			}

			
			ChangeState(MiddleBossState::LEFTSMOKE);
			return;
		}
	}


		
	
	



}




void MiddleBoss::RightAttackUpdate(float _Time)
{
	if (RightHp > 0)
	{
		if (true == AnimationLeftHumanAttackRender->IsAnimationEnd())
		{
			if (MissileCheck == false)
			{

				Bullet = GetLevel()->CreateActor<PalaceBullet>();
				Bullet->SetPos({ GetPos().x + 390, GetPos().y - 320 });
				MissileCheck = true;
			}

			ChangeState(MiddleBossState::RIGHTSMOKE);
			return;
			
		}

		
		
		
	}



}


void MiddleBoss::MiddleAttackUpdate(float _Time)
{

	if (MiddleHp > 0)
	{
		if (true == AnimationMiddleHumanAttackRender->IsAnimationEnd())
		{
			if (MissileCheck == false)
			{

				Bullet = GetLevel()->CreateActor<PalaceBullet>();
				Bullet->SetPos({ GetPos().x+ 110, GetPos().y - 320 });
				MissileCheck = true;
			}

			ChangeState(MiddleBossState::MIDDLESMOKE);
			return;
		}
	}






}

void MiddleBoss::LeftSmokeUpdate(float _Time)
{


	if (true == AnimationLeftSmokeRender->IsAnimationEnd())
	{
		
		
		
	}



}


void MiddleBoss::RightSmokeUpdate(float _Time)
{

	if (true == AnimationRightSmokeRender->IsAnimationEnd())
	{
		
		
	}




	

}



void MiddleBoss::MiddleSmokeUpdate(float _Time)
{

	if (true == AnimationMiddleSmokeRender->IsAnimationEnd())
	{
		
	}

}



void MiddleBoss::DeathStart()
{

}

void MiddleBoss::DeathUpdate(float _Time)
{

	DeathTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime2 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime3 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime4 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime5 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime6 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime7 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime8 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime9 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime10 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime11 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime12 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime13 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime14 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime15 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	DeathTime16 += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	
	if (DeathTime > 0.5)
	{
		if (DeathTime < 1.7)
		{

			MiddleExploision->On();
			MiddleExploision->SetPosition({ -100,0 });
			MiddleExploision->ChangeAnimation("Exploision", true);
			DeathTime = 0;
		}
	}
	if (DeathTime2 > 0.7)
	{
		if (DeathTime2 < 1.9)
		{
			MiddleExploision2->On();
			MiddleExploision2->SetPosition({ 0,100 });
			MiddleExploision2->ChangeAnimation("Exploision", true);
			DeathTime2 = 0;
		}
		
		
	}

	if (DeathTime3 > 0.9)
	{
		MiddleExploision3->On();
		MiddleExploision3->SetPosition({ 200,-200 });
		MiddleExploision3->ChangeAnimation("Exploision", true);
		DeathTime3 = 0;
	}

	if (DeathTime4 > 1.1)
	{
		MiddleExploision4->On();
		MiddleExploision4->SetPosition({ 400,-100 });
		MiddleExploision4->ChangeAnimation("Exploision", true);
		DeathTime4 = 0;
	}

	if (DeathTime5 > 1.3)
	{
		MiddleExploision5->On();
		MiddleExploision5->SetPosition({ -150,-300});
		MiddleExploision5->ChangeAnimation("Exploision", true);
		DeathTime5 = 0;
	}

	if (DeathTime6 > 1.5)
	{
		MiddleExploision6->On();
		MiddleExploision6->SetPosition({ -100,-150 });
		MiddleExploision6->ChangeAnimation("Exploision", true);
		DeathTime6 = 0;
	}
	if (DeathTime7 > 1.7)
	{
		MiddleExploision->On();
		MiddleExploision->SetPosition({ -100,0 });
		float4 a = MiddleExploision->GetPosition();
		MiddleExploision->ChangeAnimation("Exploision",true);
		DeathTime7 = 0;
	}

	if (DeathTime8 > 1.9)
	{
		MiddleExploision2->On();
		MiddleExploision2->SetPosition({ 400,100 });
		MiddleExploision2->ChangeAnimation("Exploision", true);
		DeathTime8 = 0;
	}

	if (DeathTime9 > 2.1)
	{
		SmallExploision->On();
		SmallExploision->SetPosition({ 350,0 });
		SmallExploision->ChangeAnimation("Exploision", true);
		DeathTime9 = 0;
	}
	if (DeathTime10 > 2.3)
	{
		SmallExploision2->On();
		SmallExploision2->SetPosition({ 200,0 });
		SmallExploision2->ChangeAnimation("Exploision", true);
		DeathTime10 = 0;
	}
	if (DeathTime11 > 2.5)
	{
		BigExploision->On();
		BigExploision->SetPosition({ -100,0 });
		BigExploision->ChangeAnimation("Exploision", true);
		DeathTime11 = 0;
	}

	if (DeathTime12 > 2.7)
	{
		BigExploision->On();
		BigExploision->SetPosition({ -100,0 });
		BigExploision->ChangeAnimation("Exploision", true);
		DeathTime12 = 0;
	}

	if (DeathTime13 > 2.9)
	{
		BigExploision2->On();
		BigExploision2->SetPosition({ 0,-300 });
		BigExploision2->ChangeAnimation("Exploision", true);
		DeathTime13 = 0;
	}
	if (DeathTime14 > 3.1)
	{
		BigExploision3->On();
		BigExploision3->SetPosition({ 300,-250 });
		BigExploision3->ChangeAnimation("Exploision", true);
		DeathTime14 = 0;
	}

	/*if (DeathTime15 > 3.3)
	{
		if (DeathTime15 < 3.5)
		{
			float4 MoveDir = float4::Up * 2000 * _Time;
			GetLevel()->SetCameraMove({ MoveDir });
		}
	}*/


	if (DeathTime15 > 3.3)
	{
		float4 MoveDir = float4::Up * 1000 * _Time;
		float4 MoveDir1 = float4::Down * 1000 * _Time;
		shakeTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		if (shakeTime > 0.03)
		{
			if (UpDownShake == false)
			{
				GetLevel()->SetCameraMove({ MoveDir1 });
			
				UpDownShake = true;
			}
			else if (UpDownShake == true)
			{
				GetLevel()->SetCameraMove({ MoveDir });
			
				UpDownShake = false;
			}
			shakeTime = 0;
		}
		

	}
	if (DeathTime15 > 3.5)
	{
		MoveDir1 += float4::Up * 60 * _Time;
		PalaceRightDoorEffect->On(); 
		PalaceRightDoorEffect->SetScale({ 200 + RightScale ,  200 + RightScale });
		PalaceRightDoorEffect->SetMove(MoveDir1* _Time);

		RightScale += 3;
	}
	if (DeathTime15 > 3.7)
	{
		MoveDir += float4::Up * 60 * _Time;
		PalaceLeftDoorEffect->On(); 
		PalaceLeftDoorEffect->SetScale({ 200 + LeftScale ,  200 + LeftScale });
		PalaceLeftDoorEffect->SetMove(MoveDir * _Time);

	

		LeftScale += 3;
	}
	if (DeathTime16 > 6.1)
	{
		CurPos = GetLevel()->GetCameraPos();
		DeathTime16 = 0;
	}

	if (DeathTime15 > 6.2)
	{
		
		GetLevel()->SetCameraPos({ 3000,3000 });
	}
	
	if (DeathTime15 > 6.4)
	{
		GetLevel()->SetCameraPos({ CurPos.x,CurPos.y+60});
		Player::MainPlayer->MiddlebossBoom = true;
		this->Death(); 
		return;

	}


	/*if (MiddleExploision->IsAnimationEnd())
	{
		MiddleExploision->Off();
	}*/









}


void MiddleBoss::OpenUpdate(float _Time)
{
	if (true == AnimationLeftHumanRender->IsAnimationEnd())
	{
		AttackCheck = true; 
		ChangeState(MiddleBossState::LEFTATTACK);
		return; 
	}
}




void MiddleBoss::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case MiddleBossState::IDLESTART:
		DoorUpdate(_Time);
		break;
	
	case MiddleBossState::IDLE:
		IdleUpdate(_Time);
		break;
	case MiddleBossState::OPEN:
		OpenUpdate(_Time);
		break;
	case MiddleBossState::LEFTATTACK:
		LeftAttackUpdate(_Time);
		break;
	case MiddleBossState::MIDDLEATTACK:
		MiddleAttackUpdate(_Time);
		break;
	case MiddleBossState::RIGHTATTACK:
		RightAttackUpdate(_Time);
		break;
	case MiddleBossState::LEFTSMOKE:
		LeftSmokeUpdate(_Time);
		break;
	case MiddleBossState::RIGHTSMOKE:
		RightSmokeUpdate(_Time);
		break;
	case MiddleBossState::MIDDLESMOKE:
		MiddleSmokeUpdate(_Time);
		break;
	case MiddleBossState::DEATH:
		DeathUpdate(_Time); 
		break;

	default:
		break;
	}
}