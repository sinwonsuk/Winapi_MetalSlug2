#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>
enum class MachineState
{
	IDLE,
	IDLE2,
	ATTACKPRE,
	ATTACKPRE2,
	MOVE,
	MOVEFINISH,
	ATTACK,
	DEATH,
};

// Ό³Έν :
class MachineMonster : public GameEngineActor
{
public:


	// constrcuter destructer
	MachineMonster();
	~MachineMonster();
	// delete Function
	MachineMonster(const MachineMonster& _Other) = delete;
	MachineMonster(MachineMonster&& _Other) noexcept = delete;
	MachineMonster& operator=(const MachineMonster& _Other) = delete;
	MachineMonster& operator=(MachineMonster&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(MachineState _State);



	void IdleStart();
	void IdleUpdate(float _Time);

	void AttackPreStart();
	void AttackPreUpdate(float _Time);

	void AttackPre2Start();
	void AttackPre2Update(float _Time);

	void MoveStart();
	void MoveUpdate(float _Time);


	void AttackStart();
	void AttackUpdate(float _Time);

	void DeathStart();
	void DeathUpdate(float _Time);






protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	MachineState StateValue = MachineState::IDLE;

	GameEngineRender* AnimationRender = nullptr;
	GameEngineRender* Effect = nullptr;

	float4 MoveDir = float4::Zero;
	bool Turn = true;
	bool DownCheck = false;
	float TimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 100;
	float DeathCheck = 0;
	bool EffectCheck = false;
	bool death = false;
	bool MoveCamera = false;
	float AttackCheck = 0; 
	float Hp = 30;
	float Time = 0;
	int a = 0;
	float BulletRange = 0;
	int AttackNumber = 0;
	//MachineMonsterBullet* Actor = nullptr;
	GameEngineCollision* MonsterCollision = nullptr;

	bool SoundCheck = false;
	GameEngineSoundPlayer DeathSound;

};
