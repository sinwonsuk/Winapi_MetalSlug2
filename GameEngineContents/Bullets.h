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
	bool test = false;
	GameEngineRender* AnimationRender = nullptr;
	float4 CurPos = float4::Zero;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	

};


