#pragma once
#include <GameEngineCore/GameEngineActor.h>


enum class BazookaMonsterState
{
	LEFTMOVE,
	RIGHTMOVE,
	LEFTATTACKPRE,
	RIGHTATTACKPRE,
	LEFTATTACK,
	RIGHTATTACK,
	DEATH
};

// Ό³Έν :
class BazookaMonster : public GameEngineActor
{
public:


	// constrcuter destructer
	BazookaMonster();
	~BazookaMonster();
	std::string DirString = "Left_";
	// delete Function
	BazookaMonster(const BazookaMonster& _Other) = delete;
	BazookaMonster(BazookaMonster&& _Other) noexcept = delete;
	BazookaMonster& operator=(const BazookaMonster& _Other) = delete;
	BazookaMonster& operator=(BazookaMonster&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void AnimationCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(BazookaMonsterState _State);

	void LeftMoveStart(); 
	void LeftMoveUpdate(float _Time);

	void RightMoveStart();
	void RightMoveUpdate(float _Time);

	void LeftAttackPreStart();
	void LeftAttackPreUpdate(float _Time);

	void RightAttackPreStart();
	void RightAttackPreUpdate(float _Time);


	void LeftAttackStart();
	void LeftAttackUpdate(float _Time);

	void RightAttackStart();
	void RightAttackUpdate(float _Time);


	

	void DeathStart();
	void DeathUpdate(float _Time);






protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	BazookaMonsterState StateValue = BazookaMonsterState::LEFTMOVE;

	GameEngineRender* AnimationRender = nullptr;
	GameEngineRender* Effect = nullptr;

	float4 MoveDir = float4::Zero;
	float4 CurMoveDir = float4::Zero;
	
	float TimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 100;
	float DeathCheck = 0;
	bool EffectCheck = false;	
	bool CollisionCheck = false;
	bool LeftMoveCheck = false;
	bool RightMoveCheck = false;
	float AttackTime = 0;
	GameEngineCollision* MonsterCollision = nullptr;
};


