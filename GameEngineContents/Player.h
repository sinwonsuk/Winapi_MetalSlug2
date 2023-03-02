#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Bullets.h"
#include "Bomb.h"
#include "HeavyGun.h"
#include "MiddleBoss.h"
enum class PlayerState
{
	IDLE,
	MOVE,
	JUMPDOWN,
	JUMPUP,
	JUMPMOVEDOWN,
	JUMPMOVEUP,
	UP,
	UPMOVE,
	UPJUMPMOVE,
	DOWN,
	IDLEDOWN,
	IDLEATTACK,
	MOVEATTACK,
	JUMPUPATTACK,
	JUMPDOWNATTACK,
	JUMPMOVEDOWNATTACK,
	JUMPMOVEUPATTACK,
	UPRIGHTATTACK,
	UPATTACK,
	UPMOVEATTACK,
	UPJUMPATTACK,
	UPJUMPDOWNATTACK,
	UPJUMPMOVEATTACK,
	UPJUMPMOVEDOWNATTACK,
	THROW,
	THROWMOVE,
	HEAVYIDLE,
	HEAVYMOVE,
	HEAVYUP,
	HEAVYUPMOVE,
	HEAVYJUMPUP,
	HEAVYJUMPDOWN,
	HEAVYJUMPMOVEUP,
	HEAVYJUMPMOVEDOWN,
	HEAVYUPJUMPUPMOVE,
	HEAVYUPJUMPDOWNMOVE,
	HEAVYIDLEATTACK,
	HEAVYMOVEATTACK,
	HEAVYUPATTACK,
	HEAVYUPMOVEATTACK,
	HEAVYJUMPUPATTACK,
	HEAVYJUMPDOWNATTACK,
	HEAVYUPJUMPATTACK,
	HEAVYUPJUMPDOWNATTACK,
	HEAVYJUMPMOVEDOWNATTACK,
	HEAVYJUMPMOVEUPATTACK,
	HEAVYUPJUMPMOVEATTACK,
	HEAVYUPJUMPMOVEDOWNATTACK,
	HEAVYIDLECHANGEUPATTACK,
	HEAVYUPCHANGEIDLEATTACK,

	HEAVYMOVECHANGEUPATTACK,
	HEAVYUPCHANGEMOVEATTACK,
	HEAVYTHROW,
	HEAVYTHROWMOVE
};

// Ό³Έν :
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;
	void RightSetBody(float4 reg)
	{
		this->body.x = reg.x + 11;
		this->body.y = reg.y - 35;
		
	}
	void LeftSetBody(float4 reg)
	{
		this->body.x = reg.x - 11;
		this->body.y = reg.y - 35;
	}
	float GetMonsterBulletRange()
	{
		return MonsterBulletRange;
	}
	


	float GetBombNumber()
	{
		return BombNumber;
	}
	float GetHeavyMachineGun()
	{
		return HeavyMachineGun;
	}

	float4 GetCameraDir()
	{
		return CameraDir; 
	}
	bool SetCameraCheck(const bool& Check)
	{		
		return CameraCheck = Check;
	}
	bool GetRebelStart()
	{
		return RebelStart;
	}
	bool GroundCheck = false;

	float4 MoveDir = float4::Zero;
	float4 SetPosCheck(const float4& Pos)
	{
		return PosCheck = Pos;
	}
	float4 GetCameraMoveCheck()
	{
		return CameraMoveCheck;
	}
	bool GetGunChange()
	{
		return GunChange;
	}

	float BombNumber = 10;
	float HeavyMachineGun = 0;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:

	

	bool Gravity = false;
	bool test = false;
	float4 CamelCheck = float4::Zero;
	float4 CamelDeath = float4::Zero;
	bool CameraCheck = false;
	PlayerState StateValue = PlayerState::IDLE;
	int MonsterCheck = 0;
	int StartFrame = 0;

	float AccTime = 0.0f;
	float MoveSpeed = 300.0f;
	float JumpSpeed = 800.0f;
	float MonsterBulletRange = 0;
	float TimeCheck = 0;
	

	std::string DirString = "Right_";
	std::string DirStringBullet = "Right";
	std::string CurDirStringBullet = ""; 

	//std::vector<GameEngineActor*> Bullet;
	//std::vector<Bullets*> bullets;
	
	
	float4 CurPos = float4::Zero;
	float4 CameraMoveCheck = float4::Zero;

	float4 SpinMoveDir = float4::Zero;
	float4 CameraDir = float4::Zero;
	float4 body = { 0,0 };
	float4 Reg = { 0,0 };
	float4 gravity = float4::Zero;
	float4 PosCheck = { 0,0 };


	bool GunChange = false;
	bool SpinDown = false;

	GameEngineRender* AnimationBodyRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;

	GameEngineRender* parachuteRender = nullptr;

	GameEngineCollision* BodyCollision = nullptr;
	GameEngineCollision* LeftBulletCollision = nullptr;
	GameEngineCollision* RightBulletCollision = nullptr;
	GameEngineCollision* UpBulletCollision = nullptr;




	//Carriage* carriage = nullptr;

	void DirCheck(const std::string_view& _AnimationName);
	void DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);
	void JumpDirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);
	
	// State
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);
	void Movecalculation(float _DeltaTime);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void CollisionCheck(float _DeltaTime);

	void UpStart();
	void UpMoveStart();
	void UpAttackStart(); 
	void UpMoveAttackStart();
	void UpJumpAttackStart();
	void UpJumpDownAttackStart(); 
	void UpJumpMoveAttackStart();
	void UpJumpMoveDownAttackStart(); 

	void UpUpdate(float _Time);
	void UpMoveUpdate(float _Time);
	void UpAttackJumpMoveUpdate(float _Time);
	
	
	void JumpUpStart();
	void JumpDownStart();
	void JumpMoveUpStart(); 
	void JumpMoveDownStart();

	void JumpUpdate(float _Time);
	void JumpMoveUpdate(float _Time);
	

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void DownStart();
	void DownIdleStart(); 

	void AttackStart(); 
	void AttackMoveStart(); 
	void AttackJumpUpStart();
	void AttackJumpDownStart();
	void AttackJumpMoveUpStart();
	void AttackJumpMoveDownStart();
	

	void AttackIdleUpdate(float _Time);
	void AttackMoveUpdate(float _Time);
	void AttackJumpUpdate(float _Time);
	void AttackJumpMoveUpdate(float _Time);
	 
	void ThrowStart();
	void ThrowMoveStart();

	void ThrowUpdate(float _Time);
	void ThrowMoveUpdate(float _Time);

	void HeavyIdleStart();
	void HeavyIdleUpdate(float _Time);

	void HeavyMoveStart();
	void HeavyMoveUpdate(float _Time);

	void HeavyUpStart();
	void HeavyUpMoveStart();

	void HeavyUpUpdate(float _Time);
	void HeavyUpMoveUpdate(float _Time);

	void HeavyJumpUpStart();
	void HeavyJumpDownStart();
	void HeavyJumpMoveUpStart();
	void HeavyJumpMoveDownStart();



	void HeavyUpJumpUpMoveStart(); 
	void HeavyUpJumpDownMoveStart();

	void HeavyJumpUpdate(float _Time);
	void HeavyJumpMoveUpdate(float _Time);

	void HeavyAttackStart();
	void HeavyAttackMoveStart();
	void HeavyUpAttackStart();
	void HeavyUpMoveAttackStart();
	void HeavyUpJumpAttackStart();
	void HeavyUpJumpDownAttackStart();

	void HeavyAttackJumpUpStart();
	void HeavyAttackJumpDownStart();
	void HeavyAttackJumpMoveUpStart();
	void HeavyAttackJumpMoveDownStart();

	void HeavyUpJumpMoveAttackStart();
	void HeavyUpJumpMoveDownAttackStart();

	void HeavIdleChangeUpStart(); 
	void HeavUpChangeIdleStart();

	void HeavyMoveChangeUpStart(); 
	void HeavyUpChangeUpMoveStart();

	void HeavyIdleChangeUpUpdate(float _Time);
	void HeavUpChangeIdleUpdate(float _Time);

	void HeavyUpAttackUpdate(float _Time);

	void HeavyUpAttackJumpMoveUpdate(float _Time);
	void HeavyAttackJumpUpdate(float _Time);
	void HeavyAttackIdleUpdate(float _Time);
	void HeavyAttackMoveUpdate(float _Time);

	void HeavyMoveChangeUpUpdate(float _Time);
	void HeavyUpChangeMoveUpdate(float _Time);

	void HeavyUpAttackMoveUpdate(float _Time);
		
	void HeavyThrowStart();
	void HeavyThrowUpdate(float _Time); 

	void HeavyThrowMoveStart();
	void HeavyThrowMoveUpdate(float _Time);


	//void HeavyUpJumpMoveAttackUpdate(float _Time);
	//void HeavyUpJumpMoveDownAttackStart(float _Time);

	float RightHeavyBulletTime = 0;
	float LeftHeavyBulletTime = 0;
	float UpHeavyBulletTime = 0;

	float asda = 20;
	Bomb* Actor = nullptr;
	HeavyGun* HeavyBullet = nullptr; 
	MiddleBoss* middleBoss = nullptr;
	float SpeedDown = 0; 

	float PalaceTime = 0; 

	bool RightHeavyBulletCheck = false;
	bool LeftHeavyBulletCheck = false;
	bool UpHeavyBulletCheck = false;

	bool IdleChangeUpCheck = false;
	bool blueCheck = false;
	bool RebelStart = false;

	float RightAttackChangeUp = 0;
	float LeftAttackChangeUp = 0;
	float RightUpChangeAttack = 0; 
	float LeftUpChangeAttack = 0;
	float RightHeavyBulletNumber = 0;
	float LeftHeavyBulletNumber = 0;
	float UPHeavyBulletNumber = 0;

};

