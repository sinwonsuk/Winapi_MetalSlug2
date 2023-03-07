#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>
enum class WallState
{
	IDLE,
	STOP,
	DEATH,
	EXPLOISION
};

// Ό³Έν :
class Wall : public GameEngineActor
{
public:
	static Wall* wall;

	// constrcuter destructer
	Wall();
	~Wall();
	std::string DirString = "Left_";
	// delete Function
	Wall(const Wall& _Other) = delete;
	Wall(Wall&& _Other) noexcept = delete;
	Wall& operator=(const Wall& _Other) = delete;
	Wall& operator=(Wall&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	
	float GetHp()
	{
		return Hp;
	}
	


	//PalaceBulletDeathSound

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	WallState StateValue = WallState::IDLE;

	GameEngineRender* AnimationRender = nullptr;

	GameEngineRender* Ston = nullptr;
	GameEngineRender* Ston2 = nullptr;
	GameEngineRender* Ston3 = nullptr;
	
	GameEngineRender* Exploision = nullptr;
	float4 WallMoveDir = float4::Zero;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 MoveDir2 = float4::Zero;
	float4 MoveDir3 = float4::Zero;
	float4 MoveDir4 = float4::Zero;
	float4 MoveDir5 = float4::Zero;
	float4 MoveDir6 = float4::Zero;


	float TimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 100;
	float DeathCheck = 0;
	bool MonsterCheck = false;
	bool EffectCheck = false;
	bool death = false;

	bool MoveCamera = false;
	bool StonReset = false;
	float Hp = 30;
	GameEngineCollision* WallCollision = nullptr;

	bool ExpilisionSoundCheck = false;
	bool ExpilisionSoundCheck2 = false;
	bool ExpilisionSoundCheck3 = false;


	GameEngineSoundPlayer ExploisionSound;
	GameEngineSoundPlayer ExploisionSound2;
	GameEngineSoundPlayer ExploisionSound3;
};

