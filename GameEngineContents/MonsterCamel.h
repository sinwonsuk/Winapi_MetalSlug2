#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "MonsterCamelEffect.h"
enum class MonsterCamelState
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
class MonsterCamel : public GameEngineActor
{
public:
	static MonsterCamel* CamelMonster;

	// constrcuter destructer
	MonsterCamel();
	~MonsterCamel();
	std::string DirString = "Left_";
	// delete Function
	MonsterCamel(const MonsterCamel& _Other) = delete;
	MonsterCamel(MonsterCamel&& _Other) noexcept = delete;
	MonsterCamel& operator=(const MonsterCamel& _Other) = delete;
	MonsterCamel& operator=(MonsterCamel&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
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
	void PlayerCheckStart();
	void PlayerCheckUpdate(float _Time);

	void MonsterBulletStart();
	void MonsterBulletUpdate(float _Time);

	void MonsterDeathStart();
	void MonsterDeathUpdate();

	
	
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

	MonsterCamelState StateValue = MonsterCamelState::IDLE;

	GameEngineRender* AnimationBodyRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;
	GameEngineRender* EffectRender = nullptr;
	MonsterCamelEffect* Effect = nullptr;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 CollisionPos = float4::Zero;
	float LeftRightTimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 1000;

	bool EffectCheck = false;
	
	

	
	GameEngineCollision* MonsterCollision = nullptr;
	
	int LeftRightCount = 0;

};