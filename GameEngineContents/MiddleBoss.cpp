#include "MiddleBoss.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"


MiddleBoss* MiddleBoss::middleBoss;


MiddleBoss::MiddleBoss()
{
}

MiddleBoss::~MiddleBoss()
{

}




void MiddleBoss::Start()
{
	middleBoss = this;

	{
		PalaceBase = CreateRender(2);
		PalaceBase->SetImage("PalaceBase.Bmp");
		//PalaceBase->SetPosition({ 0,0 });
		PalaceBase->SetScale({ 1200,430 });
		//PalaceBase->EffectCameraO();
	}


	//{
	//	AnimationBodyRender = CreateRender(MetalSlugOrder::Monster);
	//	AnimationBodyRender->SetScale({ 500,500 });

	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Idle",  .ImageName = "CamelMonsterStart.bmp", .Start = 0, .End = 9, .InterTime = 0.5f,.Loop = true });
	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Move",  .ImageName = "MonsterCamelMoveBody.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });


	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Death",  .ImageName = "DeathOne.bmp", .Start = 0, .End = 10, .InterTime = 0.1f });
	//	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Death",  .ImageName = "DeathOne.bmp", .Start = 0, .End = 10, .InterTime = 0.1f });


	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Reg_Attack",  .ImageName = "MonsterCamelDownReg.bmp", .Start = 2, .End = 2, .InterTime = 0.2f, .Loop = false });
	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Reg_AttackPre",  .ImageName = "MonsterCamelDownReg.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false });
	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Reg_Up",  .ImageName = "MonsterCamelDownReg.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false , .FrameIndex{ 2,1,0 } });

	//}
	//{
	//	AnimationRegRender = CreateRender(MetalSlugOrder::MonsterReg);
	//	AnimationRegRender->SetScale({ 500,500 });
	//	AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Reg_Idle",  .ImageName = "CamelMonsterStart.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
	//	AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Reg_Move",  .ImageName = "MonsterCamelMoveReg.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });

	//	AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Reg_Death",  .ImageName = "MonsterCamelDeathReg.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
	//	AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Body_AttackPre",  .ImageName = "MonsterCamelDownBody.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false });
	//	AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Body_Up",  .ImageName = "MonsterCamelDownBody.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false, .FrameIndex{ 2,1,0 } });
	//	AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Body_Attack",  .ImageName = "MonsterCamelAttackBody.bmp", .Start = 0, .End = 9, .InterTime = 0.1f, .Loop = false , .FrameIndex{ 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9 } });
	//}



	/*{
		BulletRender = CreateRender(MetalSlugOrder::MonsterBullet);
		BulletRender->SetScale({ 500,500 });
		BulletRender->CreateAnimation({ .AnimationName = "Left_MonsterNife", .ImageName = "MonsterNife.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
		BulletRender->ChangeAnimation("Left_MonsterNife");
	}*/



	/*{
		MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
		MonsterCollision->SetScale({ 100, 100 });

	}


	{
		PlayerCollision = CreateCollision(MetalSlugOrder::MonsterCheck);

		PlayerCollision->SetScale({ 500, 500 });
	}*/



//	ChangeState(MiddleBoss::IDLESTART);
}

void MiddleBoss::Update(float _DeltaTime)
{
}

void MiddleBoss::Render(float _Time)
{
}

