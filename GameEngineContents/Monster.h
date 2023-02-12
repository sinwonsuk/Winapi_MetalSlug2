#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "MonsterBullet.h"

enum class MonsterState
{
	IDLE,
	MOVE,
	PlAYERCHECK,
	ATTACKPRE,
	ATTACK,
	MONSTERBULLET,
	JUMP,
	JUMPBACK,
	DEATHONE,
	DEATHTWO,
};

// Ό³Έν :
class Monster : public GameEngineActor
{
public:
	static Monster* MonsterA;

	// constrcuter destructer
	Monster();
	~Monster();
	std::string DirString = "Left_";
	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(MonsterState _State);

	void IdleStart();
	void IdleUpdate(float _Time);

	void MoveStart(); 
	void MoveUpdate(float _Time);

	void AttackStart();
	void AttackUpdate(float _Time);

	void AttackPreStart();
	void AttackPreUpdate(float _Time);

	void PlayerCheckStart(); 
	void PlayerCheckUpdate(float _Time); 

	void MonsterBulletStart();
	void MonsterBulletUpdate(float _Time);

	void MonsterJumpStart();
	void MonsterJumpUpdate();

	void MonsterBackJumpStart(); 
	void MonsterBackJumpUpdate();

	void MonsterDeathOneStart(); 
	void MonsterDeathOneUpdate();

	
	void MonsterDeathTwoStart(); 
	void MonsterDeathTwoUpdate();

	
	/*inline void SetMoveDir(const float4& _MovePos)
	{
		MoveDir = _MovePos;
	}*/

	GameEngineCollision* GetPlayerCollision()
	{
		return PlayerCollision;
	}
	
	bool SetRunCheck(bool& Check)
	{
		RunCheck = Check;

		return RunCheck; 
	}
	/*GameEngineCollision* SetPlayerCollision()
	{
		return PlayerCollision;
	}*/
	GameEngineCollision* PlayerCollision = nullptr;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;	

private:

	MonsterState StateValue = MonsterState::IDLE;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	GameEngineRender* AnimationRender = nullptr;
	//GameEngineRender* BulletRender = nullptr;
	GameEngineCollision* MonsterCollision = nullptr;
	int a = 0;
	bool RunCheck = true;
	MonsterBullet* Actor = nullptr;
	float AnimationCheck = 0;

};


