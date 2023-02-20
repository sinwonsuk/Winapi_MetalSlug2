#include "MonsterCamel.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"

MonsterCamel* MonsterCamel::CamelMonster;

MonsterCamel::MonsterCamel()
{

}
MonsterCamel::~MonsterCamel()
{

}

void MonsterCamel::Start()
{

	CamelMonster = this;

	{
		AnimationBodyRender = CreateRender(MetalSlugOrder::Monster);
		AnimationBodyRender->SetScale({ 500,500 });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Idle",  .ImageName = "CamelMonsterStart.bmp", .Start = 0, .End = 9, .InterTime = 0.5f,.Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Move",  .ImageName = "MonsterCamelMoveBody.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
		
		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Death",  .ImageName = "DeathOne.bmp", .Start = 0, .End = 10, .InterTime = 0.1f });
	//	AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Body_Death",  .ImageName = "DeathOne.bmp", .Start = 0, .End = 10, .InterTime = 0.1f });
		
		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Reg_Attack",  .ImageName = "MonsterCamelDownReg.bmp", .Start = 2, .End = 2, .InterTime = 0.2f, .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Reg_AttackPre",  .ImageName = "MonsterCamelDownReg.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Reg_Up",  .ImageName = "MonsterCamelDownReg.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false , .FrameIndex{ 2,1,0 } });

	}
	{
		AnimationRegRender = CreateRender(MetalSlugOrder::MonsterReg);
		AnimationRegRender->SetScale({ 500,500 });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Reg_Idle",  .ImageName = "CamelMonsterStart.bmp", .Start = 0, .End = 9, .InterTime = 0.1f,.Loop = true });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Reg_Move",  .ImageName = "MonsterCamelMoveReg.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });

		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Reg_Death",  .ImageName = "MonsterCamelDeathReg.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Body_AttackPre",  .ImageName = "MonsterCamelDownBody.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Body_Up",  .ImageName = "MonsterCamelDownBody.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false, .FrameIndex{ 2,1,0 } });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Body_Attack",  .ImageName = "MonsterCamelAttackBody.bmp", .Start = 0, .End = 9, .InterTime = 0.1f, .Loop = false , .FrameIndex{ 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9 } });
	}

	

	/*{
		BulletRender = CreateRender(MetalSlugOrder::MonsterBullet);
		BulletRender->SetScale({ 500,500 });
		BulletRender->CreateAnimation({ .AnimationName = "Left_MonsterNife", .ImageName = "MonsterNife.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
		BulletRender->ChangeAnimation("Left_MonsterNife");
	}*/



	//{
	//	MonsterCollision = CreateCollision(MetalSlugOrder::Monster);
	//	MonsterCollision->SetPosition({ 0,-100 });
	//	MonsterCollision->SetScale({ 100, 100 });

	//}


	{
		PlayerCollision = CreateCollision(MetalSlugOrder::MonsterCheck);
		
		PlayerCollision->SetScale({ 500, 500 });


	}



	ChangeState(MonsterCamelState::IDLESTART);


}

void MonsterCamel::Movecalculation(float _DeltaTime)
{
	PlayerCollision->SetPosition({ -200,0 });
	MoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (450.0f <= abs(MoveDir.x) && StateValue == MonsterCamelState::IDLESTART)
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -450.0f;
		}
		else
		{
			MoveDir.x = 450.0f;
		}
	}

	if (200.0f <= abs(MoveDir.x) && StateValue == MonsterCamelState::MOVE)
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
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	



	if ( RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0))) 
	{	
		Check = false;
	}




	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)))
			{
				continue;
			}

			if (50.0f <= abs(MoveDir.y))
			{
				if (0 > MoveDir.y)
				{
					MoveDir.y = -100.0f;
				}
				else
				{
					MoveDir.y = 0.0f;
				}
			}
			Check = true;
			break;
		}
	}
	
	SetMove(MoveDir * _DeltaTime);
}

void MonsterCamel::DirBodyCheck(const std::string_view& _AnimationName , const std::string_view& _AnimationName1)
{


	std::string PrevDirString = DirString;

	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());


	if (StateValue == MonsterCamelState::IDLESTART)
	{
		AnimationBodyRender->SetPosition({ 0,0 });
		AnimationBodyRender->Off();
	
		return; 
	}



	else if (StateValue == MonsterCamelState::IDLE)
	{
		AnimationBodyRender->SetPosition({ 0,0 });
		AnimationBodyRender->Off();
	
		return;
	}
	
	
	else if (StateValue == MonsterCamelState::MOVE)
	{
		AnimationBodyRender->On();
		AnimationBodyRender->SetPosition({ 0,0 });
		AnimationRegRender->SetPosition({ 0,0 });
		AnimationBodyRender->SetPosition({ 25,-110});

		return;

	}

	else if (StateValue == MonsterCamelState::ATTACKPRE)
	{
		//AnimationBodyRender->On();
		AnimationBodyRender->SetPosition({ 0,0 });
		AnimationRegRender->SetPosition({ 10,-50});
		return;
	}




	if (PrevDirString != DirString)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());

		AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());
	}



}





void MonsterCamel::Update(float _DeltaTime)
{
	if (nullptr != PlayerCollision && StateValue == MonsterCamelState::IDLESTART)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == PlayerCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			CollisionPos = GetPos(); 

			ChangeState(MonsterCamelState::IDLE);

		}
	}
	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}

void MonsterCamel::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

	//PlayerCollision->DebugRender();
}
