#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BazookaBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	BazookaBullet();
	~BazookaBullet();

	// delete Function
	BazookaBullet(const BazookaBullet& _Other) = delete;
	BazookaBullet(BazookaBullet&& _Other) noexcept = delete;
	BazookaBullet& operator=(const BazookaBullet& _Other) = delete;
	BazookaBullet& operator=(BazookaBullet&& _Other) noexcept = delete;

	float4 MoveDir = float4::Zero;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool DeathCheck = false;
	GameEngineRender* BulletRender = nullptr;
	GameEngineCollision* Collision = nullptr;

};
