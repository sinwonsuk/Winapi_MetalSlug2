#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include <stdlib.h>
#include <math.h>
#include "Bullets.h"
#include "Monster.h"
#include "MonsterCamel.h"
#include "ContentsEnums.h"
#include "NPC.h"
#include "Carriage.h"
#include "RunMonster.h"
#include "Wall.h"
#include "Rebel.h"
#include "MiniBoss.h"
#include "BulletEffect.h"
#include "Boss.h"
#include "Bomb.h"
#include "HeavyGun.h"
#include "MiddleBoss.h"
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
	//GetLevel()->SetCameraPos({ 7600,0 });
	//CameraCheck = true;
	//MonsterCheck = 16;

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

		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeavyGunIdleAttack",  .ImageName = "RightHeavyGunIdleAttack.bmp", .Start = 0, .End = 6, .InterTime = 0.075f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeavyGunIdleAttack",  .ImageName = "LeftHeavyGunIdleAttack.bmp", .Start = 0, .End = 6, .InterTime = 0.075f , .Loop = false });




	




		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunUpAttack",  .ImageName = "RightHeavyUpAttack.bmp", .Start = 0, .End = 3, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunUpAttack",  .ImageName = "LeftHeavyUpAttack.bmp", .Start = 0, .End = 3, .InterTime = 0.1f , .Loop = false });

	

			

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunDownAttack",  .ImageName = "RightHeaveGunDownAttack.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunDownAttack",  .ImageName = "LeftHeaveGunDownAttack.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });

		/*AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunThrow",  .ImageName = "RightHeaveGunThrow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunThrow",  .ImageName = "LeftHeaveGunThrow.bmp", .Start = 0, .End = 5, .InterTime = 0.1f , .Loop = true });
		*/
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunIdleChangeUp",  .ImageName = "RightHeavyIdleChangeUp.bmp", .Start = 0, .End = 2, .InterTime = 0.075f , .Loop = false ,.FrameIndex{0,1,2,2} });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunIdleChangeUp",  .ImageName = "LeftHeavyIdleChangeUp.bmp", .Start = 0, .End = 2, .InterTime = 0.075f , .Loop = false ,.FrameIndex{0,1,2,2}});

		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunUpChangeIdle",  .ImageName = "RightHeavyUpChangeIdle.bmp",  .InterTime = 0.05f , .Loop = false,.FrameIndex{0,1,1} });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunUpChangeIdle",  .ImageName = "LeftHeavyUpChangeIdle.bmp",  .InterTime = 0.05f , .Loop = false,.FrameIndex{0,1,1} });


		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_HeaveGunThrow",  .ImageName = "Right_HeavyGun_Throw.bmp", .Start = 0, .End = 5, .InterTime = 0.05f , .Loop = false});
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_HeaveGunThrow",  .ImageName = "Left_HeavyGun_Throw.bmp", .Start = 0, .End = 5, .InterTime = 0.05f , .Loop = false});


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

		
	}
	{
		parachuteRender = CreateRender(MetalSlugOrder::PlayerReg);
		parachuteRender->SetScale({ 800, 800 });
		parachuteRender->SetPosition({ -10,-75 });
		parachuteRender->CreateAnimation({ .AnimationName = "parachute",    .ImageName = "parachute.bmp", .Start = 0, .End = 4, .InterTime = 0.12f,.Loop = true});
		parachuteRender->CreateAnimation({ .AnimationName = "parachuteDown",    .ImageName = "parachuteDown.bmp" ,.Start = 0, .End = 18, .InterTime = 0.05f,.Loop = true });
	}

	    parachuteRender->ChangeAnimation("parachute");
	  //  parachuteRender->SetMove({ 200,200 });



	ChangeState(PlayerState::JUMPDOWN);
	//ChangeState(PlayerState::HEAVYIDLE);
	{
		BodyCollision = CreateCollision(MetalSlugOrder::PlayerReg);
		BodyCollision->SetScale({ 100, 100 });
		BodyCollision->SetPosition({ 0,-50 });

	}
	

}

//void Player::Update(float _DeltaTime) 
//{
//	UpdateState(_DeltaTime);
//}

void Player::Movecalculation(float _DeltaTime)
{
	if (BackGroundSound == false)
	{
		

		MissionStart = GameEngineResources::GetInst().SoundPlayToControl("MissionStart.mp3");
		MissionStart.LoopCount(1);

		bgm = GameEngineResources::GetInst().SoundPlayToControl("BackgroundSound.mp3");
		BackGroundSound = true;
	}
	
	
	

	if (Gravity == true)
	{		
		MoveDir += float4::Down * 1500.0f * _DeltaTime;

		if (true == parachuteRender->IsAnimationEnd())
		{
			parachuteRender->Off(); 
		}

	}
	if (Gravity == false)
	{
		test = true;
		MoveDir = float4::Down * 20000.0f * _DeltaTime;
		//MoveDir += float4::Down * 1500.0f * _DeltaTime;
	}
	
	if (true == GameEngineInput::IsDown("test"))
	{
		if (GunChange == false)
		{
			ChangeState(PlayerState::HEAVYIDLE);
			GunChange = true;
		}
		else if (GunChange == true)
		{
			ChangeState(PlayerState::IDLE);
			GunChange = false;
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
	float4 NextPos1 = GetPos() + float4{1, 0}; 
	
	
	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		CameraCheck = true;	
	}

	/*if (MonsterCheck == 7)
	{

		if (Carriage::carriage->GetNotMove() == true)
		{

			if (RGB(0, 0, 255) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 255)))
			{
				blueCheck = true;
				CurPos = GetPos();
				CameraCheck = false;
				SetMove({ -5,0 });
			}
			if (CurPos.x < GetPos().x && blueCheck == true)
			{
				CameraCheck = true;
				blueCheck = false;
			}
		}
	}*/

	if ((RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)) || RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255,0)) || RGB(0, 254, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 254, 0))) && MoveDir.y >= -80)
	{
		if (GunChange == false)
		{
			if (test == true)
			{

				AnimationBodyRender->SetScale({ 200,200 });
				AnimationBodyRender->SetPosition({ body });

				ChangeState(PlayerState::IDLE);
				
			}
			test = false;
			Check = false;			
		}
		else if (GunChange == true)
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
		}		
	}
	

	if (false == Check )
	{
		while (true)
		{
			MoveDir.y -= 1;




			float4 NextPos = GetPos() + MoveDir * _DeltaTime;

			if ((RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)) || RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 254, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 254, 0))))
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
			Gravity = true;
			Check = true;
			break;
		}
	}
	GroundCheck = false;


	if (CameraCheck == true && PosCheck.x < GetPos().ix())
	{		
		GroundCheck = true;
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
	

	if (GunChange == true && HeavyMachineGun > 0)
	{
		CameraDir = { 0,0 };

		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			MoveDir += float4::Left * MoveSpeed;
		}

		
		
		if (DirStringBullet == "Right")
		{
			CurDirStringBullet = "Right"; 
			RightAttackChangeUp = 0;
			UPHeavyBulletNumber = 0;
			UpHeavyBulletTime = 0;

			if (RightHeavyBulletTime > 0 && RightHeavyBulletNumber == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 100,GetPos().y - 75 });
				HeavyBullet->Dir = Direction::Right;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-1);
				RightHeavyBulletNumber = 1;
			}
			if (RightHeavyBulletTime > 0.1 && RightHeavyBulletNumber == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 100,GetPos().y - 55 });
				HeavyBullet->Dir = Direction::Right;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(1);
				RightHeavyBulletNumber = 2;
			}

			if (RightHeavyBulletTime > 0.2 && RightHeavyBulletNumber == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 100,GetPos().y - 75 });
				HeavyBullet->Dir = Direction::Right;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(2);
				RightHeavyBulletNumber = 3;
			}

			if (RightHeavyBulletTime > 0.3 && RightHeavyBulletNumber == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 100,GetPos().y - 55});
				HeavyBullet->Dir = Direction::Right;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(0);
				
				RightHeavyBulletNumber = 0;
				RightHeavyBulletCheck = false;
				RightHeavyBulletTime = 0;

			}

		
			if (true == GameEngineInput::IsPress("RightMove"))
			{
				MoveDir += float4::Right * MoveSpeed;
				CameraDir = float4::Right * MoveSpeed * _DeltaTime;
			}
		}


		if (DirStringBullet == "Left")
		{
			
			LeftAttackChangeUp = 0;
			UPHeavyBulletNumber = 0;
			UpHeavyBulletTime = 0;

			if (LeftHeavyBulletTime > 0 && LeftHeavyBulletNumber == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-100 , GetPos().y - 75 });
				HeavyBullet->Dir = Direction::Left;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-181);
				LeftHeavyBulletNumber = 1;
			}
			if (LeftHeavyBulletTime > 0.1 && LeftHeavyBulletNumber == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x - 100 , GetPos().y - 55 });
				HeavyBullet->Dir = Direction::Left;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(181);
				LeftHeavyBulletNumber = 2;
			}

			if (LeftHeavyBulletTime > 0.2 && LeftHeavyBulletNumber == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x - 100 , GetPos().y - 70 });
				HeavyBullet->Dir = Direction::Left;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(183);
				LeftHeavyBulletNumber = 3;
			}

			if (LeftHeavyBulletTime > 0.3 && LeftHeavyBulletNumber == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x - 100 , GetPos().y - 55 });
				HeavyBullet->Dir = Direction::Left;
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(180);

				LeftHeavyBulletNumber = 0;
				LeftHeavyBulletCheck = false;
				LeftHeavyBulletTime = 0;

			}


			if (true == GameEngineInput::IsPress("RightMove"))
			{
				MoveDir += float4::Right * MoveSpeed;
				CameraDir = float4::Right * MoveSpeed * _DeltaTime;
			}



		}


		if (DirStringBullet == "BRIGHT" )
		{
			
			if ( RightAttackChangeUp == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+20 , GetPos().y - 75 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-10);
				HeavyBullet->Dir = Direction::A;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightAttackChangeUp = 1;
			}
			if ( RightAttackChangeUp == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 20 , GetPos().y - 55 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-30);
				HeavyBullet->Dir = Direction::B;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightAttackChangeUp = 2;
			}

			if ( RightAttackChangeUp == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 20 , GetPos().y - 75 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-50);
				HeavyBullet->Dir = Direction::C;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightAttackChangeUp = 3;
			}

			if ( RightAttackChangeUp == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x + 20 , GetPos().y - 55 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-70);
				HeavyBullet->Dir = Direction::D;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown = 0;
				RightAttackChangeUp = 4;
			
				UpHeavyBulletCheck = false;
				UpHeavyBulletTime = 0;
				UPHeavyBulletNumber = 0;

				RightHeavyBulletNumber = 0;
				RightHeavyBulletCheck = false;
				RightHeavyBulletTime = 0;
			}
		


		}
		

		if (DirStringBullet == "BLEFT")
		{
			if (LeftAttackChangeUp == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-20 , GetPos().y -75 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-170);
				HeavyBullet->Dir = Direction::LeftA;
					
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				LeftAttackChangeUp = 1;
			}
			if (LeftAttackChangeUp == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x - 20 , GetPos().y - 55 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-150);
				HeavyBullet->Dir = Direction::LeftB;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				LeftAttackChangeUp = 2;
			}

			if (LeftAttackChangeUp == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x - 20 , GetPos().y - 75 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-130);
				HeavyBullet->Dir = Direction::LeftC;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				LeftAttackChangeUp = 3;
			}

			if (LeftAttackChangeUp == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x - 20 , GetPos().y - 55 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-110);
				HeavyBullet->Dir = Direction::LeftD;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown = 0;
				LeftAttackChangeUp = 4;

				UpHeavyBulletCheck = false;
				UpHeavyBulletTime = 0;
				UPHeavyBulletNumber = 0;

				LeftHeavyBulletNumber = 0;
				LeftHeavyBulletCheck = false;
				LeftHeavyBulletTime = 0;
			}
		}


		if (DirStringBullet == "ARIGHT")
		{
			if (RightUpChangeAttack == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+20 , GetPos().y - 75 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-80);
				HeavyBullet->Dir = Direction::D;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightUpChangeAttack = 1;
			}
			if (RightUpChangeAttack == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+20 , GetPos().y - 55 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-50);
				HeavyBullet->Dir = Direction::C;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightUpChangeAttack = 2;
			}

			if (RightUpChangeAttack == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+20 , GetPos().y - 75 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-30);
				HeavyBullet->Dir = Direction::B;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightUpChangeAttack = 3;
			}

			if (RightUpChangeAttack == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+20 , GetPos().y - 55 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-10);
				HeavyBullet->Dir = Direction::A;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown = 0;
				RightUpChangeAttack = 4;

				UpHeavyBulletCheck = false;
				UpHeavyBulletTime = 0;
				UPHeavyBulletNumber = 0;

				RightHeavyBulletNumber = 0;
				RightHeavyBulletCheck = false;
				RightHeavyBulletTime = 0;
			}



		}
		if (DirStringBullet == "ALEFT")
		{
			if (RightUpChangeAttack == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-20 , GetPos().y - 50 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-110);
				HeavyBullet->Dir = Direction::LeftD;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightUpChangeAttack = 1;
			}
			if (RightUpChangeAttack == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x -20, GetPos().y - 25 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-130);
				HeavyBullet->Dir = Direction::LeftC;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightUpChangeAttack = 2;
			}

			if (RightUpChangeAttack == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-20 , GetPos().y - 50 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-150);
				HeavyBullet->Dir = Direction::LeftB;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown += 200;
				RightUpChangeAttack = 3;
			}

			if (RightUpChangeAttack == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-20 , GetPos().y - 25 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-170);
				HeavyBullet->Dir = Direction::LeftA;
				HeavyBullet->Speed -= SpeedDown;
				SpeedDown = 0;
				RightUpChangeAttack = 4;

				UpHeavyBulletCheck = false;
				UpHeavyBulletTime = 0;
				UPHeavyBulletNumber = 0;

				RightHeavyBulletNumber = 0;
				RightHeavyBulletCheck = false;
				RightHeavyBulletTime = 0;
			}



		}

		if (DirStringBullet == "Up")
		{
			CurDirStringBullet = "Up";
			RightAttackChangeUp = 0;
			RightUpChangeAttack = 0;
			if (UpHeavyBulletTime > 0 && UPHeavyBulletNumber == 0)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+10 , GetPos().y - 170 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-88);
				HeavyBullet->Dir = Direction::Up;
				UPHeavyBulletNumber = 1;
			}
			if (UpHeavyBulletTime > 0.1 && UPHeavyBulletNumber == 1)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-10 , GetPos().y - 170 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-90);
				HeavyBullet->Dir = Direction::Up;
				UPHeavyBulletNumber = 2;
			}

			if (UpHeavyBulletTime > 0.2 && UPHeavyBulletNumber == 2)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x+10 , GetPos().y - 170 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-92);
				HeavyBullet->Dir = Direction::Up;
				UPHeavyBulletNumber = 3;
			}

			if (UpHeavyBulletTime > 0.3 && UPHeavyBulletNumber == 3)
			{
				HeavyGun* HeavyBullet = GetLevel()->CreateActor<HeavyGun>();
				HeavyMachineGun -= 1;
				HeavyBullet->SetPos({ GetPos().x-10 , GetPos().y -170 });
				HeavyBullet->MoveDir = float4::AngleToDirection2DToDeg(-89);
				HeavyBullet->Dir = Direction::Up;
				
				UPHeavyBulletNumber = 0;
				UpHeavyBulletCheck = false;
				UpHeavyBulletTime = 0;

			}
		}				
	}
	if (HeavyMachineGun < 0)
	{
		HeavyMachineGun = 0;
	}


	if (HeavyMachineGun <= 0)
	{
		if (GunChange == true)
		{
			GunChange = false;
			ChangeState(PlayerState::IDLE);
		}
		
	}
	if (HeavyMachineGun > 0)
	{
		if (GunChange == false)
		{
			ChangeState(PlayerState::HEAVYIDLE);
			GunChange = true;
		}
	
	}



		if (RightHeavyBulletCheck == true)
		{
		   RightHeavyBulletTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		}
		if (UpHeavyBulletCheck ==  true)
		{
			UpHeavyBulletTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		}

		if (LeftHeavyBulletCheck == true)
		{
			LeftHeavyBulletTime += GameEngineTime::GlobalTime.GetFloatDeltaTime();
		}





	if (true == GameEngineInput::IsPress("Freemove"))
	{
		FreeMode = true;

	}

	/*if (GameEngineInput::IsDown("Attack") )
	{
		HeavyBulletCheck = true;	
	}*/




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
	

	UpdateState(_DeltaTime);
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
	
	
	
	
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

	if (nullptr != RightBulletCollision)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == RightBulletCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
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
				Actor->SetPos({ GetPos().x + 900,500 });
		
			

			}
			MonsterCheck = 1;
		}
	
	

	
		if (RGB(254, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(254, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 1)
		{
			MonsterBulletRange = GetPos().x;

			if(MonsterCheck == 1)
			{
				
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({  1700,600 });
			
			}
			if (MonsterCheck == 1)
			{
				
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({  1750,600 });
			
			}
			
			MonsterCheck = 2;
		}
		
	


	
		if (RGB(253, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(253, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 2)
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 2)
			{
				bool check = false; 
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 1900,500 });
				Actor->SetRunCheck(check);
			
			}
			if (MonsterCheck == 2)
			{
				
				NPC* Actor = GetLevel()->CreateActor<NPC>();
				Actor->SetPos({ 2000,700 });
				Actor->SetItemCheck(false);
			}
			if (MonsterCheck == 2)
			{

				NPC* Actor = GetLevel()->CreateActor<NPC>();
				Actor->SetPos({ 2140,400 });
				Actor->SetDownCheck(false); 
				Actor->SetItemCheck(true);
			}


			MonsterCheck = 3;
		}

		if (RGB(252, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(252, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 3)
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 3)

			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 2350,300 });
						
			}

			if (MonsterCheck == 3)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 2650,600 });
				
			
			}
			MonsterCheck = 4;
		}

		if (RGB(251, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(251, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 4)
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 4)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 3200,600 });

			}

			if (MonsterCheck == 4)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 3400,600 });
			

			}
			MonsterCheck = 5;
		}

		/*if (RGB(250, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(250, 0, 0)) && PosCheck.x < GetPos().ix())
		{
			MonsterBulletRange = GetPos().x;

			if (MonsterCheck == 5)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({ 3800,600 });

			}

			if (MonsterCheck == 5)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetMove({ 4000,600 });
				Actor->GetPlayerCollision()->SetPosition({ -200,0 });

			}
			MonsterCheck = 6;
		}*/

		if (RGB(249, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(249, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 5)
		{
			MonsterBulletRange = GetPos().x;
		    CameraMoveCheck = GetPos(); 
			CameraCheck = false;

			if (MonsterCheck == 5)
			{
				NPC* Actor = GetLevel()->CreateActor<NPC>();
				Actor->SetPos({ 4200, 300 });

				Actor->ChangeState(NpcState::BIND);
				Actor->SetItemCheck(false);
				Actor->SetTurn(false); 
			}

			if (MonsterCheck == 5)
			{
				NPC* Actor = GetLevel()->CreateActor<NPC>();
				Actor->SetPos({ 4500, 300 });
				Actor->SetItemCheck(true);
				Actor->SetDownCheck(true); 
			}

			if (MonsterCheck == 5)
			{
				
				MonsterCamel* Actor = GetLevel()->CreateActor<MonsterCamel>();
				Actor->SetPos({ 4000,700 });
			

			}
			MonsterCheck = 6;
		}
		if (RGB(248, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(248, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 6)
		{
			//MonsterBulletRange = GetPos().x;
			//CameraMoveCheck = GetPos();
			//CameraCheck = false;

			if (MonsterCheck == 6)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 4350,220 });
	
			}

			if (MonsterCheck == 6)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 4350,410 });
			//	Actor->GetPlayerCollision()->SetPosition({ 50,0 });
			
			}

			if (MonsterCheck == 6)
			{
				bool Check = false;
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 4500,350 });
			//	Actor->GetPlayerCollision()->SetPosition({ -150,0 });
				Actor->SetRunCheck(Check);

			}
			MonsterCheck = 7;
		}
		if (RGB(246, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(246, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 7 && MonsterDeathCheck== false)
		{
			CameraCheck = false;
			CameraMoveCheck = GetPos();


			if (MonsterCheck == 7)
			{
				Monster*monster = GetLevel()->CreateActor<Monster>();
				monster->SetPos({ 5300, 100 });
			
			}

			if (MonsterCheck == 7)
			{
				Monster* monster = GetLevel()->CreateActor<Monster>();
				monster->SetPos({ 5300, 300 });
			

			}

			MonsterDeathCheck = true; 

		
		}
		
		

		if (MonsterDeathCheck == true)
		{
			MonsterTime += GameEngineTime::GlobalTime.GetFloatDeltaTime(); 

			if (MonsterTime > 3)
			{
				if (MonsterCheck == 7)
				{
					Carriage* Actor = GetLevel()->CreateActor<Carriage>();
					Actor->SetPos({ 5500,700 });

				}

				if (MonsterCheck == 7)
				{

					RunMonster* Actor = GetLevel()->CreateActor<RunMonster>();
					Actor->SetPos({ 5600,700 });
				}
				if (MonsterCheck == 7)
				{

					RunMonster* Actor = GetLevel()->CreateActor<RunMonster>();
					Actor->SetPos({ 5680,700 });

				}

				if (MonsterCheck == 7)
				{

					RunMonster* Actor = GetLevel()->CreateActor<RunMonster>();
					Actor->SetPos({ 5760,700 });

				}
				if (MonsterCheck == 7)
				{

					RunMonster* Actor = GetLevel()->CreateActor<RunMonster>();
					Actor->SetPos({ 5840,700 });

				}

				if (MonsterCheck == 7)
				{
					MiniBoss* Actor = GetLevel()->CreateActor<MiniBoss>();
					Actor->SetPos({ 5920,700 });
				}
				if (MonsterCheck == 7)
				{
					NPC* Actor = GetLevel()->CreateActor<NPC>();
					Actor->ChangeState(NpcState::BIND);
					Actor->SetPos({ 5500,300 });
				}




				MonsterDeathCheck = false;
				MonsterCheck = 8;
			}
			

		
		}
				
		

	
		if (RGB(245, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(245, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 8)
		{
			if (MonsterCheck == 8)
			{
				MiddleBoss * middleBoss = GetLevel()->CreateActor<MiddleBoss>();
				middleBoss->SetPos({ 6520,500 });	

			}
		
			


			if (MonsterCheck == 8)
			{
				RunMonster*Atcor = GetLevel()->CreateActor<RunMonster>();
				Atcor->ChangeState(RunMonsterState::IDLE);
				Atcor->SetPos({ 6840,300 });
			}
			if (MonsterCheck == 8)
			{
				RunMonster* Atcor = GetLevel()->CreateActor<RunMonster>();
				Atcor->ChangeState(RunMonsterState::IDLE);
				Atcor->SetPos({ 6920,300 });
			}
			if (MonsterCheck == 8)
			{
				RunMonster* Atcor = GetLevel()->CreateActor<RunMonster>();
				Atcor->ChangeState(RunMonsterState::IDLE);
				Atcor->SetPos({ 7000,300 });
			}
			if (MonsterCheck == 8)
			{
				MiniBoss* Actor = GetLevel()->CreateActor<MiniBoss>();
				Actor->ChangeState(MiniMonsterState::IDLE);
				Actor->SetPos({ 7080,300 });
				Actor->compulsionAttack = true;
			}

			MonsterCheck = 9;
		}


		if (MonsterCheck == 9 && CameraMoveCheck.x > GetPos().x )
		{
			CameraCheck = true;
			PosCheck = CameraMoveCheck;
			MonsterCheck = 10;
		}


		if (MonsterCheck == 9 && CameraMoveCheck.x < GetPos().x)
		{
			float4 b = float4::Right * 1000 * _DeltaTime;

			GetLevel()->SetCameraMove(b);

			if (GetLevel()->GetCameraPos().x > Player::MainPlayer->GetPos().x - 350)
			{
				CameraCheck = true;
				PosCheck = GetPos();
				MonsterCheck = 10;
			}
		}


		if (GetLevel()->GetCameraPos().x > 6140 && MonsterCheck == 10)
		{
			CameraCheck = false;
			
			MonsterCheck = 11; 
	    }
	

		if (RGB(244, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(244, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 11)
		{
			//CameraCheck = true;

			if (MonsterCheck == 11)
			{
				Wall* Actor = GetLevel()->CreateActor<Wall>();
				Actor->SetPos({ 8400,770 });
			}
			if (MonsterCheck == 11)
			{
				Rebel* Actor = GetLevel()->CreateActor<Rebel>();
				Actor->SetPos({ 8000,500 });
				//Actor->ChangeState(RebelState::IDLE);
			}
			if (MonsterCheck == 11)
			{
				Rebel* Actor = GetLevel()->CreateActor<Rebel>();
				Actor->SetPos({ 8200,500 });
				Actor->ChangeState(RebelState::IDLE2);
			}
			if (MonsterCheck == 11)
			{
				Rebel* Actor = GetLevel()->CreateActor<Rebel>();
				Actor->ChangeState(RebelState::ATTACK);
				Actor->SetPos({ 8350,0 });
			}


			MonsterCheck = 12;
		}
		if (MonsterCheck == 12 && MiddlebossBoom == true && CameraMoveCheck.x > GetPos().x)
		{
			CameraCheck = true;
			PosCheck = CameraMoveCheck;
			MonsterCheck = 13;
		}

		if (MonsterCheck == 12 && MiddlebossBoom == true )
		{
			float4 b = float4::Right * 1000 * _DeltaTime;

			GetLevel()->SetCameraMove(b);

			if (GetLevel()->GetCameraPos().x > Player::MainPlayer->GetPos().x - 350)
			{
				CameraCheck = true;
				PosCheck = GetPos();
				MonsterCheck = 13;
			}
		}

		
		if (RGB(243, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(243, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 13)
		{		
			if (MonsterCheck == 13)
			{
				RebelStart = true;
			}
			MonsterCheck = 14;		
		}
		if (RGB(242, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(242, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 14)
		{
			

			if (MonsterCheck == 14)
			{
				PosCheck = CameraMoveCheck;
				CameraCheck = false;
			}
			MonsterCheck = 15;
		}

		if (RGB(241, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(241, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 15)
		{
			if (MonsterCheck == 8)
			{
				NPC* Actor = GetLevel()->CreateActor<NPC>();
				Actor->SetPos({ 9500, 300 });
				Actor->SetItemCheck(true);
				Actor->SetDownCheck(true);

			}

			if (MonsterCheck == 15)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 9600,300 });
			
			}
			if (MonsterCheck == 15)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 9600,500 });
			
			}
			MonsterCheck = 16;
		}

		if (RGB(240, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(240, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 16)
		{
			if (MonsterCheck == 16)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 9900,300 });
			
			}
			if (MonsterCheck == 16)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 9900,600 });
			
			}
			MonsterCheck = 17;
		}
		if (RGB(239, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(239, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 17)
		{
			if (MonsterCheck == 17)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 10200,300 });
				
			}
			if (MonsterCheck == 17)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 10200,600 });
			
			}
			if (MonsterCheck == 17)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 10300,300 });
			
			}
			if (MonsterCheck == 17)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 10350,600 });
			
			}

			MonsterCheck = 18;
		}
		if (RGB(238, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(238, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 18)
		{
			if (MonsterCheck == 18)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 10500,600 });
			
			}
			if (MonsterCheck == 18)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 10500,600 });
				
			}
			MonsterCheck = 19;
		}
		if (RGB(237, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(237, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 19)
		{
			if (MonsterCheck == 19)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 11400,600 });
				
			}
			if (MonsterCheck == 19)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 11500,600 });
			
			}
			if (MonsterCheck == 19)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 11600,600 });
			
			}
			if (MonsterCheck == 19)
			{
				Monster* Actor = GetLevel()->CreateActor<Monster>();
				Actor->SetPos({ 11700,600 });
			
			}


			MonsterCheck = 20;
		}
		if (RGB(236, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(236, 0, 0)) && PosCheck.x < GetPos().ix() && MonsterCheck == 21)
		{
			Boss * boss = GetLevel()->CreateActor<Boss>();
			boss->SetPos({ 11800,100 });
			MonsterCheck = 22;
		}
		/*if (GetLevel()->GetCameraPos().x >= 11367)
		{
			CameraCheck = false;
			boss->BossStart = true;
		}
		if (boss != nullptr)
		{
			if (boss->Hp <= 0)
			{
				AnimationBodyRender->Off();
				AnimationRegRender->Off();
			}
		}*/

}

void Player::DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{
	std::string PrevDirString = DirString;

	
	bool Left = false;
	bool Right = true; 
	bool NotMove = false;
	bool Move = true;
	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());

	if (StateValue == PlayerState::MOVEATTACK || StateValue == PlayerState::IDLEATTACK || 
		StateValue == PlayerState::UPATTACK   || StateValue == PlayerState::UPMOVEATTACK  
			&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(),true);
	}

	if ( StateValue == PlayerState::HEAVYIDLEATTACK ||
		 StateValue == PlayerState::HEAVYMOVEATTACK || StateValue == PlayerState::HEAVYUPATTACK
		|| StateValue == PlayerState::HEAVYUPMOVEATTACK
		&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(), true);
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
			DirStringBullet = "Left";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "Right";
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
		//	DirStringBullet = "Left";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 15,body.y });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			//DirStringBullet = "Right";
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
			DirStringBullet = "BLEFT";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x+35 ,body.y-18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "BRIGHT";
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
			DirStringBullet = "Left";
			DirStringBullet = "ALEFT";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "ARIGHT";
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
			DirStringBullet = "BLEFT";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "BRIGHT";
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
			DirStringBullet = "Left";
			DirStringBullet = "ALEFT";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 18 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "ARIGHT";
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
		    DirStringBullet = "Left";
		}

		else if (GameEngineInput::IsPress("RightMove"))
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "Right";
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
		//	DirStringBullet = "Left";
		}

		else if (GameEngineInput::IsPress("RightMove"))
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x + 20,body.y - 5 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		//	DirStringBullet = "Right";
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
			DirStringBullet = "Up";
		
		}

		else if (GameEngineInput::IsPress("RightMove"))
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x+5 ,body.y-20 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "Up";
		
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
			//DirStringBullet = "Up";

		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x ,body.y - 15 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			//DirStringBullet = "Up";
		}
	}


	if (StateValue == PlayerState::UPATTACK || StateValue == PlayerState::UPMOVEATTACK)
	{
		AnimationBodyRender->SetScale({ 200,200 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });
			Bullets* Actor = GetLevel()->CreateActor<Bullets>();
			Actor->SetPos({ GetPos().x,GetPos().y - 200 });
			Actor->MoveDir = float4::Up;
			
			AnimationBodyRender->SetPosition({ body.x+10,body.y-120 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
			DirStringBullet = "Up";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });
			Bullets* Actor = GetLevel()->CreateActor<Bullets>();
			Actor->SetPos({ GetPos().x,GetPos().y - 200 });
			Actor->MoveDir = float4::Up;
		
			AnimationBodyRender->SetPosition({ body.x-5,body.y -120});
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "Up";
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


				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x-100,GetPos().y - 95 });
				Actor->MoveDir = float4::Left;

				/*BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetPos({ GetPos().x - 100,GetPos().y - 95 });
				Effect->MoveDir = float4::Left;*/

				AnimationBodyRender->SetPosition({ body.x - 38 , body.y + 7 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
				DirStringBullet = "Left";
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });
				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x+100,GetPos().y - 95 });
				Actor->MoveDir = float4::Right;

			/*	BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetPos({ GetPos().x + 100,GetPos().y - 95 });
				Effect->MoveDir = float4::Right;*/

				AnimationBodyRender->SetPosition({ body.x + 40, body.y + 7 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
				DirStringBullet = "Right";

			}
		}
		
	}
	

	if (StateValue == PlayerState::HEAVYIDLEATTACK)
	{

		AnimationBodyRender->SetScale({ 400,400 });

		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x - 50 ,body.y - 5 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
			DirStringBullet = "Left";
			LeftHeavyBulletCheck = true;

		}

		else if (DirString == "Right_")
		{

			

			RightSetBody({ 0,0 });
			
			AnimationBodyRender->SetPosition({ body.x + 50 ,body.y - 5 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
			DirStringBullet = "Right";

			
			RightHeavyBulletCheck = true;

		

		}


	}








			
		
		if (StateValue == PlayerState::HEAVYMOVEATTACK)
		{

			AnimationBodyRender->SetScale({ 400,400 });

			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				AnimationBodyRender->SetPosition({ body.x - 50 ,body.y - 5 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
				DirStringBullet = "Left";
				LeftHeavyBulletCheck = true;
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });

				AnimationBodyRender->SetPosition({ body.x + 50 ,body.y - 5 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
				DirStringBullet = "Right";
				RightHeavyBulletCheck = true;
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
				DirStringBullet = "Up";

				UpHeavyBulletCheck = true;
			}
			if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });

				AnimationBodyRender->SetPosition({ body.x - 15 ,body.y - 20 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
				DirStringBullet = "Up";

				UpHeavyBulletCheck = true;
				//UpHeavyBulletTime = 0;
			}

		}
	


	if (GameEngineInput::IsDown("Throw"))
	{
		
		

		if (StateValue == PlayerState::THROW)
		{

			
			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					
						Bomb*Actor = GetLevel()->CreateActor<Bomb>();
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
					
					Bomb* Actor = GetLevel()->CreateActor<Bomb>();
						Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
						Actor->MoveDir += float4::Up * 550;
						Actor->SetDirCheck(Right);
						Actor->SetMoveCheck(NotMove);
					
				}

				AnimationBodyRender->SetPosition({ body });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}

			if (BombNumber > 0)
			{
				BombNumber--;
			}

		}
		if (StateValue == PlayerState::THROWMOVE)
		{
			



			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					
						Bomb* Actor = GetLevel()->CreateActor<Bomb>();
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
					
					Bomb* Actor = GetLevel()->CreateActor<Bomb>();
						Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
						Actor->MoveDir += float4::Up * 550;
						Actor->SetDirCheck(Right);
						Actor->SetMoveCheck(Move);
									
				}

				AnimationBodyRender->SetPosition({ body });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
			if (BombNumber > 0)
			{
				BombNumber--;
			}

		}

		if (StateValue == PlayerState::HEAVYTHROW)
		{
			AnimationBodyRender->SetScale({ 600,600 });
			
			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Bomb* Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x - 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Left);
					Actor->SetMoveCheck(NotMove);
				}
				AnimationBodyRender->SetPosition({ body.x -20,  body.y});
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Bomb* Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Right);
					Actor->SetMoveCheck(NotMove);
				}

				AnimationBodyRender->SetPosition({ body.x+20,body.y-48 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
			if (BombNumber > 0)
			{
				--BombNumber;
			}

		}
		if (StateValue == PlayerState::HEAVYTHROWMOVE)
		{
			
			AnimationBodyRender->SetScale({ 600,600 });



			if (DirString == "Left_")
			{
				LeftSetBody({ 0,0 });

				if (BombNumber >= 0)
				{
					Bomb* Actor = GetLevel()->CreateActor<Bomb>();
					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Left);
					Actor->SetMoveCheck(Move);
				}

				AnimationBodyRender->SetPosition({ body.x-25,body.y });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			else if (DirString == "Right_")
			{
				RightSetBody({ 0,0 });

				if (BombNumber > 0)
				{
					Bomb* Actor = GetLevel()->CreateActor<Bomb>();


					Actor->SetPos({ GetPos().x + 50,GetPos().y - 100 });
					Actor->MoveDir += float4::Up * 550;
					Actor->SetDirCheck(Right);
					Actor->SetMoveCheck(Move);
				}

				AnimationBodyRender->SetPosition({ body.x+25,  body.y-50});
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";

			}
			if (BombNumber > 0)
			{
				--BombNumber;
			}

		}


	}
	if (PrevDirString != DirString)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
		AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());
	}
	if (StateValue == PlayerState::MOVEATTACK || StateValue == PlayerState::IDLEATTACK ||
		StateValue == PlayerState::UPATTACK || StateValue == PlayerState::UPMOVEATTACK
		&& AnimationBodyRender->GetFrame() > 1)
	{
		AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data(), true);
	}

	if (StateValue == PlayerState::HEAVYIDLEATTACK ||
		StateValue == PlayerState::HEAVYMOVEATTACK || StateValue == PlayerState::HEAVYUPATTACK
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

	

	

	
	if (StateValue == PlayerState::JUMPDOWNATTACK || StateValue == PlayerState::JUMPMOVEUPATTACK || 
		StateValue == PlayerState::JUMPMOVEDOWNATTACK||StateValue == PlayerState::JUMPUPATTACK ||
		StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK ||
		StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK ||
		StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK  || StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK || 
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

				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x - 95,GetPos().y - 100 });
				Actor->MoveDir = float4::Left;

			
				AnimationBodyRender->SetPosition({ body.x - 38, body.y - 10 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

			
			else if (StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK)
			{
				LeftSetBody({ 0,0 });
				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x,GetPos().y - 200 });
				Actor->MoveDir = float4::Up;
			
				AnimationBodyRender->SetPosition({ body.x + 10,body.y - 135 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			

			else if (StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK)
			{
				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x,GetPos().y - 250 });
				Actor->MoveDir = float4::Up;

				LeftSetBody({ 0,0 });
				
			
				AnimationBodyRender->SetPosition({ body.x + 20 ,body.y - 150 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}
			
			


			else if (StateValue == PlayerState::JUMPMOVEUPATTACK)
			{
				LeftSetBody({ 0,0 });
				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x - 95,GetPos().y - 100 });
				Actor->MoveDir = float4::Left;
			
				AnimationBodyRender->SetPosition({ body.x - 20  ,body.y - 25 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

			



			else if (StateValue == PlayerState::JUMPMOVEDOWNATTACK)
			{
				LeftSetBody({ 0,0 });
				Bullets* Actor = GetLevel()->CreateActor<Bullets>();
				Actor->SetPos({ GetPos().x - 95,GetPos().y - 100 });
				Actor->MoveDir = float4::Left;
			
				AnimationBodyRender->SetPosition({ body.x - 20  ,body.y - 25 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			


		
		}	

	
		if (StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK)
		{
			AnimationBodyRender->SetScale({ 400,400 });
			LeftSetBody({ 0,0 });
		

			AnimationBodyRender->SetPosition({ body.x - 50, body.y - 10 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
			DirStringBullet = "Left";
			LeftHeavyBulletCheck = true; 
		}


		else if (StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK)
		{
			AnimationBodyRender->SetScale({ 600,600 });
			LeftSetBody({ 0,0 });


			AnimationBodyRender->SetPosition({ body.x + 17,body.y - 35 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
			DirStringBullet = "Up";
			UpHeavyBulletCheck = true;
		}

		else if (StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK)
		{
			AnimationBodyRender->SetScale({ 600,600 });
			LeftSetBody({ 0,0 });


			AnimationBodyRender->SetPosition({ body.x + 35 ,body.y - 50 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
			DirStringBullet = "Up";
			UpHeavyBulletCheck = true;
		}

		else if (StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK)
		{
			AnimationBodyRender->SetScale({ 400,400 });
			LeftSetBody({ 0,0 });


			AnimationBodyRender->SetPosition({ body.x - 40  ,body.y - 38 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";

			DirStringBullet = "Left";
			LeftHeavyBulletCheck = true;

		}

		else if (StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK)
		{
			AnimationBodyRender->SetScale({ 400,400 });
			LeftSetBody({ 0,0 });


			AnimationBodyRender->SetPosition({ body.x - 40  ,body.y - 38 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";

			DirStringBullet = "Left";
			LeftHeavyBulletCheck = true;
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

					Bullets* Actor = GetLevel()->CreateActor<Bullets>();
					Actor->SetPos({ GetPos().x + 95,GetPos().y - 100 });
					Actor->MoveDir = float4::Right;

					AnimationBodyRender->SetPosition({ body.x + 38, body.y - 5 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					
					
				}
				else if (StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
				



					AnimationBodyRender->SetPosition({ body.x + 42, body.y - 20 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					DirStringBullet = "Right";
					RightHeavyBulletCheck = true;
				}
				else if (StateValue == PlayerState::UPJUMPATTACK || StateValue == PlayerState::UPJUMPDOWNATTACK)
				{
					RightSetBody({ 0,0 });

					Bullets* Actor = GetLevel()->CreateActor<Bullets>();
					Actor->SetPos({ GetPos().x ,GetPos().y - 200 });
					Actor->MoveDir = float4::Up;

				
					AnimationBodyRender->SetPosition({ body.x - 10,body.y - 135 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}
				else if (StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK)
				{

					AnimationBodyRender->SetScale({ 600,600 });

					RightSetBody({ 0,0 });
					//bullets[d]->Dir = Direction::Up;
					AnimationBodyRender->SetPosition({ body.x - 17,body.y-35  });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					DirStringBullet = "Up";
					UpHeavyBulletCheck = true;
				}


				else if (StateValue == PlayerState::UPJUMPMOVEATTACK || StateValue == PlayerState::UPJUMPMOVEDOWNATTACK)
				{
					RightSetBody({ 0,0 });
			
					Bullets* Actor = GetLevel()->CreateActor<Bullets>();
					Actor->SetPos({ GetPos().x ,GetPos().y - 250 });
					Actor->MoveDir = float4::Up;

					AnimationBodyRender->SetPosition({ body.x-20 ,body.y - 150 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}

				else if (StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 600,600 });
					RightSetBody({ 0,0 });
					
					AnimationBodyRender->SetPosition({ body.x - 30 ,body.y - 50 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					DirStringBullet = "Up";
					UpHeavyBulletCheck = true;
				}

				else if (StateValue == PlayerState::JUMPMOVEUPATTACK)
				{
					RightSetBody({ 0,0 });
			
					Bullets* Actor = GetLevel()->CreateActor<Bullets>();
					Actor->SetPos({ GetPos().x + 95 ,GetPos().y - 100 });
					Actor->MoveDir = float4::Right;


					AnimationBodyRender->SetPosition({ body.x + 30 ,body.y - 30 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					
				}


				else if (StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
					//bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 43 ,body.y - 38 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					DirStringBullet = "Right";
					RightHeavyBulletCheck = true;
				}



				else if (StateValue == PlayerState::JUMPMOVEDOWNATTACK)
				{
					RightSetBody({ 0,0 });
				
					Bullets* Actor = GetLevel()->CreateActor<Bullets>();
					Actor->SetPos({ GetPos().x + 95 ,GetPos().y - 100 });
					Actor->MoveDir = float4::Right;

					AnimationBodyRender->SetPosition({ body.x + 30 ,body.y -25 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";

				}

				else if (StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
					//bullets[d]->Dir = Direction::Right;
					AnimationBodyRender->SetPosition({ body.x + 43 ,body.y - 38 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
					DirStringBullet = "Right";
				}

			
			}


			
			/*	if (StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
				
					AnimationBodyRender->SetPosition({ body.x + 42, body.y - 20 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}

				else if (StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK)
				{

					AnimationBodyRender->SetScale({ 600,600 });

					RightSetBody({ 0,0 });
				
					AnimationBodyRender->SetPosition({ body.x - 17,body.y-35  });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}

				else if (StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK)
			    {
				    AnimationBodyRender->SetScale({ 600,600 });
				    RightSetBody({ 0,0 });
				  
				    AnimationBodyRender->SetPosition({ body.x - 30 ,body.y - 50 });
				    AnimationRegRender->SetPosition({ Reg });
				    DirString = "Right_";
			    }


				else if (StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
				
					AnimationBodyRender->SetPosition({ body.x + 43 ,body.y - 38 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";

				}



				else if (StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK)
				{
					AnimationBodyRender->SetScale({ 400,400 });
					RightSetBody({ 0,0 });
				
					AnimationBodyRender->SetPosition({ body.x + 43 ,body.y - 38 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}
*/

			




		
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
		StateValue == PlayerState::HEAVYJUMPUPATTACK || StateValue == PlayerState::HEAVYUPJUMPATTACK || StateValue == PlayerState::HEAVYUPJUMPDOWNATTACK ||
		StateValue == PlayerState::HEAVYJUMPMOVEUPATTACK || StateValue == PlayerState::HEAVYJUMPMOVEDOWNATTACK ||
		StateValue == PlayerState::HEAVYUPJUMPMOVEATTACK || StateValue == PlayerState::HEAVYUPJUMPMOVEDOWNATTACK || StateValue == PlayerState::HEAVYJUMPDOWNATTACK ||
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
	

	//std::string MouseText = "MousePosition : \n";
	//MouseText += GetLevel()->GetCameraPos().ToString();
	//GetLevel()->GetCameraPos().x > 6500

	std::string CameraMouseText = "MousePositionCamera : \n";
	CameraMouseText += GetLevel()->GetCameraPos().ToString();
	//CameraMouseText = SpinMoveDir.ToString();

	//CameraMouseText += GetLevel()

	//CameraMouseText = MoveDir
	//GameEngineLevel::DebugTextPush(MouseText);
	GameEngineLevel::DebugTextPush(CameraMouseText);
	/*HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

	


	std::string AngleText = "Angle : ";
	AngleText += std::to_string(Deg);
	GameEngineLevel::DebugTextPush(AngleText);

	std::string MouseText = "MousePosition : ";
	MouseText += GetLevel()->GetMousePos().ToString();

	std::string CameraMouseText = "MousePositionCamera : ";
	CameraMouseText += GetLevel()->GetMousePosToCamera().ToString();

	GameEngineLevel::DebugTextPush(MouseText);*/
	// GameEngineLevel::DebugTextPush(CameraMouseText);

	//std::string Text = "출력";
	//SetBkMode(DoubleDC, TRANSPARENT);
	//TextOut(DoubleDC, 0, 0, Text.c_str(), Text.size());

	// 디버깅용.
	//BodyCollision->DebugRender(); 
	/*LeftBulletCollision->DebugRender(); 
	RightBulletCollision->DebugRender();
	UpBulletCollision->DebugRender();*/
   
}