#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Bullets.h"
#include "Bomb.h"


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

	float4 GetCameraDir()
	{
		return CameraDir; 
	}

	bool test23 = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	bool a = true;
	bool test = false;
	bool test1 = false;
	bool CameraCheck = false;

	int MonsterCheck = 0;
	int d = 99;
	int StartFrame = 0;

	float AccTime = 0.0f;
	float MoveSpeed = 300.0f;
	float JumpSpeed = 800.0f;
	float MonsterBulletRange = 0;
	float TimeCheck = 0;
	float BombNumber = 10; 

	std::string DirString = "Right_";
	std::vector<GameEngineActor*> Bullet;
	std::vector<Bullets*> bullets;
	PlayerState StateValue = PlayerState::IDLE;

	float4 MoveDir = float4::Zero;
	float4 CameraDir = float4::Zero;
	float4 body = { 0,0 };
	float4 Reg = { 0,0 };
	float4 gravity = float4::Zero;
	float4 PosCheck = { 0,0 };


	GameEngineRender* AnimationBodyRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;
	GameEngineCollision* BodyCollision = nullptr;
	GameEngineCollision* BulletCollision = nullptr;

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
		
	//void HeavyUpJumpMoveAttackUpdate(float _Time);
	//void HeavyUpJumpMoveDownAttackStart(float _Time);

	Bomb* Actor = nullptr;
	

};

