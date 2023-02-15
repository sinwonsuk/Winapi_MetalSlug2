#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineTime.h>



// State
void Player::ChangeState(PlayerState _State) 
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PlayerState::IDLE:
		IdleStart();
		break;
	case PlayerState::MOVE:
		MoveStart();
		break;
	case PlayerState::JUMPDOWN:
		JumpDownStart();
		break;
	case PlayerState::JUMPUP:
		JumpUpStart();
		break;
	case PlayerState::JUMPMOVEUP:
		JumpMoveUpStart();
		break;
	case PlayerState::JUMPMOVEDOWN:
		JumpMoveDownStart();
		break;
	case PlayerState::UP:
		UpStart(); 
		break;
	case PlayerState::UPMOVE:
		UpMoveStart();
		break;
	case PlayerState::DOWN:
		DownStart();
		break;
	case PlayerState::IDLEDOWN:
		DownIdleStart();
		break;
	case PlayerState::IDLEATTACK:
		AttackStart();
		break;
	case PlayerState::MOVEATTACK:
		AttackMoveStart(); 
		break;
	case PlayerState::JUMPUPATTACK:
		AttackJumpUpStart();
		break;
	case PlayerState::JUMPDOWNATTACK:
		AttackJumpDownStart();
		break;
	case PlayerState::JUMPMOVEDOWNATTACK:
		AttackJumpMoveDownStart();
		break;
	case PlayerState::JUMPMOVEUPATTACK:
		AttackJumpMoveUpStart();
		break;
	case PlayerState::UPATTACK:
		UpAttackStart(); 
		break;
	case PlayerState::UPMOVEATTACK:
		UpMoveAttackStart();
		break;
	case PlayerState::UPJUMPATTACK:
		UpJumpAttackStart(); 
		break;
	case PlayerState::UPJUMPDOWNATTACK:
		UpJumpDownAttackStart(); 
		break;
	case PlayerState::UPJUMPMOVEATTACK:
		UpJumpMoveAttackStart();
		break;
	case PlayerState::UPJUMPMOVEDOWNATTACK:
		UpJumpMoveDownAttackStart();
		break;
	case PlayerState::THROW:
		ThrowStart();
		break;
	case PlayerState::THROWMOVE:
		ThrowMoveStart();
		break;
	case PlayerState::HEAVYIDLE:
		HeavyIdleStart();
		break;
	case PlayerState::HEAVYMOVE:
		HeavyMoveStart();
		break;
	case PlayerState::HEAVYUP:
		HeavyUpStart();
		break;
	case PlayerState::HEAVYUPMOVE:
		HeavyUpMoveStart();
		break;
	case PlayerState::HEAVYJUMPUP:
		HeavyJumpUpStart();
		break;
	case PlayerState::HEAVYJUMPDOWN:
		HeavyJumpDownStart();
		break;
	case PlayerState::HEAVYJUMPMOVEUP:
		HeavyJumpMoveUpStart();
		break;
	case PlayerState::HEAVYJUMPMOVEDOWN:
		HeavyJumpMoveDownStart();
		break;
	case PlayerState::HEAVYUPJUMPUPMOVE:
		HeavyUpJumpUpMoveStart();
	
		break;
	case PlayerState::HEAVYUPJUMPDOWNMOVE:
		HeavyUpJumpDownMoveStart();
		break;
	case PlayerState::HEAVYIDLEATTACK:
		HeavyAttackStart();
		break;
	case PlayerState::HEAVYMOVEATTACK:
		HeavyAttackMoveStart();	
		break;
	case PlayerState::HEAVYUPATTACK:
		HeavyUpAttackStart();
		break;
	case PlayerState::HEAVYUPMOVEATTACK:
		HeavyAttackMoveStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case PlayerState::IDLE:
		IdleEnd();
		break;
	case PlayerState::MOVE:
		MoveEnd();
		break;
	default:
		break;
	}

}

void Player::UpdateState(float _Time)
{
	
		switch (StateValue)
		{
		case PlayerState::IDLE:
			IdleUpdate(_Time);
			break;
		case PlayerState::MOVE:
			MoveUpdate(_Time);
			break;
		case PlayerState::JUMPUP:
			JumpUpdate(_Time);
			break;
		case PlayerState::JUMPDOWN:
			JumpUpdate(_Time);
			break;
		case PlayerState::JUMPMOVEUP:
			JumpMoveUpdate(_Time);
			break;
		case PlayerState::JUMPMOVEDOWN:
			JumpMoveUpdate(_Time);
			break;
		case PlayerState::UP:
			UpUpdate(_Time);
			break;
		case PlayerState::UPMOVE:
			UpMoveUpdate(_Time);
			break;
		case PlayerState::DOWN:
			JumpUpdate(_Time);
			break;
		case PlayerState::IDLEDOWN:
			JumpUpdate(_Time);
			break;
		case PlayerState::IDLEATTACK:
			AttackIdleUpdate(_Time);
			break;
		case PlayerState::MOVEATTACK:
			AttackMoveUpdate(_Time);
			break;
		case PlayerState::JUMPUPATTACK:
			AttackJumpUpdate(_Time);
			break;
		case PlayerState::JUMPDOWNATTACK:
			AttackJumpUpdate(_Time);
			break;
		case PlayerState::JUMPMOVEUPATTACK:
			AttackJumpMoveUpdate(_Time);
			break;
		case PlayerState::JUMPMOVEDOWNATTACK:
			AttackJumpMoveUpdate(_Time);
			break;		
		case PlayerState::UPATTACK:
			UpUpdate(_Time);
			break;
		case PlayerState::UPMOVEATTACK:
			UpMoveUpdate(_Time);
			break;
		case PlayerState::UPJUMPATTACK:
			AttackJumpUpdate(_Time);
			break;
		case PlayerState::UPJUMPDOWNATTACK:
			AttackJumpUpdate(_Time);
			break;
		case PlayerState::UPJUMPMOVEATTACK:
			UpAttackJumpMoveUpdate(_Time);	
			break;
		case PlayerState::UPJUMPMOVEDOWNATTACK:
			UpAttackJumpMoveUpdate(_Time);
			break;
		case PlayerState::THROW:
			ThrowUpdate(_Time);
			break;
		case PlayerState::THROWMOVE:
			ThrowMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYIDLE:
			HeavyIdleUpdate(_Time);
			break;
		case PlayerState::HEAVYMOVE:
			HeavyMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYUP:
			HeavyUpUpdate(_Time);
			break;
		case PlayerState::HEAVYUPMOVE:
			HeavyUpMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYJUMPUP:
			HeavyJumpUpdate(_Time);
			break;
		case PlayerState::HEAVYJUMPDOWN:
			HeavyJumpUpdate(_Time);
			break;
		case PlayerState::HEAVYJUMPMOVEUP:
			HeavyJumpMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYJUMPMOVEDOWN:
			HeavyJumpMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYUPJUMPUPMOVE:
			HeavyJumpMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYUPJUMPDOWNMOVE:
			HeavyJumpMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYIDLEATTACK:
			HeavyAttackIdleUpdate(_Time);
			break;
		case PlayerState::HEAVYMOVEATTACK:
			HeavyAttackMoveUpdate(_Time);
			break;
		case PlayerState::HEAVYUPATTACK:
			HeavyUpUpdate(_Time);
			break;
		case PlayerState::HEAVYUPMOVEATTACK:
			HeavyAttackMoveUpdate(_Time);
			break;
		default:
			break;
		}
		

	
}


// FSM 내가 어떤일을 할때 이동하면서 가만히 있을수 없다.
void Player::IdleStart() 
{
	DirCheck("Idle","Idle" );
}


void Player::MoveStart() 
{	
	DirCheck("Move" ,"Move" );
}


void Player::UpStart()
{
	DirCheck("Up", "Idle");
}

void Player::UpMoveStart()
{
	DirCheck("Up", "Move");
}

void Player::UpAttackStart()
{
	DirCheck("Up_Attack", "Idle");
}

void Player::UpMoveAttackStart()
{
	DirCheck("Up_Attack", "Move");
}

void Player::UpJumpAttackStart()
{
	JumpDirCheck("Up_Attack", "Idle_Up_Jump");
}

void Player::UpJumpDownAttackStart()
{
	JumpDirCheck("Up_Attack", "Idle_Down_Jump");
}

void Player::UpJumpMoveAttackStart()
{
	JumpDirCheck("Up_Attack", "Move_UP_Jump_Reg");
}
void Player::UpJumpMoveDownAttackStart()
{
	JumpDirCheck("Up_Attack", "Move_Down_Jump_Reg");
}


void Player::JumpUpStart()
{
	JumpDirCheck("Idle_Jump" , "Idle_Up_Jump");
}
void Player::JumpDownStart()
{
	JumpDirCheck("Idle_Jump", "Idle_Down_Jump");
}

void Player::JumpMoveUpStart()
{
	JumpDirCheck("Move_Up_Jump_Body", "Move_UP_Jump_Reg");
}

void Player::JumpMoveDownStart()
{
	JumpDirCheck("Move_Down_Jump_Body", "Move_Down_Jump_Reg");
}
void Player::DownStart()
{
	JumpDirCheck("Down", "Move_Down_Jump_Reg");
}

void Player::DownIdleStart()
{
	JumpDirCheck("Down", "Idle_Down_Jump");
}

void Player::AttackStart()
{
	DirCheck("Attack", "Idle");
}

void Player::AttackMoveStart()
{
	DirCheck("Attack", "Move");
}

void Player::AttackJumpUpStart()
{
	JumpDirCheck("Attack", "Idle_Up_Jump");
}

void Player::AttackJumpDownStart()
{
	JumpDirCheck("Attack", "Idle_Down_Jump");
}

void Player::AttackJumpMoveUpStart()
{
	JumpDirCheck("Attack", "Move_UP_Jump_Reg");
}

void Player::AttackJumpMoveDownStart()
{
	JumpDirCheck("Attack", "Move_Down_Jump_Reg");
}

void Player::ThrowStart()
{
	DirCheck("Throw", "Idle");
}

void Player::ThrowMoveStart()
{
	DirCheck("Throw", "Move");
}
void Player::HeavyIdleStart()
{
	DirCheck("HeavyGunIdle", "Idle");
}

void Player::HeavyMoveStart()
{
	DirCheck("HeaveGunMove", "Move");
}
void Player::HeavyUpStart()
{
	DirCheck("HeaveGunUp", "Idle");
}

void Player::HeavyUpMoveStart()
{
    DirCheck("HeaveGunUp", "Move");
}
void Player::HeavyJumpUpStart()
{
	JumpDirCheck("HeaveGunIdleUpJump", "Idle_Up_Jump");
}
void Player::HeavyJumpDownStart()
{
	JumpDirCheck("HeaveGunIdleDownJump", "Idle_Down_Jump");
}

void Player::HeavyJumpMoveUpStart()
{
	JumpDirCheck("HeaveGunMoveUpJump", "Move_UP_Jump_Reg");
}

void Player::HeavyJumpMoveDownStart()
{
	JumpDirCheck("HeaveGunMoveDownJump", "Move_Down_Jump_Reg");
}

void Player::HeavyUpJumpUpMoveStart()
{
	JumpDirCheck("HeaveGunUp", "Move_UP_Jump_Reg");
}
void Player::HeavyUpJumpDownMoveStart()
{
	JumpDirCheck("HeavyGunIdleAttack", "Move_Down_Jump_Reg");
}
void Player::HeavyAttackStart()
{
	DirCheck("HeavyGunIdleAttack", "Idle");
}

void Player::HeavyAttackMoveStart()
{
	DirCheck("HeavyGunIdleAttack", "Move");
}

void Player::HeavyUpAttackStart()
{
	DirCheck("HeaveGunUpAttack", "Idle");
}

void Player::HeavyUpMoveAttackStart()
{
	DirCheck("HeaveGunUp", "Move");
}


void Player::IdleUpdate(float _Time)
{

	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}

	else if (GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::UP);
		return;
	}

	else if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::UPMOVE);
		return;
	}
	else if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::IDLEATTACK);
		return;
	}
	else if (true == GameEngineInput::IsDown("JumpMove"))
	{
		ChangeState(PlayerState::JUMPUP);
		MoveDir += float4::Up * 650;
		test = true;
	}
	else if (true == GameEngineInput::IsPress("Throw"))
	{


		ChangeState(PlayerState::THROW);
		return;
	}

}
void Player::IdleEnd() {

}
void Player::HeavyIdleUpdate(float _Time)
{

	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::HEAVYMOVE);
		return;
	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::HEAVYUP);
		return;
	}
	else if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::HEAVYIDLEATTACK);
		return;
	}

	else if (true == GameEngineInput::IsDown("JumpMove"))
	{
		ChangeState(PlayerState::HEAVYJUMPUP);
		MoveDir += float4::Up * 650;
		test = true;
	}

}


void Player::AttackIdleUpdate(float _Time)
{
	CameraDir = { 0,0 };


	if (AnimationBodyRender->IsAnimationEnd() == true)
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
	{	
		ChangeState(PlayerState::UPATTACK);
		return;
	}

	if (true == GameEngineInput::IsDown("Attack"))
	{	
		ChangeState(PlayerState::IDLEATTACK);
		return;
	}


	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		ChangeState(PlayerState::MOVE);
		MoveDir += float4::Left * MoveSpeed;
	}
	else if (true == GameEngineInput::IsDown("JumpMove"))
	{
		ChangeState(PlayerState::JUMPUP);
		MoveDir += float4::Up * 650;
		test = true;
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::MOVE);
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}
}

void Player::HeavyAttackIdleUpdate(float _Time)
{
	CameraDir = { 0,0 };


	if (AnimationBodyRender->IsAnimationEnd() == true)
	{
		ChangeState(PlayerState::HEAVYIDLE);
		return;
	}


	if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::HEAVYIDLEATTACK);
		return;
	}

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		ChangeState(PlayerState::HEAVYMOVE);
		MoveDir += float4::Left * MoveSpeed;
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::HEAVYMOVE);
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}
}



void Player::ThrowUpdate(float _Time)
{
	if (AnimationBodyRender->IsAnimationEnd() == true)
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (true == GameEngineInput::IsDown("Throw"))
	{
		ChangeState(PlayerState::THROW);
		return;
	}
}


void Player::ThrowMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (AnimationBodyRender->IsAnimationEnd() == true)
	{
		ChangeState(PlayerState::MOVE);
		return;
	}

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}
	if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}


	if (true == GameEngineInput::IsDown("Throw"))
	{
		ChangeState(PlayerState::THROWMOVE);
		return;
	}



	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

}


void Player::AttackMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };
	if (AnimationBodyRender->IsAnimationEnd() == true)
	{
		ChangeState(PlayerState::MOVE);
		return;
	}

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}
	if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}


	if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::MOVEATTACK);
		return;
	}
	if (true == GameEngineInput::IsDown("JUMPMOVE"))
	{
		ChangeState(PlayerState::JUMPMOVEUP);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}
	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}
	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}
	
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}
	
}
void Player::HeavyAttackMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };
	if (AnimationBodyRender->IsAnimationEnd() == true)
	{
		ChangeState(PlayerState::HEAVYMOVE);
		return;
	}

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::HEAVYIDLE);
		return;
	}
	if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::HEAVYIDLE);
		return;
	}
	if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::HEAVYMOVEATTACK);
		return;
	}


	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

}




void Player::AttackJumpUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (MoveDir.y < 0)
	{
		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPATTACK);
			return;
		}

		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPUPATTACK);
			return;
		}
	}
	if (MoveDir.y > 0)
	{
		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPDOWNATTACK);
			return;
		}

		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPDOWNATTACK);
			return;
		}
	}

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}


}

void Player::AttackJumpMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	
	if (MoveDir.y < 300)
	{
	

		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEUPATTACK);
			return;
		}
	}
	if (MoveDir.y > 300)
	{
		
		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEDOWNATTACK);
			return;
		}
	}
	/*if (MoveDir.y > 300)
	{
		ChangeState(PlayerState::JUMPMOVEDOWN);
		return;
	}*/
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}
}


void Player::UpUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsUp("UpMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}
	if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::UPATTACK);
		return;
	}
	if (true == GameEngineInput::IsDown("JumpMove"))
	{
		ChangeState(PlayerState::JUMPUP);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}

	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}


	else if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::UPMOVE);
		return;
	}

	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}
	else if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::UPMOVE);
		return;
	}

}

void Player::HeavyUpUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsUp("UpMove"))
	{
		ChangeState(PlayerState::HEAVYIDLE);
		return;
	}
	else if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::HEAVYUPATTACK);
		return;
	}
	if (true == AnimationBodyRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::HEAVYUP);
		return;
	}


	else if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::HEAVYUPMOVE);
		return;
	}
	else if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::HEAVYUPMOVE);
		return;

	}

}



void Player::UpMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::UP);
		return;
	}
	if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::UP);
		return;
	}

	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("JumpMove"))
	{
		ChangeState(PlayerState::JUMPMOVEUP);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}
	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("JumpMove"))
	{
		ChangeState(PlayerState::JUMPMOVEUP);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}


	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}
	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}


	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir += float4::Left * MoveSpeed;		
	}
	
	else if (true == GameEngineInput::IsPress("LeftMove"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}

	
	

	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}



	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}

}
void Player::HeavyUpMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::HEAVYUP);
		return;
	}
	if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::HEAVYUP);
		return;
	}

	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("JumpMove"))
	{
		ChangeState(PlayerState::HEAVYUPJUMPUPMOVE);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}
	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("JumpMove"))
	{
		ChangeState(PlayerState::HEAVYUPJUMPUPMOVE);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}



	if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	else if (true == GameEngineInput::IsPress("LeftMove"))
	{
		ChangeState(PlayerState::HEAVYMOVE);
		return;
	}

	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::HEAVYMOVE);
		return;
	}

	

}


void Player::UpMoveAttackUpdate(float _Time)
{
	//if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
	//{
	//	ChangeState(PlayerState::UPMOVEATTACK);
	//	return;
	//}
	//if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
	//{
	//	ChangeState(PlayerState::UPMOVEATTACK);
	//	return;
	//}
	if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::UPMOVEATTACK);
		return;
	}
	
	 if  (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::UPMOVE);
		return;
	}



	if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::UPMOVE);	
		return;
	}





}

void Player::UpAttackJumpMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

	if (MoveDir.y < 300)
	{
		/*if (true == GameEngineInput::IsPress("RightMove") || true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEUPATTACK);
			return; 
		}*/


		 if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPMOVEATTACK);
			return;
		}
	}
	if (MoveDir.y > 300)
	{
		/*if (true == GameEngineInput::IsPress("LeftMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEDOWNATTACK);
			return;
		}*/

		 if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPMOVEDOWNATTACK);
			return;
		}
	}
	
	


	
}



void Player::JumpMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

	if (MoveDir.y < 300)
	{
		

		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPMOVEATTACK);
			return;
		}

		
		else if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEUPATTACK);
			return;
		}
	}
	if (MoveDir.y > 300)
	{
		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPMOVEDOWNATTACK);
			return;
		}
		

		else if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPMOVEDOWNATTACK);
			return;
		}
	}
	if (true == GameEngineInput::IsDown("DownMove"))
	{
		ChangeState(PlayerState::DOWN);
		return;
	}


	if (MoveDir.y > 300)
	{
		ChangeState(PlayerState::JUMPMOVEDOWN);
		return;
	}




	
}

void Player::HeavyJumpMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}





	if (MoveDir.y > 300)
	{
		ChangeState(PlayerState::HEAVYJUMPMOVEDOWN);
		return;
	}

}





void Player::JumpUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}
	if (true == GameEngineInput::IsPress("DownMove"))
	{
		ChangeState(PlayerState::IDLEDOWN);
		return;
	}

	if (MoveDir.y < 0)
	{
		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPATTACK);
			return;
		}

		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPUPATTACK);
			return;
		}
	}
	if (MoveDir.y > 0)
	{
		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::UPJUMPDOWNATTACK);
			return;
		}

		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPDOWNATTACK);
			return;
		}
	}

	
	if (MoveDir.y > 0)
	{
		if (true == GameEngineInput::IsDown("Attack"))
		{
			ChangeState(PlayerState::JUMPDOWNATTACK);
			return;
		}
	}

	

	if (MoveDir.y > 0)
	{
		ChangeState(PlayerState::JUMPDOWN);
		return; 
	}
	
}

void Player::HeavyJumpUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

	if (MoveDir.y > 0)
	{
		ChangeState(PlayerState::HEAVYJUMPDOWN);
		return;
	}

}



void Player::MoveUpdate(float _Time) 
{
	CameraDir = { 0,0 };

	
	

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}
	else if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	else if (true == GameEngineInput::IsPress("Throw"))
	{
		ChangeState(PlayerState::THROWMOVE);
		return;
	}
	else if (true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::UP);
		return;
	}
	
	else if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::MOVEATTACK);
		return;
	}



	else if (true == GameEngineInput::IsDown("JumpMove"))
	{
		ChangeState(PlayerState::JUMPMOVEUP);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}
	
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;	  	
	}		
}

void Player::HeavyMoveUpdate(float _Time)
{
	CameraDir = { 0,0 };

	if (true == GameEngineInput::IsDown("LeftMove") || true == GameEngineInput::IsDown("RightMove"))
	{
		ChangeState(PlayerState::HEAVYIDLE);
		return;
	}
	else if (true == GameEngineInput::IsUp("LeftMove") || true == GameEngineInput::IsUp("RightMove"))
	{
		ChangeState(PlayerState::HEAVYIDLE);
		return;
	}


	else if (true == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::HEAVYUP);
		return;
	}

	else if (true == GameEngineInput::IsDown("JumpMove"))
	{
		ChangeState(PlayerState::HEAVYJUMPMOVEUP);
		MoveDir += float4::Up * 650;
		test = true;
		return;
	}
	else if (true == GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::HEAVYMOVEATTACK);
		return;
	}


	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
		CameraDir = float4::Right * MoveSpeed * _Time;
	}

}








void Player::MoveEnd() {


}

