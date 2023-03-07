#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

class MonsterCamelBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	MonsterCamelBullet();
	~MonsterCamelBullet();

	// delete Function
	MonsterCamelBullet(const MonsterCamelBullet& _Other) = delete;
	MonsterCamelBullet(MonsterCamelBullet&& _Other) noexcept = delete;
	MonsterCamelBullet& operator=(const MonsterCamelBullet& _Other) = delete;
	MonsterCamelBullet& operator=(MonsterCamelBullet&& _Other) noexcept = delete;
	
	float4 MoveDir = float4::Zero;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* BulletRender = nullptr;
	GameEngineCollision* Collision = nullptr;
	
	GameEngineSoundPlayer CamelBullet;
	bool CamelSound = false;
	float Time = 0;
};