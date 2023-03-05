#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BossSmallMonster.h"
enum class BossState
{

	IDLE,
	SMOKEPRE,
	SMOKE,
	ATTACKPRE,
	ATTACK,


};

// Ό³Έν :
class Boss : public GameEngineActor
{
public:
	static Boss* boss;

	// constrcuter destructer
	Boss();
	~Boss();
	// delete Function
	Boss(const Boss& _Other) = delete;
	Boss(Boss&& _Other) noexcept = delete;
	Boss& operator=(const Boss& _Other) = delete;
	Boss& operator=(Boss&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	//void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(BossState _State);

	

	void IdleStart();
	void IdleUpdate(float _Time);

	void SmokePreStart();
	void SmokePreUpdate(float _Time);

	void SmokeStart();
	void SmokeUpdate(float _Time);

	void AttackPreStart();
	void AttackPreUpdate(float _Time);

	void AttackStart();
	void AttackUpdate(float _Time);

	void AnimationCheck();


	bool GetAttackCheck()
	{
		return AttackCheck;
	}
	float Hp = 100;
	bool BossStart = false;
	float4 MoveDir = float4::Zero;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:

	GameEngineCollision* MonsterCollision = nullptr;

	GameEngineCollision* BullletCollision = nullptr;

	BossState StateValue = BossState::IDLE;

	GameEngineRender* Mainbody = nullptr;

	GameEngineRender* Upbody = nullptr;

	GameEngineRender* TwoPhaseBody = nullptr;

	GameEngineRender* DeathBody = nullptr;

	GameEngineRender* LeftWing = nullptr;
	GameEngineRender* RightWing = nullptr;

	GameEngineRender* LeftGroundEffect = nullptr;
	GameEngineRender* RightGroundEffect = nullptr;

	GameEngineRender* LeftBoom = nullptr;
	GameEngineRender* RightBoom = nullptr;

	GameEngineRender* LeftEngine = nullptr;
	GameEngineRender* RightEngine = nullptr;


	GameEngineRender* MiddleExploision = nullptr;
	GameEngineRender* MiddleExploision2 = nullptr;
	GameEngineRender* MiddleExploision3 = nullptr;
	GameEngineRender* MiddleExploision4 = nullptr;
	GameEngineRender* MiddleExploision5 = nullptr;
	GameEngineRender* MiddleExploision6 = nullptr;
	GameEngineRender* MiddleExploision7 = nullptr;
	GameEngineRender* MiddleExploision8 = nullptr;
	GameEngineRender* MiddleExploision9 = nullptr;
	GameEngineRender* MiddleExploision10 = nullptr;
	
	

	GameEngineRender* BigExploision = nullptr;
	GameEngineRender* BigExploision2 = nullptr;
	GameEngineRender* BigExploision3 = nullptr;
	GameEngineRender* BigExploision4 = nullptr;
	GameEngineRender* BigExploision5 = nullptr;
	
	
	float4 MoveDirGroundEffect = float4::Zero;
	float MoveTime = 0;
	float ads = 0;
	float ChangeTime = 0; 
	int a = 0;
	float AttackPreTime = 0; 
	float BigExploisionTime = 0;
	float Time = 0; 
	float MonsterTime = 0; 
	bool AttackCheck = false;
	BossSmallMonster* SmallMonster = nullptr;
	bool LeftRightCheck = false;
	bool IdleStartCheck = false;
	bool MoveStop = false;
	bool sddfs = false;
	
	bool Finishletter = false;
	float DeathTime = 0;
	float MountTime = 0;
	float ExploisionTime = 0; 
	int MoveCheck = 0;

};


