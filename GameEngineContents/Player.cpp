#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
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
	
	
	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
		GameEngineInput::CreateKey("Freemove", '1');
		GameEngineInput::CreateKey("Jumpmove", 'J');
		GameEngineInput::CreateKey("Attack", 'K');
	}

	{
		//body
		RightSetBody({ 0,0 });
		AnimationBodyRender = CreateRender(3);
		AnimationBodyRender->SetScale({ 200,200 });
		AnimationBodyRender->SetPosition({body });

		// Idle Body
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdlePlayer.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "LeftIdlePlayer.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });

		// Move Body
		
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "RightBodyMove.bmp", .Start = 0, .End = 11, .InterTime = 0.05f });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "LeftBodyMove.bmp", .Start = 0, .End = 11, .InterTime = 0.05f });
		
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
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Right_Up_Attack",  .ImageName = "RightUpAttack.bmp", .Start = 0, .End = 9, .InterTime = 0.1f , .Loop = false });
		AnimationBodyRender->CreateAnimation({ .AnimationName = "Left_Up_Attack",  .ImageName = "LeftUpAttack.bmp", .Start = 0, .End = 9, .InterTime = 1.0f , .Loop = false });
	}


	{
		//reg
		AnimationRegRender = CreateRender(2);
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

}

//void Player::Update(float _DeltaTime) 
//{
//	UpdateState(_DeltaTime);
//}

void Player::Movecalculation(float _DeltaTime)
{
	
	 
		//MoveDir = float4::Down * 300.0f * _DeltaTime;


	if (a == true)
	{		
		MoveDir += float4::Down * 1500.0f * _DeltaTime;
	}
	if (a == false)
	{
		MoveDir += float4::Down * 4000.0f * _DeltaTime;
	}

	
	

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
	
	
	

	if (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255,0)))
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
	//float4 ab = MoveDir * _DeltaTime;

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


	// 일단 되긴하는데 시간 남아돌면 바꾸기 
	
	// jump
	if (StateValue == PlayerState::IDLE)
	{
		if (true == GameEngineInput::IsDown("JumpMove"))
		{
			ChangeState(PlayerState::JUMPUP);
			MoveDir += float4::Up * 650;
			test = true;
		}
	
	}
	if (true == GameEngineInput::IsPress("RightMove") || true == GameEngineInput::IsPress("LeftMove"))
	{
		if (true == GameEngineInput::IsDown("JumpMove"))
		{
			ChangeState(PlayerState::JUMPMOVEUP);

			MoveDir += float4::Up * 650;
			test = true;
		}
	}
	
	if (StateValue == PlayerState::JUMPMOVEUP )
	{
		if (true == GameEngineInput::IsDown("DownMove"))
		{
			ChangeState(PlayerState::DOWN);
		}
	}
	
	if (StateValue == PlayerState::JUMPUP)
	{
		if (true == GameEngineInput::IsDown("DownMove"))
		{
			ChangeState(PlayerState::IDLEDOWN);
		}
	}
	
	if (StateValue == PlayerState::JUMPMOVEUP)
	{
		if (MoveDir.y > 300)
		{
			ChangeState(PlayerState::JUMPMOVEDOWN);
		}
	}

	if (StateValue == PlayerState::JUMPUP)
	{
		if (MoveDir.y > 0)
		{
			ChangeState(PlayerState::JUMPDOWN);
		}
	}
	// attack

	if (StateValue == PlayerState::IDLEATTACK)

	{
		if (true == GameEngineInput::IsDown("Attack"))
		{
			TimeCheck = 0;
			ChangeState(PlayerState::IDLE);
		}
		


	}
	if (StateValue == PlayerState::JUMPUPATTACK )
	{
		if (true == GameEngineInput::IsDown("Attack"))
		{	
			ChangeState(PlayerState::JUMPUP);
		}
		

	}
	if ( StateValue == PlayerState::JUMPDOWNATTACK)
	{
	
		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPDOWN);
		}

	}
	if (StateValue == PlayerState::JUMPMOVEUPATTACK)
	{
		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEUP);
		}
	}

	if ( StateValue == PlayerState::JUMPMOVEDOWNATTACK)
	{
		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEDOWN);
		}
	}
	if (StateValue == PlayerState::UPATTACK)
	{
		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UP);
		}
	}


	if (CameraCheck == true && PosCheck.x < GetPos().ix())
	{
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

	//UpdateState(_DeltaTime);
	Movecalculation(_DeltaTime);
	UpdateState(_DeltaTime);
	//UpdateState(_DeltaTime);
	
	
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
void Player::DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{
	std::string PrevDirString = DirString;

	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());

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


	if (StateValue == PlayerState::UP)
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
	if (StateValue == PlayerState::UPATTACK)
	{
		if (DirString == "Left_")
		{
			LeftSetBody({ 0,0 });

			AnimationBodyRender->SetPosition({ body.x+10,body.y-120 });
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Left_";
		}
		if (DirString == "Right_")
		{
			RightSetBody({ 0,0 });
			AnimationBodyRender->SetPosition({ body.x-10,body.y -120});
			AnimationRegRender->SetPosition({ Reg });
			DirString = "Right_";
		}
	}
	if (GameEngineInput::IsPress("Attack"))
	{
	    
	    if (StateValue == PlayerState::IDLEATTACK || StateValue == PlayerState::MOVEATTACK)
	    {
	    	if (DirString == "Left_")
	    	{
	    		LeftSetBody({ 0,0 });

	    		AnimationBodyRender->SetPosition({ body.x - 38 , body.y + 7 });
	    		AnimationRegRender->SetPosition({ Reg });
	    		DirString = "Left_";
	    	}
	    	else if (DirString == "Right_")
	    	{
	    		RightSetBody({ 0,0 });
	    
	    		AnimationBodyRender->SetPosition({ body.x + 40, body.y + 7 });
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

}
// 1 body 2 reg 
void Player::JumpDirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{

	std::string PrevDirString = DirString;

	AnimationBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	AnimationRegRender->ChangeAnimation(DirString + _AnimationName1.data());


	if (DirString == "Left_")
	{
		if (GameEngineInput::IsPress("JumpMove"))
		{
			if (StateValue == PlayerState::JUMPUP || StateValue == PlayerState::JUMPDOWN)
			{
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x + 15,body.y - 22 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}

			else if (StateValue == PlayerState::JUMPMOVEUP )
			{
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x  ,body.y - 32 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}
			
		}

		if (GameEngineInput::IsPress("Attack"))
		{
			if (StateValue == PlayerState::JUMPUPATTACK)
			{
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x - 38, body.y - 10 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";
			}


			else if (StateValue == PlayerState::JUMPMOVEUPATTACK)
			{
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x - 20  ,body.y - 25 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

			else if (StateValue == PlayerState::JUMPMOVEDOWNATTACK)
			{
				LeftSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x-20  ,body.y - 25 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Left_";

			}

		}
	}
	if (DirString == "Right_")
	{
		if (GameEngineInput::IsDown("JumpMove"))
		{
			if (StateValue == PlayerState::JUMPUP || StateValue == PlayerState::JUMPDOWN)
			{
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x - 15,body.y - 22 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
			}

			else if (StateValue == PlayerState::JUMPMOVEUP)
			{
				RightSetBody({ 0,0 });
				AnimationBodyRender->SetPosition({ body.x-25 ,body.y -32 });
				AnimationRegRender->SetPosition({ Reg });
				DirString = "Right_";
			}

			
		}


		

			if (GameEngineInput::IsPress("Attack"))
			{
				if (StateValue == PlayerState::JUMPUPATTACK || StateValue == PlayerState::JUMPDOWNATTACK)
				{
					RightSetBody({ 0,0 });
					AnimationBodyRender->SetPosition({ body.x + 38, body.y - 5 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";
				}
				else if (StateValue == PlayerState::JUMPMOVEUPATTACK)
				{
					RightSetBody({ 0,0 });
					AnimationBodyRender->SetPosition({ body.x + 30 ,body.y - 30 });
					AnimationRegRender->SetPosition({ Reg });
					DirString = "Right_";

				}
				else if (StateValue == PlayerState::JUMPMOVEDOWNATTACK)
				{
					RightSetBody({ 0,0 });
					AnimationBodyRender->SetPosition({ body.x + 30 ,body.y -25 });
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

}

void Player::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC, 
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
		);

	
}