#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class BossState
{

	IDLE,
	ATTACK,
	SURRENDER

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
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(BossState _State);

	void Idle2Update(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);

	void LeftMoveStart();
	void LeftMoveUpdate(float _Time);

	void RightMoveStart();
	void RightMoveUpdate(float _Time);

	void AttackStart();
	void AttackUpdate(float _Time);

	bool GetAttackCheck()
	{
		return AttackCheck;
	}


	bool compulsionAttackStart = false;
	bool compulsionAttack = false;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	BossState StateValue = BossState::IDLE;
	GameEngineRender* AnimationRender = nullptr;

	GameEngineRender* AnimationBloodRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;

	float4 MoveDir = float4::Zero;

	float DeathTime = 0;
	float TimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 100;
	float MoveCheck = 0;
	float IdleCheck = 0;

	bool AttackCheck = false;


	bool Idle = false;

	GameEngineCollision* MonsterCollision = nullptr;

};


