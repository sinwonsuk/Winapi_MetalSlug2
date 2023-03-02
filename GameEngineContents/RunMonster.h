#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class RunMonsterState
{

	IDLE,

	STOP,
	MOVE,
	DEATH,
	
	
	DMOVEPRE,
	DEATHTWO
};

// Ό³Έν :
class RunMonster : public GameEngineActor
{
public:
	

	// constrcuter destructer
	RunMonster();
	~RunMonster();
	std::string DirString = "Left_";
	// delete Function
	RunMonster(const RunMonster& _Other) = delete;
	RunMonster(RunMonster&& _Other) noexcept = delete;
	RunMonster& operator=(const RunMonster& _Other) = delete;
	RunMonster& operator=(RunMonster&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(RunMonsterState _State);

	void MoveUpdate(float _Time);
	void MoveStart();

	void IdleStart();
	void IdleUpdate(float _Time);


	void DeathStart();
	void DeathUpdate(float _Time);

	void DeathTwoStart();
	void DeathTwoUpdate(float _Time);
	bool SetCarriageMonster(const bool& Check)
	{
		return CarriageMonster = Check; 
	}
	




protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	RunMonsterState StateValue = RunMonsterState::IDLE;
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

	bool CarriageMonster = false;
	bool EffectCheck = false;
	bool death = false;
	bool Idle = true;
	bool CarriageMonsterSee = false;
	GameEngineCollision* MonsterCollision = nullptr;

};

