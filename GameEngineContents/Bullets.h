#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Bullets : public GameEngineActor
{
	


public:
	enum Direction
	{
		IDLE,
		Left,
		Right,
		Up,
		Down
	}
	Dir = Direction::IDLE;
	// constrcuter destructer
	Bullets();
	~Bullets();

	// delete Function
	Bullets(const Bullets& _Other) = delete;
	Bullets(Bullets&& _Other) noexcept = delete;
	Bullets& operator=(const Bullets& _Other) = delete;
	Bullets& operator=(Bullets&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	bool test = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	

};


