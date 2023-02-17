#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <stdlib.h>
#include <math.h>
#include "Bullets.h"
#include "Monster.h"
#include "ContentsEnums.h"

Player* Player::MainPlayer;

Player::Player() 
{
	
	

}

Player::~Player() 
{
}

void Player::Start()
{
	MainPlayer = this;
	SetMove({ 100,0 });
	
	float a = cos(20);

	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::CreateKey("RightMove", VK_RIGHT);
		GameEngineInput::CreateKey("DownMove", VK_DOWN);
		GameEngineInput::CreateKey("UpMove", VK_UP);
		GameEngineInput::CreateKey("Freemove", '1');
		GameEngineInput::CreateKey("Jumpmove", 'S');
		GameEngineInput::CreateKey("Attack", 'A');
		GameEngineInput::CreateKey("Throw", 'D');
		GameEngineInput::CreateKey("test", 'F');
	}

	{
		//body
		RightSetBody({ 0,0 });
		AnimationBodyRender = CreateRender(MetalSlugOrder::PlayerBody);
		AnimationBodyRender->SetScale({ 200,200 });
		AnimationBodyRender->SetPosition({body });

		// Idle Body
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdlePlayer.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "LeftIdlePlayer.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });

		// Move Body
		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "RightBodyMove.bmp", .Start = 2, .End = 11, .InterTime = 0.07f });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "LeftBodyMove.bmp", .Start = 2, .End = 11, .InterTime = 0.07f });
		
		//JumpIdleBody

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Idle_Jump",  .ImageName = "RightIdleJumpBody.bmp", .InterTime = 0.1f,.Loop = false, .FrameIndex{5,4,3,2,1,0,1,2,3,4,5}});
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Idle_Jump",  .ImageName = "LeftIdleJumpBody.bmp",  .InterTime = 0.1f,.Loop = false , .FrameIndex{ 5,4,3,2,1,0,1,2,3,4,5 }});

		//JumpMoveUpBody

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Move_Up_Jump_Body",  .ImageName = "RightJumpBody.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Move_Up_Jump_Body",  .ImageName = "LeftJumpBody.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = false });

		//JumpMoveDownBody

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Move_Down_Jump_Body",  .ImageName = "RightJumpBody.bmp", .Start = 4, .End = 5, .InterTime = 0.12f,.Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Move_Down_Jump_Body",  .ImageName = "LeftJumpBody.bmp", .Start = 4, .End = 5, .InterTime = 0.12f,.Loop = false });
	
		//Up

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Up",  .ImageName = "RightUp.bmp", .Start = 7, .End = 7, .InterTime = 0.01f,.Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Up",  .ImageName = "LeftUp.bmp", .Start = 7, .End = 7, .InterTime = 0.01f,.Loop = false });
		

		//Down

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Down",  .ImageName = "RightDown.bmp", .Start = 0, .End = 2, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Down",  .ImageName = "LeftDown.bmp", .Start = 0, .End = 2, .InterTime = 0.1f , .Loop = false });

		//IdleAttack

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Attack",  .ImageName = "RightAttack.bmp", .Start = 0, .End = 9, .InterTime = 0.05f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Attack",  .ImageName = "LeftAttack.bmp", .Start = 0, .End = 9, .InterTime = 0.05f , .Loop = false });

		// UpAttack
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Up_Attack",  .ImageName = "RightUpAttack.bmp", .Start = 0, .End = 9, .InterTime = 0.05f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Up_Attack",  .ImageName = "LeftUpAttack.bmp", .Start = 0, .End = 9, .InterTime = 0.05f , .Loop = false });


		//Throw 
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Throw",  .ImageName = "RightThrow.bmp", .Start = 0, .End = 5, .InterTime = 0.05f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Throw",  .ImageName = "LeftThrow.bmp", .Start = 0, .End = 5, .InterTime = 0.05f , .Loop = true });


		//HeaveGun
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeavyGunIdle",  .ImageName = "RightHeavyGunIdle.bmp", .Start = 0, .End = 3, .InterTime = 0.2f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeavyGunIdle",  .ImageName = "LeftHeavyGunIdle.bmp", .Start = 0, .End = 3, .InterTime = 0.2f , .Loop = true });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunMove",  .ImageName = "RightHeaveGunMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunMove",  .ImageName = "LeftHeaveGunMove.bmp", .Start = 0, .End = 11, .InterTime = 0.1f , .Loop = true });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunUp",  .ImageName = "RightHeaveGunUp.bmp", .Start = 0, .End = 1, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunUp",  .ImageName = "LeftHeaveGunUp.bmp", .Start = 0, .End = 1, .InterTime = 0.1f , .Loop = false });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunIdleUpJump",  .ImageName = "RightHeaveGunIdleJump.bmp", .Start = 0, .End = 4, .InterTime = 0.1f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunIdleUpJump",  .ImageName = "LeftHeaveGunIdleJump.bmp", .Start = 0, .End = 4, .InterTime = 0.1f , .Loop = true });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunIdleDownJump",  .ImageName = "RightHeaveGunIdleJump.bmp", .Start = 0, .End = 4, .InterTime = 0.1f , .Loop = true ,.FrameIndex{4,3,2,1,0 } });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunIdleDownJump",  .ImageName = "LeftHeaveGunIdleJump.bmp", .Start = 0, .End = 4, .InterTime = 0.1f , .Loop = true ,  .FrameIndex{4,3,2,1,0 } });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunMoveUpJump",  .ImageName = "RightHeaveGunMoveJump.bmp", .Start = 0, .End = 2, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunMoveUpJump",  .ImageName = "LeftHeaveGunMoveJump.bmp", .Start = 0, .End = 2, .InterTime = 0.1f , .Loop = false });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunMoveDownJump",  .ImageName = "RightHeaveGunMoveJump.bmp", .Start = 3, .End = 5, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunMoveDownJump",  .ImageName = "LeftHeaveGunMoveJump.bmp", .Start = 3, .End = 5, .InterTime = 0.1f , .Loop = false });

		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeavyGunIdleAttack",  .ImageName = "RightHeavyGunIdleAttack.bmp", .Start = 0, .End = 6, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeavyGunIdleAttack",  .ImageName = "LeftHeavyGunIdleAttack.bmp", .Start = 0, .End = 6, .InterTime = 0.1f , .Loop = false });




	




		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunUpAttack",  .ImageName = "RightHeavyUpAttack.bmp", .Start = 0, .End = 3, .InterTime = 0.075f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunUpAttack",  .ImageName = "LeftHeavyUpAttack.bmp", .Start = 0, .End = 3, .InterTime = 0.075f , .Loop = false });

	

			

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunDownAttack",  .ImageName = "RightHeaveGunDownAttack.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunDownAttack",  .ImageName = "LeftHeaveGunDownAttack.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunThrow",  .ImageName = "RightHeaveGunThrow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunThrow",  .ImageName = "LeftHeaveGunThrow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunIdleChangeUp",  .ImageName = "RightHeavyIdleChangeUp.bmp", .Start = 0, .End = 3, .InterTime = 0.075f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunIdleChangeUp",  .ImageName = "LeftHeavyIdleChangeUp.bmp", .Start = 0, .End = 3, .InterTime = 0.075f , .Loop = false });

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunUpChangeIdle",  .ImageName = "RightHeavyUpChangeIdle.bmp", .Start = 0, .End = 2, .InterTime = 0.075f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunUpChangeIdle",  .ImageName = "LeftHeavyUpChangeIdle.bmp", .Start = 0, .End = 2, .InterTime = 0.075f , .Loop = false });

	}


	{
		//reg
		AnimationRegRender = CreateRender(MetalSlugOrder::PlayerReg);
		AnimationRegRender->SetScale({ 200, 200 });
		AnimationRegRender->SetPosition({ Reg });
		
		//Idle Reg

		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "RightReg.bmp", .Start = 0, .End = 0, .InterTime = 0.2f });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "LeftReg.bmp", .Start = 0, .End = 0, .InterTime = 0.2f });
		

		//Move Reg
	
		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "RightReg.bmp", .Start = 3, .End = 15, .InterTime = 0.05f });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "LeftReg.bmp", .Start = 3, .End = 15, .InterTime = 0.05f });

		//Idle Jump Down Reg
		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Idle_Down_Jump",  .ImageName = "RightJumpReg.bmp",   .InterTime = 0.1f ,   .Loop = false,.FrameIndex{5,4,3,2,1,0}});
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Idle_Down_Jump",  .ImageName = "LeftJumpReg.bmp",   .InterTime = 0.1f ,   .Loop = false,.FrameIndex{5,4,3,2,1,0} });
		
		// Idle Jump Up Reg
		
	    AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Idle_Up_Jump",    .ImageName = "RightJumpReg.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = false });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Idle_Up_Jump",    .ImageName =   "LeftJumpReg.bmp", .Start = 0, .End = 5, .InterTime = 0.1f,.Loop = false });

		// Jump  Up Move

		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Move_Up_Jump_Reg",    .ImageName = "RightJumpReg.bmp", .Start = 6, .End = 8, .InterTime = 0.1f,.Loop = false });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Move_Up_Jump_Reg",    .ImageName =  "LeftJumpReg.bmp" ,.Start = 6, .End = 8, .InterTime = 0.1f,.Loop = false });

		// Jump Down Move

		AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Move_Down_Jump_Reg",    .ImageName = "RightJumpReg.bmp", .Start = 9, .End = 11, .InterTime = 0.12f,.Loop = false });
		AnimationRegRender->CreateAnimation({ .AnimationName = "Left_Move_Down_Jump_Reg",    .ImageName = "LeftJumpReg.bmp" ,.Start = 9, .End = 11, .InterTime = 0.12f,.Loop = false });





		// Up Idle Reg
		//AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Idle_Up_Reg",  .ImageName = "RightReg.bmp", .Start = 0, .End = 0, .InterTime = 0.2f });
		//AnimationRegRender->CreateAnimation({ .AnimationName = "Right_Up_Move",  .ImageName = "RightReg.bmp", .Start = 3, .End = 15, .InterTime = 0.05f });

		
	}

	


	ChangeState(PlayerState::IDLE);
	//ChangeState(PlayerState::HEAVYIDLE);
	{
		BodyCollision = CreateCollision(MetalSlugOrder::PlayerReg);
		BodyCollision->SetScale({ 100, 100 });
		BodyCollision->SetPosition({ 0,-100 });

	}
	{
		BulletCollision = CreateCollision(MetalSlugOrder::BulletCheck);
		BulletCollision->SetPosition({ 500,0 });
		BulletCollision->SetScale({10,500});

	}

}

//void Player::Update(float _DeltaTime) 
//{
//	UpdateState(_DeltaTime);
//}

void Player::Movecalculation(float _DeltaTime)
{
	
	

	if (a == true)
	{		
		MoveDir += float4::Down * 1500.0f * _DeltaTime;
	}
	if (a == false)
	{
		MoveDir += float4::Down * 6000.0f * _DeltaTime;
	}
	
	if (true == GameEngineInput::IsDown("test"))
	{
		if (a1 == false)
		{
			ChangeState(PlayerState::HEAVYIDLE);
			a1 = true;
		}
		else if (a1 == true)
		{
			ChangeState(PlayerState::IDLE);
			a1 = false;
		}

	}
	
	//Actors.size(); 
	

	if (300.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -300.0f;
		}
		else 
		{
			MoveDir.x = 300.0f;
		}
	}



	
	if (false == GameEngineInput::IsPress("LeftMove") && false == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir.x *= 0.01f;	
	}

	//ColMap.BMP 이걸 변수로하면 
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}
	
	//// 내 미래의 위치는 여기인데/.

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	
	
	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		CameraCheck = true;	
	}

	

	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255,0)) && MoveDir.y >= -80)
	{
		if (a1 == false)
		{
			if (test == true)
			{

				AnimationBodyRender->SetScale({ 200,200 });
				AnimationBodyRender->SetPosition({ body });

				ChangeState(PlayerState::IDLE);
			}
			test = false;
			Check = false;
			a = false;
		}
		else if (a1 == true)
		{
			if (test == true)
			{

				//AnimationBodyRender->SetScale({ 200,200 });
				AnimationBodyRender->SetPosition({ body });
				ChangeState(PlayerState::HEAVYIDLE);
				//ChangeState(PlayerState::IDLE);
			}
			test = false;
			Check = false;
			a = false;
		}		
	}
	

	if (false == Check )
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
					MoveDir.y = -80.0f;
				}
				else 
				{
					MoveDir.y = 0.0f;
				}
			
			}
			a = true;
			Check = true;
			break;
		}
	}
	test23 = false;


	if (CameraCheck == true && PosCheck.x < GetPos().ix())
	{		
		test23 = true;
		GetLevel()->SetCameraMove(CameraDir);
	}
	
	SetMove(MoveDir * _DeltaTime);
}

bool FreeMode = false; 

void Player::Update(float _DeltaTime)
{

	
	

	if (GameEngineInput::IsDown("LeftMove"))
	{
		
		if (PosCheck.x < GetPos().x)
		{
			PosCheck = GetPos();
		}


	}
	if (true == GameEngineInput::IsPress("Freemove"))
	{
		FreeMode = true;
	}

	if (true == FreeMode)
	{
		if (GameEngineInput::IsPress("LeftMove"))
		{
			SetMove(float4::Left*1000.0f* _DeltaTime);
			GetLevel()->SetCameraMove(float4::Left * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("RightMove"))
		{
			SetMove(float4::Right * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Right * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("UpMove"))
		{
			SetMove(float4::Up * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Up * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("DownMove"))
		{
			SetMove(float4::Down * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Down * 1000.0f * _DeltaTime);
		}
		if (true == GameEngineInput::IsPress("Freemove"))
		{
			FreeMode = false;
		}
		return; 
	}

	
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
	UpdateState(_DeltaTime);
	
	
	
}

void Player::DirCheck(const std::string_view& _AnimationName)
{
	

	std::string PrevDirString = DirString;

	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName.data());
	
	if (StateValue == PlayerState::IDLE)
	{
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });
			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (GameEngineInput::IsPress("LeftMove"))
	{
		LeftSetBody({0,0});
	
		AnimationBodyRender->SetPosition({ body });
		AnimationRegRender->SetPosition({ Reg });
		DirString = "Left_";
	}

	else if (GameEngineInput::IsPress("RightMove"))
	{
		RightSetBody({0,0});
	
		AnimationBodyRender->SetPosition({ body });
		AnimationRegRender->SetPosition({ Reg });
		DirString = "Right_";
	}




		
	if (PrevDirString != DirString)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
		AnimationRegRender->ChangeAnimation(DirString + _AnimationName.data());
	}

}

void Player::CollisionCheck(float _DeltaTime)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	if (nullptr != BulletCollision)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == BulletCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{


			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				ColActor->Death();
			}

		}

	}	
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;


	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		CameraCheck = true;
	}

	
		if (RGB(255, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(255, 0, 0)) && PosCheck.x < GetPos().ix())
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 0)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({ GetPos().x + 900,500 });
				Actor->GetPlayerCollision()->SetScale({ 500,500 });
				

			}
			MonsterCheck = 1;
		}
	
	

	
		if (RGB(254, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(254, 0, 0)) && PosCheck.x < GetPos().ix())
		{
			MonsterBulletRange = GetPos().x;

			if(MonsterCheck == 1)
			{
				
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({  1600,500 });
				Actor->GetPlayerCollision()->SetPosition({ -200,0 });
			}
			if (MonsterCheck == 1)
			{
				
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({  1650,500 });
				Actor->GetPlayerCollision();
			}
			
			MonsterCheck = 2;
		}
		
	


	
		if (RGB(253, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(253, 0, 0)) && PosCheck.x < GetPos().ix())
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 2)
			{
				bool check = false; 
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({ 1900,500 });
				Actor->GetPlayerCollision()->SetScale({ float4(static_cast<float>(rand() % 550) + 400,500) });
				Actor->SetRunCheck(check);
				MonsterCheck += 1;
			}
			MonsterCheck = 3;
		}

		if (RGB(252, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(252, 0, 0)) && PosCheck.x < GetPos().ix())
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 3)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({ 2350,300 });
						
			}

			if (MonsterCheck == 3)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({ 2650,600 });
				Actor->GetPlayerCollision()->SetPosition({ -200,0 });
			
			}
			MonsterCheck += 1;
		}



}

void Player::DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{
	std::string PrevDirString = DirString;

	std::vector<GameEngineActor*> Bullet = GetLevel()->GetActors(MetalSlugOrder::Bullet);

	std::vector<Bullets*> bullets;
	bullets.reserve(Bullet.size());
	//Bullets* b = dynamic_cast<Bullets*>(Bullet[d]);
	for (size_t i = 0; i < Bullet.size(); i++)
	{
		Bullets* bullet = dynamic_cast<Bullets*>(Bullet[i]);
		bullets.push_back(bullet);
	}

	bool Left = false;
	bool Right = true; 
	bool NotMove = false;
	bool Move = true;
	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());

	if (StateValue == PlayerState::MOVEATTACK || StateValue == PlayerState::IDLEATTACK || StateValue == PlayerState::HEAVYIDLEATTACK ||
		StateValue == PlayerState::UPATTACK   || StateValue == PlayerState::UPMOVEATTACK  || StateValue == PlayerState::HEAVYMOVEATTACK || StateValue == PlayerState::HEAVYUPATTACK
		|| StateValue == PlayerState::HEAVYUPMOVEATTACK
		&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(),true);
	}

	if (StateValue == PlayerState::IDLE)
	{
		AnimationBodyRender->SetScale({ 200,200 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYIDLE)
	{
		AnimationBodyRender->SetScale({ 400,400 });
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 15,body.y });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 15,body.y });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYIDLECHANGEUPATTACK)
	{
		AnimationBodyRender->SetScale({ 600,600 });
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x-40 ,body.y-18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x+35 ,body.y-18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYUPCHANGEIDLEATTACK)
	{
		AnimationBodyRender->SetScale({ 400,400 });
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 40 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYMOVECHANGEUPATTACK)
	{
		AnimationBodyRender->SetScale({ 600,600 });
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 40 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}
	if (StateValue == PlayerState::HEAVYUPCHANGEMOVEATTACK)
	{
		AnimationBodyRender->SetScale({ 400,400 });
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 40 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}


	if (StateValue == PlayerState::MOVE || StateValue == PlayerState::UPMOVE)
	{
		AnimationBodyRender->SetScale({ 200,200 });

		if (GameEngineInput::IsPress("LeftMove"))
		{

			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}

		else if (GameEngineInput::IsPress("RightMove"))
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYMOVE )
	{
		AnimationBodyRender->SetScale({ 400,400 });

		if (GameEngineInput::IsPress("LeftMove"))
		{

			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x -20 ,body.y-4 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}

		else if (GameEngineInput::IsPress("RightMove"))
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 20,body.y - 5 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYUPMOVE)
	{
		AnimationBodyRender->SetScale({ 400,400 });

		if (GameEngineInput::IsPress("LeftMove"))
		{

			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x-5  ,body.y-20 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}

		else if (GameEngineInput::IsPress("RightMove"))
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x+5 ,body.y-20 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::UP)
	{
		AnimationBodyRender->SetScale({ 200,200 });
		
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });
			
			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });
			
			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYUP)
	{
		AnimationBodyRender->SetScale({ 400,400 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x ,body.y - 15 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x ,body.y - 15 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}


	if (StateValue == PlayerState::UPATTACK || StateValue == PlayerState::UPMOVEATTACK)
	{
		AnimationBodyRender->SetScale({ 200,200 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });
			bullets[d]->Dir = Direction::Up;
			
			AnimationBodyRender->SetPosition({ body.x+10,body.y-120 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });
			bullets[d]->Dir = Direction::Up;
		
			AnimationBodyRender->SetPosition({ body.x-5,body.y -120});
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}
	if (GameEngineInput::IsDown("Attack"))
	{
		if (StateValue == PlayerState::IDLEATTACK || StateValue == PlayerState::MOVEATTACK)
		{
			AnimationBodyRender->SetScale({ 200,200 });
			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;

				AnimationBodyRender->SetPosition({ body.x - 38 , body.y + 7 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Right;

				AnimationBodyRender->SetPosition({ body.x + 40, body.y + 7 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
		}
		

		bullets[d]->test = true;

		d--;

	}
	
	if (StateValue == PlayerState::HEAVYIDLEATTACK || StateValue == PlayerState::HEAVYMOVEATTACK)
	{
		AnimationBodyRender->SetScale({ 400,400 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 50 ,body.y - 5 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		else if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 50 ,body.y - 5 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}

	if (StateValue == PlayerState::HEAVYUPATTACK || StateValue == PlayerState::HEAVYUPMOVEATTACK)
	{
		AnimationBodyRender->SetScale({ 600,600 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });


			AnimationBodyRender->SetPosition({ body.x + 15 ,body.y - 20 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 15 ,body.y - 20 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}

	}



	if (GameEngineInput::IsDown("Throw"))
	{
		
		

		if (StateValue == PlayerState::THROW)
		{

			if (BombNumber > 0)
			{
				BombNumber--;
			}

			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Left);
					Actor->SetMoveCheck(NotMove);
				}
				AnimationBodyRender->SetPosition({ body });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Right);
					Actor->SetMoveCheck(NotMove);
				}

				AnimationBodyRender->SetPosition({ body });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
		}
		if (StateValue == PlayerState::THROWMOVE)
		{
			if (BombNumber > 0)
			{
				BombNumber--;
			}




			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Left);
					Actor->SetMoveCheck(Move);
				}

				AnimationBodyRender->SetPosition({ body });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Right);
					Actor->SetMoveCheck(Move);
				}

				AnimationBodyRender->SetPosition({ body });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
		}

		


	}
	if (PrevDirString != DirString)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
		AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());
	}
	if (StateValue == PlayerState::MOVEATTACK || StateValue == PlayerState::IDLEATTACK || StateValue == PlayerState::HEAVYIDLEATTACK ||
		StateValue == PlayerState::UPATTACK || StateValue == PlayerState::UPMOVEATTACK || StateValue == PlayerState::HEAVYMOVEATTACK || StateValue == PlayerState::HEAVYUPATTACK
		|| StateValue == PlayerState::HEAVYUPMOVEATTACK
		&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(), true);
	}


}
// 1 body 2 reg 
void Player::JumpDirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{

	std::string PrevDirString = DirString;

	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());

	std::vector<GameEngineActor*> Bullet = GetLevel()->GetActors(MetalSlugOrder::Bullet);
	
	std::vector<Bullets*> bullets;
	for (size_t i = 0; i < Bullet.size(); i++)
	{
		Bullets* bullet = dynamic_cast<Bullets*>(Bullet[i]);
		bullets.push_back(bullet);
	}




	if (StateValue == PlayerState::JUMPDOWNATTACK || StateValue == PlayerState::JUMPMOVEUPATTACK || 
		StateValue == PlayerState::JUMPMOVEDOWNATTACK||StateValue == PlayerState::JUMPUPATTACK ||
		StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK ||
		StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYUPJUMPATTACK ||
		StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK  || StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK || 
		StateValue == PlayerState:: THROW
		&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(), true);
	}


	if (DirString == "Left_")
	{
		

		
			if (StateValue == PlayerState::JUMPUP || StateValue == PlayerState::JUMPDOWN)
			{
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x + 15,body.y - 22 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			else if (StateValue == PlayerState::HEAVYJUMPUP || StateValue == PlayerState::HEAVYJUMPDOWN)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x ,body.y - 22 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}


			else if (StateValue == PlayerState::JUMPMOVEUP || StateValue == PlayerState::JUMPMOVEDOWN)
			{
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x  ,body.y - 32 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

			else if (StateValue == PlayerState::HEAVYJUMPMOVEUP || StateValue == PlayerState::HEAVYUPJUMPUPMOVE)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x+10  ,body.y - 45 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

			
			else if (StateValue == PlayerState::HEAVYJUMPMOVEDOWN || StateValue == PlayerState::HEAVYUPJUMPDOWNMOVE)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x - 12 ,body.y - 40 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}
		
		

		if (GameEngineInput::IsDown("Attack"))
		{
			if (StateValue == PlayerState::JUMPUPATTACK || StateValue == PlayerState::JUMPDOWNATTACK)
			{				
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;
			
				AnimationBodyRender->SetPosition({ body.x - 38, body.y - 10 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			else if (StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;

				AnimationBodyRender->SetPosition({ body.x - 50, body.y - 10 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			else if (StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK)
			{
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Up;
			
				AnimationBodyRender->SetPosition({ body.x + 10,body.y - 135 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK)
			{
				AnimationBodyRender->SetScale({ 600,600 }); 
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Up;

				AnimationBodyRender->SetPosition({ body.x + 17,body.y - 35 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			

			else if (StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK)
			{
				
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Up;
			
				AnimationBodyRender->SetPosition({ body.x + 20 ,body.y - 150 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK)
			{
				AnimationBodyRender->SetScale({ 600,600 });
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Up;

				AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 50 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			


			else if (StateValue == PlayerState::JUMPMOVEUPATTACK)
			{
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;
			
				AnimationBodyRender->SetPosition({ body.x - 20  ,body.y - 25 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

			else if (StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;

				AnimationBodyRender->SetPosition({ body.x - 40  ,body.y - 38 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}



			else if (StateValue == PlayerState::JUMPMOVEDOWNATTACK)
			{
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;
			
				AnimationBodyRender->SetPosition({ body.x - 20  ,body.y - 25 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			else if (StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				LeftSetBody({ 0,0 });
				bullets[d]->Dir = Direction::Left;

				AnimationBodyRender->SetPosition({ body.x - 40  ,body.y - 38 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}


			bullets[d]->test = true;

			d--;	
		}	
	}

	if (DirString == "Right_")
	{
		
		
			if (StateValue == PlayerState::JUMPUP || StateValue == PlayerState::JUMPDOWN)
			{
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x - 15,body.y - 22 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
			}

			else if (StateValue == PlayerState::JUMPMOVEUP || StateValue == PlayerState::JUMPMOVEDOWN)
			{
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x-25 ,body.y -32 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
			}
			else if (StateValue == PlayerState::HEAVYJUMPUP || StateValue == PlayerState::HEAVYJUMPDOWN)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x + 15,body.y - 22 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
			}
			else if (StateValue == PlayerState::HEAVYJUMPMOVEUP || StateValue == PlayerState::HEAVYUPJUMPUPMOVE )
			{
				AnimationBodyRender->SetScale({ 400,400 });
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x-15 ,body.y -45 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
			else if ( StateValue == PlayerState::HEAVYJUMPMOVEDOWN || StateValue == PlayerState::HEAVYUPJUMPDOWNMOVE)
			{
				AnimationBodyRender->SetScale({ 400,400 });
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x - 10 ,body.y - 35 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}


			
		

			if (GameEngineInput::IsDown("Attack"))
			{
				if (StateValue == PlayerState::JUMPUPATTACK || StateValue == PlayerState::JUMPDOWNATTACK )
				{
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 38, body.y - 5 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}
				else if (StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 42, body.y - 20 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}
				else if (StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK)
				{
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Up;
					AnimationBodyRender->SetPosition({ body.x - 10,body.y - 135 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}
				else if (StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK)
				{

					AnimationBodyRender->SetScale({ 600,600 });

					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Up;
					AnimationBodyRender->SetPosition({ body.x - 17,body.y-35  });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}


				else if (StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK)
				{
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Up;
					AnimationBodyRender->SetPosition({ body.x-20 ,body.y - 150 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}

				else if (StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 600,600 });
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Up;
					AnimationBodyRender->SetPosition({ body.x - 30 ,body.y - 50 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}

				else if (StateValue == PlayerState::JUMPMOVEUPATTACK)
				{
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 30 ,body.y - 30 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					
				}


				else if (StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 43 ,body.y - 38 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";

				}



				else if (StateValue == PlayerState::JUMPMOVEDOWNATTACK)
				{
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 30 ,body.y -25 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";

				}

				else if (StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
					bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 43 ,body.y - 38 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}








				bullets[d]->test = true;
				d--;
			}
		
	}
	



	if (PrevDirString != DirString)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
		AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());
	}
	if (StateValue == PlayerState::JUMPDOWNATTACK || StateValue == PlayerState::JUMPMOVEUPATTACK ||
		StateValue == PlayerState::JUMPMOVEDOWNATTACK || StateValue == PlayerState::JUMPUPATTACK ||
		StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK ||
		StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYUPJUMPATTACK ||
		StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK || StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::THROW
		&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(), true);
	}
	

}

void Player::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);


	std::string MouseText = "MousePosition : ";
	MouseText += GetLevel()->GetMousePos().ToString();

	std::string CameraMouseText = "MousePositionCamera : ";
	CameraMouseText += GetLevel()->GetMousePosToCamera().ToString();

	GameEngineLevel::DebugTextPush(MouseText);
	GameEngineLevel::DebugTextPush(CameraMouseText);
	//BodyCollision->DebugRender();
    BulletCollision->DebugRender();
}