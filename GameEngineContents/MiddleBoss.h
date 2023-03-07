#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>
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

	
	bool SetMiddleBossStart(const bool& Check)
	{
		return MiddleBossStart = Check; 
	}


	void DeathStart();
	void DeathUpdate(float _Time);
	float GetDeathTime()
	{
		return DeathTime15;
	}

	GameEngineRender* GetPalaceBase()
	{
		return PalaceBase;
	}


	int LeftHp = 20;
	int RightHp = 20;
	int MiddleHp = 20;

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




	GameEngineRender* SmallExploision = nullptr;
	GameEngineRender* SmallExploision2 = nullptr;
	GameEngineRender* SmallExploision3 = nullptr;
	


	GameEngineRender* MiddleExploision = nullptr;
	GameEngineRender* MiddleExploision2 = nullptr;
	GameEngineRender* MiddleExploision3 = nullptr;
	GameEngineRender* MiddleExploision4 = nullptr;
	GameEngineRender* MiddleExploision5 = nullptr;
	GameEngineRender* MiddleExploision6 = nullptr;

	GameEngineRender* BigExploision = nullptr;
	GameEngineRender* BigExploision2 = nullptr;
	GameEngineRender* BigExploision3 = nullptr;

	GameEngineRender* LeftBigExploision = nullptr;
	GameEngineRender* RightBigExploision = nullptr;
	GameEngineRender* MiddleBigExploision = nullptr;

	GameEngineRender* PalaceLeftDoorEffect = nullptr;
	GameEngineRender* PalaceRightDoorEffect = nullptr;


	


	//GameEngineRender* EffectRender = nullptr;
	float4 MoveDirLeft = float4::Zero;
	float4 MoveDirMiddle = float4::Zero;
	float4 MoveDirRight = float4::Zero;

	float4 MissileLeftDir = float4::Zero;
	float4 MissileMiddleDir = float4::Zero;
	float4 MissileRightDir = float4::Zero;


	float4 CollisionPos = float4::Zero;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 CurPos = float4::Zero;
	float AttackTime = 0; 
	float LeftRightTimeCheck = 0;
	float MoveCheck = 0; 
	float MoveSpeed = 1000;
	float MissileDirCheck = 0;
	
	float DeathCheck = 0;
	bool  death = false;
	bool ad = false;
	bool EffectCheck = false;
	float DeathTime = 0;
	float DeathTime2 = 0;
	float DeathTime3 = 0;
	float DeathTime4 = 0;
	float DeathTime5 = 0;
	float DeathTime6 = 0;
	float DeathTime7 = 0;
	float DeathTime8 = 0;
	float DeathTime9 = 0;
	float DeathTime10 = 0;
	float DeathTime11 = 0;
	float DeathTime12 = 0;
	float DeathTime13 = 0;
	float DeathTime14 = 0;
	float DeathTime15 = 0;
	float DeathTime16 = 0;

	
	float shakeTime = 0; 
	bool UpDownShake = false; 
	bool MissileCheck = false;
	bool AnimationEnd = false;
	float LeftScale = 0;
	float RightScale = 0;

	int BulletManager = 0; 
	bool MiddleBossStart = false;
	bool AttackCheck = false;
	int attack = 0;
	//PalaceBullet* Bullet = nullptr;
	GameEngineCollision* LeftMonsterCollision = nullptr;
	GameEngineCollision* RightMonsterCollision = nullptr;
	GameEngineCollision* MiddleMonsterCollision = nullptr;
	
	bool SildeSounCheck = false;
	bool PalaceFinishSoundCheck = false;
	bool DeathSoundCheck = false;
	GameEngineSoundPlayer PalaceSlide;
	GameEngineSoundPlayer PalaceFinish;
	GameEngineSoundPlayer PalaceDeath;
	GameEngineSoundPlayer PalaceExploision;

};