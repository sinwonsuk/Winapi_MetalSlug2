#include "Boss.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "BulletEffect.h"
#include "BossSmallMonster.h"
#include "BazookaMonster.h"
#include "FinishInterFace.h"
#include "WinPlayer.h"
#include "Player.h"
Boss* Boss::boss;
Boss::Boss()
{

}

Boss::~Boss()
{

}



void Boss::Start()
{
	boss = this;

	{
		Mainbody = CreateRender(MetalSlugOrder::Boss);
		Mainbody->SetScale({ 1200,1200 });
		Mainbody->SetPosition({ 0,-470 });
		Mainbody->SetImage("Boss.bmp");
		
		//Mainbody->SetImage(); 	
	}
	{
		TwoPhaseBody = CreateRender(MetalSlugOrder::Boss);
		TwoPhaseBody->SetScale({ 1200,1200 });
		TwoPhaseBody->SetPosition({ 0,-470 });
		TwoPhaseBody->SetImage("TwoBoss.bmp");
		TwoPhaseBody->Off(); 
		//Mainbody->SetImage(); 

	}
	{
		DeathBody = CreateRender(MetalSlugOrder::Boss);
		DeathBody->SetScale({ 1200,1200 });
		DeathBody->SetPosition({ 0,-470 });
		DeathBody->SetImage("DeathBoss.bmp");
		DeathBody->Off();
		//Mainbody->SetImage(); 

	}
	{
		Upbody = CreateRender(MetalSlugOrder::Boss);
		Upbody->SetScale({ 800,800 });
		Upbody->CreateAnimation({ .AnimationName = "Bossmount",  .ImageName = "Bossmount.bmp", .Start = 0, .End = 6 , .InterTime = 0.1f,.Loop = false });
		Upbody->CreateAnimation({ .AnimationName = "BossmountFinish",  .ImageName = "Bossmount.bmp", .Start = 0, .End = 6 , .InterTime = 0.1f,.Loop = false ,.FrameIndex{6,5,4,3,2,1,0} });
		Upbody->ChangeAnimation("Bossmount");
		Upbody->SetPosition({ 7,-540 });
		Upbody->Off();
	}

	{
		LeftGroundEffect = CreateRender(MetalSlugOrder::GroundEffect);
		LeftGroundEffect->SetScale({ 800,800 });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftGround",  .ImageName = "GroundEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftSmokeGround",  .ImageName = "GroundSmokeEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftYellowGround",  .ImageName = "GroundYellowEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftBlueGround",  .ImageName = "GroundBlueEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftRedGround",  .ImageName = "GroundRedEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });

		LeftGroundEffect->ChangeAnimation("LeftGround");
		LeftGroundEffect->SetPosition({ -295,30 });
		LeftGroundEffect->Off(); 


	}
	{
		RightGroundEffect = CreateRender(MetalSlugOrder::GroundEffect);
		RightGroundEffect->SetScale({ 800,800 });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightGround",  .ImageName = "GroundEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightSmokeGround",  .ImageName = "GroundSmokeEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightYellowGround",  .ImageName = "GroundYellowEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightBlueGround",  .ImageName = "GroundBlueEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightRedGround",  .ImageName = "GroundRedEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });

		RightGroundEffect->ChangeAnimation("RightGround");
		RightGroundEffect->SetPosition({ 308,30});
		RightGroundEffect->Off(); 
	}
	{
		LeftBoom = CreateRender(MetalSlugOrder::Boss);
		LeftBoom->SetScale({ 800,800 });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftIdleBoom",  .ImageName = "LeftBossIdleBoom.bmp", .Start = 0, .End = 3, .InterTime = 0.05f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftSmokeBoom",  .ImageName = "LeftBossSmoke.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftSmokeIdleBoom",  .ImageName = "LeftBossSmoke.bmp", .Start = 3, .End = 8, .InterTime = 0.05f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackPreBlueBoom",  .ImageName = "BoosAttackPreBlueBoom.bmp", .Start = 0, .End = 15, .InterTime = 0.04f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackPreYellowBoom",  .ImageName = "BossAttackPreYellowBoom.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackPreRedBoom",  .ImageName = "BossAttackPreRedBoom.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackBlueBoom",  .ImageName = "BossShakeBlueBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.04f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackYellowBoom",  .ImageName = "BossShakeYellowBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.04f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackRedBoom",  .ImageName = "BossRedShakeBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.04f,.Loop = true });
		LeftBoom->ChangeAnimation("LeftIdleBoom");
		LeftBoom->SetPosition({ -295,-208 });
	}

	{
		RightBoom = CreateRender(MetalSlugOrder::Boss);
		RightBoom->SetScale({ 800,800 });
		RightBoom->CreateAnimation({ .AnimationName = "RightIdleBoom",  .ImageName = "RightBossIdleBoom.bmp", .Start = 0, .End = 3, .InterTime = 0.05f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightSmokeBoom",  .ImageName = "RightBossSmoke.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightSmokeIdleBoom",  .ImageName = "RightBossSmoke.bmp", .Start = 3, .End = 8, .InterTime = 0.04f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackPreBlueBoom",  .ImageName = "BoosAttackPreBlueBoom.bmp", .Start = 0, .End = 15, .InterTime = 0.05f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackPreYellowBoom",  .ImageName = "BossAttackPreYellowBoom.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackPreRedBoom",  .ImageName = "BossAttackPreRedBoom.bmp", .Start = 0, .End = 15, .InterTime = 0.1f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackBlueBoom",  .ImageName = "BossShakeBlueBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.04f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackYellowBoom",  .ImageName = "BossShakeYellowBoom.bmp", .Start = 0, .End =22, .InterTime = 0.04f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackRedBoom",  .ImageName = "BossRedShakeBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.04f,.Loop = true });
		RightBoom->ChangeAnimation("RightIdleBoom");
		RightBoom->SetPosition({ 308,-208 });
	}

	{
		LeftEngine = CreateRender(MetalSlugOrder::Boss);
		LeftEngine->SetScale({ 800,800 });
		LeftEngine->CreateAnimation({ .AnimationName = "LeftEngine",  .ImageName = "LeftEngine.bmp", .Start = 0, .End = 2, .InterTime = 0.1f,.Loop = true });
		LeftEngine->CreateAnimation({ .AnimationName = "LeftColorEngine",  .ImageName = "LeftEngine.bmp", .Start = 3, .End = 8, .InterTime = 0.04f,.Loop = true });
		LeftEngine->ChangeAnimation("LeftEngine");
		LeftEngine->SetPosition({ -315,-398});
	}

	{
		RightEngine = CreateRender(MetalSlugOrder::Boss);
		RightEngine->SetScale({ 800,800 });
		RightEngine->CreateAnimation({ .AnimationName = "RightEngine",  .ImageName = "RightEngine.bmp", .Start = 0, .End = 2, .InterTime = 0.1f,.Loop = true });
		RightEngine->CreateAnimation({ .AnimationName = "RightColorEngine",  .ImageName = "RightEngine.bmp", .Start = 3, .End = 8, .InterTime = 0.04f,.Loop = true });
		RightEngine->ChangeAnimation("RightEngine");
		RightEngine->SetPosition({ 325,-398 });
	}


	{
	
		MiddleExploision = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision->SetScale({ 700,700 });
	
		MiddleExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision->Off();

		MiddleExploision2 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision2->SetScale({ 700,700 });
	
		MiddleExploision2->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision2->Off();

		MiddleExploision3 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision3->SetScale({ 700,700 });
	
		MiddleExploision3->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision3->Off();

		MiddleExploision4 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision4->SetScale({ 700,700 });
		
		MiddleExploision4->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision4->Off();

		MiddleExploision5 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision5->SetScale({ 700,700 });
		
		MiddleExploision5->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision5->Off();

		MiddleExploision6 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision6->SetScale({ 700,700 });

		MiddleExploision6->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision6->Off();

		MiddleExploision7 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision7->SetScale({ 700,700 });
						
		MiddleExploision7->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision7->Off();

		MiddleExploision8 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision8->SetScale({ 700,700 });

		MiddleExploision8->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision8->Off();

		MiddleExploision9 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision9->SetScale({ 700,700 });

		MiddleExploision9->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision9->Off();

		MiddleExploision10 = CreateRender(MetalSlugOrder::BossExPloision);
		MiddleExploision10->SetScale({ 700,700 });

		MiddleExploision10->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = true });
		MiddleExploision10->Off();

		BigExploision = CreateRender(MetalSlugOrder::BossExPloision);
		BigExploision->SetScale({ 900,900 });	
		BigExploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });
		BigExploision->Off();

		BigExploision2 = CreateRender(MetalSlugOrder::BossExPloision);
		BigExploision2->SetScale({ 900,900 });		
		BigExploision2->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });
		BigExploision2->Off();

		BigExploision3 = CreateRender(MetalSlugOrder::BossExPloision);
		BigExploision3->SetScale({ 900,900 });
		BigExploision3->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });
		BigExploision3->Off();

		BigExploision4 = CreateRender(MetalSlugOrder::BossExPloision);
		BigExploision4->SetScale({ 900,900 });
		BigExploision4->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });
		BigExploision4->Off();

		BigExploision5 = CreateRender(MetalSlugOrder::BossExPloision);
		BigExploision5->SetScale({ 900,900 });
		BigExploision5->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "BigExploision.bmp", .Start = 0, .End = 27, .InterTime = 0.05f,.Loop = false });
		BigExploision5->Off();

	}

	MiddleExploision->ChangeAnimation("Exploision");
	MiddleExploision2->ChangeAnimation("Exploision");
	MiddleExploision3->ChangeAnimation("Exploision");
	MiddleExploision4->ChangeAnimation("Exploision");
	MiddleExploision5->ChangeAnimation("Exploision");
	MiddleExploision6->ChangeAnimation("Exploision");
	MiddleExploision7->ChangeAnimation("Exploision");
	MiddleExploision8->ChangeAnimation("Exploision");
	MiddleExploision9->ChangeAnimation("Exploision");
	MiddleExploision10->ChangeAnimation("Exploision");

	BigExploision->ChangeAnimation("Exploision");
	BigExploision2->ChangeAnimation("Exploision");
	BigExploision3->ChangeAnimation("Exploision");
	BigExploision4->ChangeAnimation("Exploision");
	BigExploision5->ChangeAnimation("Exploision");
	
	ChangeState(BossState::IDLE); 

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::Boss);
		MonsterCollision->SetScale({ 400, 300 });
		MonsterCollision->SetPosition({ 0,-400 });

	}
	{
		BullletCollision = CreateCollision(MetalSlugOrder::Boss);
		BullletCollision->SetScale({ 800, 200 });
		BullletCollision->SetPosition({ 0,-400 });

	}


}

void Boss::Update(float _DeltaTime)
{
	if (BossStart == true)
	{
		if (IdleStartCheck == false)
		{
			MoveDir = float4::Down * 50;
			SetMove(MoveDir * _DeltaTime);
		}




		if (GetPos().y > 690)
		{
			LeftGroundEffect->On();
			RightGroundEffect->On();
			IdleStartCheck = true;
			Upbody->On();
		}



		if (IdleStartCheck == true)
		{

			if (nullptr != BullletCollision)
			{
				std::vector<GameEngineCollision*> collision;
				if (true == BullletCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
				{
					Hp--;

					for (size_t i = 0; i < collision.size(); i++)
					{
						GameEngineActor* ColActor = collision[i]->GetActor();
						BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
						Effect->SetMove(ColActor->GetPos());


						ColActor->Death();
					}


				}
			}

			MonsterTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

			if (MonsterTime > 1.5 && Hp > 75)
			{
				if (LeftRightCheck == true)
				{
					SmallMonster = GetLevel()->CreateActor<BossSmallMonster>();

					SmallMonster->ChangeState(SmallMonsterState::RIGHTMOVE);
					SmallMonster->SetPos({ GetPos().x,MonsterCollision->GetCollisionData().Top() });
					LeftRightCheck = false;
					MonsterTime = 0;

				}
				else if (LeftRightCheck == false)
				{
					SmallMonster = GetLevel()->CreateActor<BossSmallMonster>();

					SmallMonster->ChangeState(SmallMonsterState::LEFTMOVE);
					SmallMonster->SetPos({ GetPos().x,MonsterCollision->GetCollisionData().Top() });
					LeftRightCheck = true;
					MonsterTime = 0;

				}

			}

			Movecalculation(_DeltaTime);
		}

		if (Hp <= 0)
		{
			MoveDir = { 0,0 };



			ExploisionTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

			if (ExploisionTime < 0.5)
			{
				MiddleExploision->On();
				MiddleExploision->SetPosition({ 0,-570 });
			}
			if (ExploisionTime > 0.5)
			{
				if (ExploisionTime < 1.0)
				{
					MiddleExploision2->On();
					MiddleExploision2->SetPosition({ -50,-500 });
				}
			}
			if (ExploisionTime > 1.0)
			{
				if (ExploisionTime < 1.5)
				{
					MiddleExploision3->On();
					MiddleExploision3->SetPosition({ 70,-480 });
				}
			}
			if (ExploisionTime > 1.5)
			{
				if (ExploisionTime < 2.0)
				{
					MiddleExploision4->On();
					MiddleExploision4->SetPosition({ 100,-370 });
				}
			}
			if (ExploisionTime > 2.0)
			{
				if (ExploisionTime < 2.5)
				{
					MiddleExploision5->On();
					MiddleExploision5->SetPosition({ -80,-350 });
				}
			}
			if (ExploisionTime > 2.5)
			{
				if (ExploisionTime < 3.0)
				{
					MiddleExploision6->On();
					MiddleExploision6->SetPosition({ -150,-480 });
				}
			}
			if (ExploisionTime > 3.0)
			{
				if (ExploisionTime < 3.5)
				{
					MiddleExploision7->On();
					MiddleExploision7->SetPosition({ 250,-460 });
				}
			}
			if (ExploisionTime > 3.5)
			{
				if (ExploisionTime < 4.0)
				{
					MiddleExploision8->On();
					MiddleExploision8->SetPosition({ -300,-410 });
				}
			}
			if (ExploisionTime > 4.0)
			{
				if (ExploisionTime < 4.5)
				{
					MiddleExploision9->On();
					MiddleExploision9->SetPosition({ 200,-420 });
				}
			}
			if (ExploisionTime > 4.5)
			{
				if (ExploisionTime < 5.0)
				{
					MiddleExploision10->On();
					MiddleExploision10->SetPosition({ -360,-380 });
				}
			}


			if (ExploisionTime > 5.0)
			{
				ExploisionTime = 0;
			}






			LeftGroundEffect->Off();
			RightGroundEffect->Off();
			LeftBoom->Off();
			RightBoom->Off();
			LeftEngine->Off();
			RightEngine->Off();


			GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

			if (nullptr == ColImage)
			{
				MsgAssert("충돌용 맵 이미지가 없습니다.");
			}

			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			float4 NextPos1 = { NextPos.x,NextPos.y - 250 };
			if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos1, RGB(0, 255, 0))))
			{
				if (MoveStop == false)
				{
					TwoPhaseBody->Off();
					DeathBody->On();
					MoveStop = true;
				}



				BigExploisionTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();


				if (BigExploisionTime > 1)
				{
					MiddleExploision->Off();
					MiddleExploision2->Off();
					MiddleExploision3->Off();
					MiddleExploision4->Off();
					MiddleExploision5->Off();
					MiddleExploision6->Off();
					MiddleExploision7->Off();
					MiddleExploision8->Off();
					MiddleExploision9->Off();
					MiddleExploision10->Off();

					BigExploision->On();
					BigExploision->SetPosition({ 0,-500 });
					BigExploision2->On();
					BigExploision2->SetPosition({ -300,-500 });
					BigExploision3->On();
					BigExploision3->SetPosition({ 300,-500 });
					BigExploision4->On();
					BigExploision4->SetPosition({ 250,-400 });
					BigExploision5->On();
					BigExploision5->SetPosition({ -250,-400 });
					DeathBody->Off();
					Upbody->Off();
				}

				SetMove(-MoveDir * _DeltaTime);
			}

			if (MoveStop == false)
			{
				MoveDir += float4::Down * 300;


				DeathTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();

				if (DeathTime < 0.05)
				{
					MoveDir += float4::Right * 100;
				}
				if (DeathTime > 0.05)
				{
					if (DeathTime < 0.1)
					{
						MoveDir += float4::Left * 100;
					}
				}
				if (DeathTime > 0.1)
				{
					DeathTime = 0;
				}
			}


		}
		if (BigExploision5->IsAnimationEnd())
		{
			if (Finishletter == false)
			{
				WinPlayer * player = GetLevel()->CreateActor<WinPlayer>();
				player->SetPos(Player::MainPlayer->GetPos()); 

				FinishInterFace* Actor = GetLevel()->CreateActor<FinishInterFace>();
				Actor->SetPos({ GetPos().x - 400,GetPos().y - 1000 });
				Finishletter = true;
			}

		}

		if (Hp >= 0)
		{
			UpdateState(_DeltaTime);
		}

	}
}


void Boss::Movecalculation(float _DeltaTime)
{
	

	
	if (250.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -400.0f;
		}
		else
		{
			MoveDir.x = 400.0f;
		}
	}
	if (250.0f <= abs(MoveDirGroundEffect.x))
	{
		if (0 > MoveDirGroundEffect.x)
		{
			MoveDirGroundEffect.x = -200.0f;
		}
		else
		{
			MoveDirGroundEffect.x = 200.0f;
		}
	}
	if (40.0f <= abs(MoveDirGroundEffect.y))
	{
		if (0 > MoveDirGroundEffect.y)
		{
			MoveDirGroundEffect.y = -40.0f;
		}
		else
		{
			MoveDirGroundEffect.y = 40.0f;
		}
	}


	

	if (40.0f <= abs(MoveDir.y))
	{
		if (0 > MoveDir.y)
		{
			MoveDir.y = -40.0f;
		}
		else
		{
			MoveDir.y = 40.0f;
		}
	}




	RightGroundEffect->SetMove(MoveDirGroundEffect * _DeltaTime);
	LeftGroundEffect->SetMove(MoveDirGroundEffect * _DeltaTime);
	SetMove(MoveDir * _DeltaTime);
}

void Boss::AnimationCheck()
{


	if (StateValue == BossState::SMOKEPRE)
	{
		LeftBoom->SetScale({ 1200,830 });
		LeftBoom->SetPosition({ -295,-358 });

		RightBoom->SetScale({ 1200,830 });
		RightBoom->SetPosition({ 308,-358 });

		LeftEngine->ChangeAnimation("LeftEngine");
		RightEngine->ChangeAnimation("RightEngine");

		LeftBoom->ChangeAnimation("LeftSmokeBoom");
		RightBoom->ChangeAnimation("RightSmokeBoom");

		LeftGroundEffect->ChangeAnimation("LeftSmokeGround");
		RightGroundEffect->ChangeAnimation("RightSmokeGround");
	}

	if (StateValue == BossState::SMOKE)
	{
		LeftBoom->ChangeAnimation("LeftSmokeIdleBoom");
		RightBoom->ChangeAnimation("RightSmokeIdleBoom");
	}

	if (StateValue == BossState::ATTACKPRE)
	{
		LeftBoom->ChangeAnimation("LeftAttackPreBlueBoom");
		RightBoom->ChangeAnimation("RightAttackPreBlueBoom");
	}


	if (StateValue == BossState::ATTACKPRE)
	{
		

		LeftBoom->SetScale({ 1200,830 });
		LeftBoom->SetPosition({ -295,-358 });

		RightBoom->SetScale({ 1200,830 });
		RightBoom->SetPosition({ 308,-358 });

		LeftGroundEffect->SetPosition({ -295 ,40});
		RightGroundEffect->SetPosition({308, 40});
	}

	if (StateValue == BossState::ATTACK)
	{
		LeftEngine->ChangeAnimation("LeftColorEngine");
		RightEngine->ChangeAnimation("RightColorEngine");
	}


}


void Boss::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

	//BullletCollision->DebugRender();
	
}
