#pragma once

#include <GameEngineCore/GameEngineActor.h>

	enum class CarriageState
	{
		IDLE,
		STOP,
		DEATH,
	};

	// Ό³Έν :
class Carriage : public GameEngineActor
{
public:
	static Carriage* carriage;

	// constrcuter destructer
	Carriage();
	~Carriage();
	std::string DirString = "Left_";
	// delete Function
	Carriage(const Carriage& _Other) = delete;
	Carriage(Carriage&& _Other) noexcept = delete;
	Carriage& operator=(const Carriage& _Other) = delete;
	Carriage& operator=(Carriage&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(CarriageState _State);

	void StopStart(); 
	void StopUpdate(float _Time); 

	void IdleStart();
	void IdleUpdate(float _Time);

	
	void DeathStart();
	void DeathUpdate(float _Time);

	

	bool SetTurn(const bool& Check)
	{
		return Turn = Check;
	}
	bool SetDownCheck(const bool& Check)
	{
		return DownCheck = Check;
	}





protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	CarriageState StateValue = CarriageState::IDLE;

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
	float Hp = 10; 
	float Time = 0; 
	GameEngineCollision* MonsterCollision = nullptr;

};



