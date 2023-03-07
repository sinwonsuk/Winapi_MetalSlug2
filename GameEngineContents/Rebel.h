#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

enum class RebelState
{
	IDLE,
	IDLE2,
	MOVEPRE,
	MOVE,
	MOVEFINISH,
	ATTACK,
	DEATH,
};

// Ό³Έν :
class Rebel : public GameEngineActor
{
public:
	

	// constrcuter destructer
	Rebel();
	~Rebel();
	std::string DirString = "Left_";
	// delete Function
	Rebel(const Rebel& _Other) = delete;
	Rebel(Rebel&& _Other) noexcept = delete;
	Rebel& operator=(const Rebel& _Other) = delete;
	Rebel& operator=(Rebel&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(RebelState _State);

	

	void IdleStart();
	void IdleUpdate(float _Time);

	void Idle2Start();
	void Idle2Update(float _Time);

	void MovePreStart();
	void MovePreUpdate(float _Time);

	void MoveStart();
	void MoveUpdate(float _Time);

	void MoveFinsihStart(); 
	void MoveFinsihUpdate(float _Time);

	void AttackStart();
	void AttackUpdate(float _Time);

	void DeathStart();
	void DeathUpdate(float _Time);






protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	RebelState StateValue = RebelState::IDLE;

	GameEngineRender* AnimationRender = nullptr;
	GameEngineRender* Exploision = nullptr;

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
	float Hp = 1;
	float Time = 0;
	int a = 0;
	float BulletRange = 0;
	bool RebelAttack = false;
	GameEngineCollision* MonsterCollision = nullptr;
	
	bool SoundCheck = false;
	bool RunSoundCheck = false;
	GameEngineSoundPlayer DeathSound;
	GameEngineSoundPlayer RunSound;
};

