#include "Boss.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "BulletEffect.h"

Boss::Boss()
{

}

Boss::~Boss()
{

}



void Boss::Start()
{

	{
		Mainbody = CreateRender(MetalSlugOrder::Boss);
		Mainbody->SetScale({ 1200,1200 });
		Mainbody->SetPosition({ 0,-470 });
		Mainbody->SetImage("Boss.bmp");
		//Mainbody->SetImage(); 
	
	}
	/*{
		LeftWing = CreateRender(MetalSlugOrder::Boss);
		LeftWing->SetScale({ 800,800 });
		LeftWing->CreateAnimation({ .AnimationName = "LeftWing",  .ImageName = "LeftWing.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		LeftWing->ChangeAnimation("LeftWing");
		LeftWing->SetPosition({ -520,-250 });
	}
	{
		RightWing = CreateRender(MetalSlugOrder::Boss);
		RightWing->SetScale({ 800,800 });
		RightWing->CreateAnimation({ .AnimationName = "RightWing",  .ImageName = "RightWing.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
		RightWing->ChangeAnimation("RightWing");
		RightWing->SetPosition({ 380,-250 });
	}*/

	{
		LeftGroundEffect = CreateRender(MetalSlugOrder::Boss);
		LeftGroundEffect->SetScale({ 800,800 });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftGround",  .ImageName = "GroundEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftSmokeGround",  .ImageName = "GroundSmokeEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftYellowGround",  .ImageName = "GroundYellowEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftBlueGround",  .ImageName = "GroundBlueEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		LeftGroundEffect->CreateAnimation({ .AnimationName = "LeftRedGround",  .ImageName = "GroundRedEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });

		LeftGroundEffect->ChangeAnimation("LeftGround");
		LeftGroundEffect->SetPosition({ -295,0 });


	}
	{
		RightGroundEffect = CreateRender(MetalSlugOrder::Boss);
		RightGroundEffect->SetScale({ 800,800 });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightGround",  .ImageName = "GroundEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightSmokeGround",  .ImageName = "GroundSmokeEffect.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightYellowGround",  .ImageName = "GroundYellowEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightBlueGround",  .ImageName = "GroundBlueEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		RightGroundEffect->CreateAnimation({ .AnimationName = "RightRedGround",  .ImageName = "GroundRedEffect.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });

		RightGroundEffect->ChangeAnimation("RightGround");
		RightGroundEffect->SetPosition({ 308,0});
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
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackBlueBoom",  .ImageName = "BossShakeBlueBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.05f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackYellowBoom",  .ImageName = "BossShakeYellowBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.05f,.Loop = true });
		LeftBoom->CreateAnimation({ .AnimationName = "LeftAttackRedBoom",  .ImageName = "BossRedShakeBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.05f,.Loop = true });
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
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackBlueBoom",  .ImageName = "BossShakeBlueBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.05f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackYellowBoom",  .ImageName = "BossShakeYellowBoom.bmp", .Start = 0, .End =22, .InterTime = 0.05f,.Loop = true });
		RightBoom->CreateAnimation({ .AnimationName = "RightAttackRedBoom",  .ImageName = "BossRedShakeBoom.bmp", .Start = 0, .End = 22, .InterTime = 0.05f,.Loop = true });
		RightBoom->ChangeAnimation("RightIdleBoom");
		RightBoom->SetPosition({ 308,-208 });
	}

	{
		LeftEngine = CreateRender(MetalSlugOrder::Boss);
		LeftEngine->SetScale({ 800,800 });
		LeftEngine->CreateAnimation({ .AnimationName = "LeftEngine",  .ImageName = "LeftEngine.bmp", .Start = 0, .End = 2, .InterTime = 0.1f,.Loop = true });
		LeftEngine->CreateAnimation({ .AnimationName = "LeftColorEngine",  .ImageName = "LeftEngine.bmp", .Start = 3, .End = 8, .InterTime = 0.05f,.Loop = true });
		LeftEngine->ChangeAnimation("LeftEngine");
		LeftEngine->SetPosition({ -315,-398});
	}

	{
		RightEngine = CreateRender(MetalSlugOrder::Boss);
		RightEngine->SetScale({ 800,800 });
		RightEngine->CreateAnimation({ .AnimationName = "RightEngine",  .ImageName = "RightEngine.bmp", .Start = 0, .End = 2, .InterTime = 0.1f,.Loop = true });
		RightEngine->CreateAnimation({ .AnimationName = "RightColorEngine",  .ImageName = "RightEngine.bmp", .Start = 3, .End = 8, .InterTime = 0.05f,.Loop = true });
		RightEngine->ChangeAnimation("RightEngine");
		RightEngine->SetPosition({ 325,-398 });
	}


	ChangeState(BossState::IDLE); 

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MonsterCollision->SetScale({ 400, 300 });
		MonsterCollision->SetPosition({ 0,-400 });

	}

	


}

void Boss::Update(float _DeltaTime)
{
	if (nullptr != MonsterCollision)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
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

	Movecalculation(_DeltaTime);
	UpdateState(_DeltaTime);
}


void Boss::Movecalculation(float _DeltaTime)
{
	

	
	if (250.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -200.0f;
		}
		else
		{
			MoveDir.x = 200.0f;
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
		LeftBoom->SetScale({ 1200,800 });
		LeftBoom->SetPosition({ -295,-358 });

		RightBoom->SetScale({ 1200,800 });
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
		

		LeftBoom->SetScale({ 1200,800 });
		LeftBoom->SetPosition({ -295,-358 });

		RightBoom->SetScale({ 1200,800 });
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
	MonsterCollision->DebugRender(); 
}
