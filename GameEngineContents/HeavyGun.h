#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
class HeavyGun : public GameEngineActor
{



public:


	//enum Direction Dir = Direction::IDLE;
	// constrcuter destructer
	HeavyGun();
	~HeavyGun();
	Direction Dir = Direction::IDLE;
	// delete Function
	HeavyGun(const HeavyGun& _Other) = delete;
	HeavyGun(HeavyGun&& _Other) noexcept = delete;
	HeavyGun& operator=(const HeavyGun& _Other) = delete;
	HeavyGun& operator=(HeavyGun&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	bool test = false;
	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;
	//float4 MoveDir = float4::Zero;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
private:
	float Speed = 1000;
	float DeathCheck = 0;
};


