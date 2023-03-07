#include "Boss.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "BazookaMonster.h"

void Boss::ChangeState(BossState _State)
{
	{
		BossState NextState = _State;
		BossState PrevState = StateValue;

		StateValue = NextState;

		switch (NextState)
		{

		case BossState::IDLE:
			IdleStart();
			break;
		case BossState::SMOKEPRE:
			SmokePreStart();
			break;
		case BossState::SMOKE:
			SmokeStart();
			break;
		case BossState::ATTACKPRE:
			AttackPreStart();
			break;
		case BossState::ATTACK:
			AttackStart();
			break;
		
		default:
			break;
		}
		

	}

}







void Boss::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case BossState::IDLE:
		IdleUpdate(_Time);
		break;
	case BossState::SMOKEPRE:
		SmokePreUpdate(_Time);
		break;
	case BossState::SMOKE:
		SmokeUpdate(_Time);
		break;
	case BossState::ATTACKPRE:
		AttackPreUpdate(_Time);
		break;
	case BossState::ATTACK:
		AttackUpdate(_Time);
		break;

	default:
		break;
	}
}

void Boss::IdleStart()
{

}

void Boss::SmokePreStart()
{
	AnimationCheck();
}
void Boss::SmokeStart()
{
	AnimationCheck();
}
void Boss::AttackPreStart()
{
	AnimationCheck();
}
void Boss::AttackStart()
{
	AnimationCheck();
}

void Boss::IdleUpdate(float _Time)
{
	if (IdleStartCheck == true && Hp> 0 )
	{
		Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (Time < 0.7)
		{

			MoveDir += float4::Up * 40;
			MoveDirGroundEffect += float4::Down * 40;
		}
		if (Time > 0.7)
		{
			if (Time < 1.4)
			{
				MoveDir += float4::Down * 40;
				MoveDirGroundEffect += float4::Up * 40;
			}
		}
		if (Time > 1.4)
		{
			Time = 0;
		}

		if (Hp <= 75)
		{
			MountTime += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 
			
			Mainbody->Off();
			TwoPhaseBody->On(); 

			if (MountTime < 1)
			{
				Upbody->ChangeAnimation("BossmountFinish");
			}
				
			
			if (MountTime > 2)
			{
				Upbody->ChangeAnimation("Bossmount");

				if (Upbody->IsAnimationEnd())
				{
					if (sddfs == false)
					{
						BazookaMonster* Actor = GetLevel()->CreateActor<BazookaMonster>();
						Actor->ChangeState(BazookaMonsterState::RIGHTMOVE);
						Actor->SetPos({ GetPos().x,MonsterCollision->GetCollisionData().Top() });

						BazookaMonster* Actor1 = GetLevel()->CreateActor<BazookaMonster>();
						Actor1->ChangeState(BazookaMonsterState::LEFTMOVE);
						Actor1->SetPos({ GetPos().x,MonsterCollision->GetCollisionData().Top() });
						sddfs = true;
					}
				}
			}
			if (MountTime > 3.5)
			{
				ChangeState(BossState::SMOKEPRE);
				return; 
			}


			/*Time = 0;
			ChangeState(BossState::SMOKEPRE);
			return;*/
		}
	}

	
}

void Boss::SmokePreUpdate(float _Time)
{
	if (Hp > 0)
	{
		if (BoomSoundCheck == true)
		{
			BoomSound.Stop();
		}


		if (SmokeSoundCheck == false)
		{

			SmokeSound = GameEngineResources::GetInst().SoundPlayToControl("BossSmoke.mp3");

			SmokeSoundCheck = true;

			BoomSoundCheck = false;
		}


		Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (Time < 0.7)
		{

			MoveDir += float4::Up * 40;
			MoveDirGroundEffect += float4::Down * 40;
		}
		if (Time > 0.7)
		{
			if (Time < 1.4)
			{
				MoveDir += float4::Down * 40;
				MoveDirGroundEffect += float4::Up * 40;
			}
		}
		if (Time > 1.4)
		{
			Time = 0;
		}



		if (LeftBoom->IsAnimationEnd())
		{
			ChangeState(BossState::SMOKE);
			return;
		}
	}
}



void Boss::SmokeUpdate(float _Time)
{
	if (Hp > 0)
	{
		Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (Time < 0.7)
		{

			MoveDir += float4::Up * 40;
			MoveDirGroundEffect += float4::Down * 40;
		}
		if (Time > 0.7)
		{
			if (Time < 1.4)
			{
				MoveDir += float4::Down * 40;
				MoveDirGroundEffect += float4::Up * 40;
			}
		}
		if (Time > 1.4)
		{
			Time = 0;
		}



		AttackPreTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (AttackPreTime > 2)
		{
			ChangeState(BossState::ATTACKPRE);
			AttackPreTime = 0;
			return;
		}
	}


}



void Boss::AttackPreUpdate(float _Time)
{
	if (Hp > 0)
	{
		if (SmokeSoundCheck == true)
		{
			SmokeSound.Stop();
		}

		if (BoomSoundCheck == false)
		{
			BoomSound = GameEngineResources::GetInst().SoundPlayToControl("BossBoom.mp3");
			BoomSoundCheck = true;


			SmokeSoundCheck = false;
		}
		Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (Time < 0.7)
		{

			MoveDir += float4::Up * 40;
			MoveDirGroundEffect += float4::Down * 40;
		}
		if (Time > 0.7)
		{
			if (Time < 1.4)
			{
				MoveDir += float4::Down * 40;
				MoveDirGroundEffect += float4::Up * 40;
			}
		}
		if (Time > 1.4)
		{
			Time = 0;
		}


		if (LeftBoom->IsAnimationEnd())
		{
			ChangeState(BossState::ATTACK);
			return;
		}
	}
}



void Boss::AttackUpdate(float _Time)
{
	if (Hp > 0)
	{
		ChangeTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		MoveTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		if (ChangeTime < 0.2)
		{
			RightBoom->ChangeAnimation("RightAttackBlueBoom");
			RightGroundEffect->ChangeAnimation("RightBlueGround");
			LeftBoom->ChangeAnimation("LeftAttackBlueBoom");
			LeftGroundEffect->ChangeAnimation("LeftBlueGround");


			//a = RightIdleBoom->GetFrame();
		}
		if (ChangeTime > 0.2)
		{
			if (ChangeTime < 0.4)
			{
				//RightIdleBoom->SetFrame(a);
				RightBoom->ChangeAnimation("RightAttackRedBoom");
				RightGroundEffect->ChangeAnimation("RightRedGround");
				LeftBoom->ChangeAnimation("LeftAttackRedBoom");
				LeftGroundEffect->ChangeAnimation("LeftRedGround");
				a = RightBoom->GetFrame();
			}

		}
		if (ChangeTime > 0.4)
		{
			if (ChangeTime < 0.6)
			{
				//	RightIdleBoom->SetFrame(a);
				RightBoom->ChangeAnimation("RightAttackYellowBoom");
				RightGroundEffect->ChangeAnimation("RightYellowGround");
				LeftBoom->ChangeAnimation("LeftAttackYellowBoom");
				LeftGroundEffect->ChangeAnimation("LeftYellowGround");
				a = RightBoom->GetFrame();
			}

		}


		ads += GameEngineTime::GlobalTime.GetFloatDeltaTime();

		if (ads < 0.4)
		{

			MoveDir += float4::Up * 40;
			MoveDirGroundEffect += float4::Down * 40;
		}
		if (ads > 0.4)
		{
			if (ads < 0.8)
			{
				MoveDir += float4::Down * 40;
				MoveDirGroundEffect += float4::Up * 40;
			}
		}
		if (ads > 0.8)
		{
			ads = 0;

		}




		if (ChangeTime > 0.5)
		{
			ChangeTime = 0;
		}
		if (MoveTime < 0.8)
		{
			MoveDir += float4::Right * 400;
		}
		if (MoveTime > 0.8)
		{
			if (MoveTime < 1.6)
			{
				MoveDir += float4::Left * 400;
			}
		}
		if (MoveTime > 1.6)
		{
			if (MoveTime < 2.4)
			{
				MoveDir += float4::Right * 400;
			}
		}
		if (MoveTime > 2.4)
		{
			if (MoveTime < 3.2)
			{
				MoveDir += float4::Left * 400;
			}
		}
		if (MoveTime > 3.2)
		{

			if (MoveCheck == 2)
			{
				MoveDir = { 0,0 };
				MoveTime = 0;
				ChangeState(BossState::SMOKEPRE);
				MoveCheck = 0;
				return;
			}

			++MoveCheck;
			MoveTime = 0;
		}
	}
}

