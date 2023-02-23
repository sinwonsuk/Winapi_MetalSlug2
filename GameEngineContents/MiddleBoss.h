#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PalaceBullet.h"
enum class MiddleBossState
{
	
	IDLE,
	IDLESTART,
	OPEN,
	LEFTATTACK,
	MIDDLEATTACK,
	RIGHTATTACK,
	LEFTSMOKE,
	RIGHTSMOKE,
	MIDDLESMOKE,
	MONSTERBULLET,
	DEATH,
	UP,

};

// Ό³Έν :
class MiddleBoss : public GameEngineActor
{
public:
	static MiddleBoss* middleBoss;

	// constrcuter destructer
	MiddleBoss();
	~MiddleBoss();
	std::string DirString = "Left_";
	// delete Function
	MiddleBoss(const MiddleBoss& _Other) = delete;
	MiddleBoss(MiddleBoss&& _Other) noexcept = delete;
	MiddleBoss& operator=(const MiddleBoss& _Other) = delete;
	MiddleBoss& operator=(MiddleBoss&& _Other) noexcept = delete;
	
	void test(const std::string_view& _AnimationName);
	void AnimationCheck(const std::string_view& _AnimationName);
	void OpenCheck(const std::string_view& _AnimationName);
	void LeftAttackCheck(const std::string_view& _AnimationName);
	void RightAttackCheck(const std::string_view& _AnimationName);
	void MiddleAttackCheck(const std::string_view& _AnimationName);
	void LeftSmokeCheck(const std::string_view& _AnimationName);
	void RightSmokeCheck(const std::string_view& _AnimationName);
	void MiddleSmokeCheck(const std::string_view& _AnimationName);



	void DoorStart();
	void DoorUpdate(float _Time);

	void UpdateState(float _Time);
	void ChangeState(MiddleBossState _State);

	void OpenStart();
	void OpenUpdate(float _Time); 

	void IdleStart();
	void IdleUpdate(float _Time);

	
	void LeftAttackStart();
	void LeftAttackUpdate(float _Time);

	void RightAttackStart();
	void RightAttackUpdate(float _Time);

	void MiddleAttackStart();
	void MiddleAttackUpdate(float _Time);
	
	void LeftSmokeStart();
	void LeftSmokeUpdate(float _Time);

	void RightSmokeStart();
	void RightSmokeUpdate(float _Time);

	void MiddleSmokeStart();
	void MiddleSmokeUpdate(float _Time);





	void DeathStart();
	void DeathUpdate(float _Time);


	GameEngineCollision* GetPlayerCollision()
	{
		return PlayerCollision;
	}


	GameEngineCollision* PlayerCollision = nullptr;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:

	MiddleBossState StateValue = MiddleBossState::IDLE;

	GameEngineRender* PalaceBase = nullptr;
	GameEngineRender* PalaceLeft = nullptr;
	GameEngineRender* PalaceMiddle = nullptr;
	GameEngineRender* PalaceRight = nullptr;

	GameEngineRender* LeftDoorRender = nullptr;
	GameEngineRender* MiddleDoorRender = nullptr;
	GameEngineRender* RightDoorRender = nullptr;


	GameEngineRender* AnimationLeftDoorRender = nullptr;
	GameEngineRender* AnimationMiddleDoorRender = nullptr;
	GameEngineRender* AnimationRightDoorRender = nullptr;
	
	GameEngineRender* AnimationLeftWindowRender = nullptr;
	GameEngineRender* AnimationMiddleWindowRender = nullptr;
	GameEngineRender* AnimationRightWindowRender = nullptr;
	
	GameEngineRender* AnimationLeftHumanRender = nullptr;
	GameEngineRender* AnimationRightHumanRender = nullptr;
	GameEngineRender* AnimationMiddleHumanRender = nullptr;

	GameEngineRender* AnimationLeftHumanAttackRender = nullptr;
	GameEngineRender* AnimationRightHumanAttackRender = nullptr;
	GameEngineRender* AnimationMiddleHumanAttackRender = nullptr;

	GameEngineRender* AnimationLeftSmokeRender = nullptr;
	GameEngineRender* AnimationRightSmokeRender = nullptr;
	GameEngineRender* AnimationMiddleSmokeRender = nullptr;

	GameEngineRender* PalaceLeftDestory= nullptr;
	GameEngineRender* PalaceRightDestory = nullptr;
	GameEngineRender* PalaceMiddleDestory = nullptr;


	//GameEngineRender* EffectRender = nullptr;
	float4 MoveDirLeft = float4::Zero;
	float4 MoveDirMiddle = float4::Zero;
	float4 MoveDirRight = float4::Zero;

	float4 MissileLeftDir = float4::Zero;
	float4 MissileMiddleDir = float4::Zero;
	float4 MissileRightDir = float4::Zero;


	float4 CollisionPos = float4::Zero;
	float AttackTime = 0; 
	float LeftRightTimeCheck = 0;
	float MoveCheck = 0; 
	float JumpSpeed = 650;
	float MoveSpeed = 1000;
	float MissileDirCheck = 0;
	int LeftHp = 10;
	int RightHp = 10;
	int MiddleHp = 10;
	float DeathCheck = 0;
	bool  death = false;
	bool ad = false;
	bool EffectCheck = false;

	bool MissileCheck = false;

	PalaceBullet* Bullet = nullptr;
	GameEngineCollision* LeftMonsterCollision = nullptr;
	GameEngineCollision* RightMonsterCollision = nullptr;
	GameEngineCollision* MiddleMonsterCollision = nullptr;
	

};