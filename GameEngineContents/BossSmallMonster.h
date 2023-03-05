#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class SmallMonsterState
{
	LEFTIDLE,
	RIGHTIDLE,
	LEFTMOVE,
	RIGHTMOVE,
	LEFTJUMP,
	RIGHTJUMP,
	LEFTATTACK,
	RIGHTATTACK,
	LEFTDEATH,
	RIGHTDEATH

};

// Ό³Έν :
class BossSmallMonster : public GameEngineActor
{
public:


	// constrcuter destructer
	BossSmallMonster();
	~BossSmallMonster();
	// delete Function
	BossSmallMonster(const BossSmallMonster& _Other) = delete;
	BossSmallMonster(BossSmallMonster&& _Other) noexcept = delete;
	BossSmallMonster& operator=(const BossSmallMonster& _Other) = delete;
	BossSmallMonster& operator=(BossSmallMonster&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void AnimationCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(SmallMonsterState _State);



	void LeftIdleStart();
	void LeftIdleUpdate(float _Time);

	void RightIdleStart();
	void RightIdleUpdate(float _Time);

	


	void LeftMoveStart();
	void LeftMoveUpdate(float _Time);

	void RightMoveStart();
	void RightMoveUpdate(float _Time);

	void LeftJumpStart();
	void LeftJumpUpdate(float _Time);

	void RightJumpStart();
	void RightJumpUpdate(float _Time);



	void LeftAttackStart();
	void LeftAttackUpdate(float _Time);

	void RightAttackStart();
	void RightAttackUpdate(float _Time);


	void LeftDeathStart();
	void LeftDeathUpdate(float _Time);

	void RightDeathStart();
	void RightDeathUpdate(float _Time);

	float4 MoveDir = float4::Zero;


protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	SmallMonsterState StateValue = SmallMonsterState::LEFTMOVE;

	GameEngineRender* AnimationRender = nullptr;
	GameEngineRender* Effect = nullptr;
	float4 CurMoveDir = float4::Zero;
	
	 
	bool DownCheck = false;
	bool EffectCheck = false;
	//bool death = false;
	int AttackNumber = 0; 
	float Time = 0;
	float BulletRange = 0;


	bool JumpCheck = false;	
	bool CollisionCheck = false;
	bool AttackCheck = false;
	//MachineMonsterBullet* Actor = nullptr;
	GameEngineCollision* MonsterCollision = nullptr;

};
