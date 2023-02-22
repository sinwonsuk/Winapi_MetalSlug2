#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class MiddleBossState
{
	IDLESTART,
	IDLE,
	MOVE,
	PlAYERCHECK,
	ATTACKPRE,
	ATTACK,
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

	/*void Movecalculation(float _DeltaTime);
	void DirBodyCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);

	void UpdateState(float _Time);
	void ChangeState(MonsterCamelState _State);

	void MonsterStart();
	void MonsterUpdate(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);

	void MoveStart();
	void MoveUpdate(float _Time);

	void AttackStart();
	void AttackUpdate(float _Time);

	void AttackPreStart();
	void AttackPreUpdate(float _Time);

	void UpStart();
	void UpUpdate(float _Time);

	void DeathStart();
	void DeathUpdate(float _Time);*/


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

	//MonsterCamelState StateValue = MonsterCamelState::IDLE;
	GameEngineRender* PalaceBase = nullptr;
	GameEngineRender* AnimationBodyRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;
	GameEngineRender* EffectRender = nullptr;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 CollisionPos = float4::Zero;
	float LeftRightTimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 1000;
	int Hp = 10;;
	float DeathCheck = 0;
	bool  death = false;
	bool EffectCheck = false;




	GameEngineCollision* MonsterCollision = nullptr;

	

};