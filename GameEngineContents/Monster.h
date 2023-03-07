#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

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
	void MonsterJumpUpdate(float _Time);

	void MonsterBackJumpStart(); 
	void MonsterBackJumpUpdate(float _Time);

	void MonsterDeathOneStart(); 
	void MonsterDeathOneUpdate(float _Time);

	
	void MonsterDeathTwoStart(); 
	void MonsterDeathTwoUpdate(float _Time);

	
	

	GameEngineCollision* GetPlayerCollision()
	{
		return PlayerCollision;
	}
	
	bool SetRunCheck(bool& Check)
	{
		RunCheck = Check;

		return RunCheck; 
	}

	GameEngineCollision* PlayerCollision = nullptr;
	/*int GetNumber()
	{
		return Number;
	}*/

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;	

private:

	MonsterState StateValue = MonsterState::IDLE;
	float BulletRange = 0;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float JumpSpeed = 650; 
	float MoveSpeed = 1000;
	GameEngineRender* AnimationRender = nullptr;
	float DeathTime = 0;
	bool DeathCheck = false;
	GameEngineCollision* MonsterCollision = nullptr;
	int Hp = 1;
	float a = 0;
	bool death = false;
	bool RunCheck = true;
	bool Test = false;
	bool GroundCheck = false;
	float BackJumpTime =0;
	float AnimationCheck = 0;
	bool BackJumpCheck = false;

	GameEngineSoundPlayer DeathOne;
	GameEngineSoundPlayer DeathTwo;


};


