#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class MiniMonsterState
{

	IDLE,
	LEFTMOVE,
	RIGHTMOVE,
	ATTACK,
	SURRENDER
	
};

// Ό³Έν :
class MiniBoss : public GameEngineActor
{
public:
	static MiniBoss* miniboss;

	// constrcuter destructer
	MiniBoss();
	~MiniBoss();
	// delete Function
	MiniBoss(const MiniBoss& _Other) = delete;
	MiniBoss(MiniBoss&& _Other) noexcept = delete;
	MiniBoss& operator=(const MiniBoss& _Other) = delete;
	MiniBoss& operator=(MiniBoss&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(MiniMonsterState _State);

	

	void IdleStart();
	void IdleUpdate(float _Time);

	void LeftMoveStart();
	void LeftMoveUpdate(float _Time);
	
	void RightMoveStart();
	void RightMoveUpdate(float _Time);

	void AttackStart(); 
	void AttackUpdate(float _Time);

	void SurrenderStart();
	void SurrenderUpdate(float _Time);

	bool GetAttackCheck()
	{
		return AttackCheck; 
	}




protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	MiniMonsterState StateValue = MiniMonsterState::IDLE;
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
	float Hp = 3;

	bool AttackCheck = false;
	

	bool Idle = false;
	
	GameEngineCollision* MonsterCollision = nullptr;

};

