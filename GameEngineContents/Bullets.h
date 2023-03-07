#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
class Bullets : public GameEngineActor
{
	


public:
	
	
	//enum Direction Dir = Direction::IDLE;
	// constrcuter destructer
	Bullets();
	~Bullets();
	Direction Dir = Direction::IDLE;
	// delete Function
	Bullets(const Bullets& _Other) = delete;
	Bullets(Bullets&& _Other) noexcept = delete;
	Bullets& operator=(const Bullets& _Other) = delete;
	Bullets& operator=(Bullets&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	GameEngineRender* AnimationRender = nullptr;
	GameEngineRender* UpBullet = nullptr;
	GameEngineCollision* Collision = nullptr;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
private:
	float DeathCheck = 0; 
	


};


