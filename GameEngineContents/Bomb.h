#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"

class Bomb : public GameEngineActor
{



public:


	//enum Direction Dir = Direction::IDLE;
	// constrcuter destructer
	Bomb();
	~Bomb();
	Direction Dir = Direction::IDLE;
	// delete Function
	Bomb(const Bomb& _Other) = delete;
	Bomb(Bomb&& _Other) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	bool test = false;
	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;
	float4 CurPos = float4::Zero;
	bool SetDirCheck(bool & Check)
	{
		return DirCheck = Check;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
private:
	GameEngineRender* BoombRender = nullptr;
	bool DirCheck = true;
};


