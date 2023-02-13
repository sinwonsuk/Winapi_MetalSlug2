#pragma once
#include <GameEngineCore/GameEngineActor.h>


class MonsterBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	MonsterBullet();
	~MonsterBullet();

	// delete Function
	MonsterBullet(const MonsterBullet& _Other) = delete;
	MonsterBullet(MonsterBullet&& _Other) noexcept = delete;
	MonsterBullet& operator=(const MonsterBullet& _Other) = delete;
	MonsterBullet& operator=(MonsterBullet&& _Other) noexcept = delete;
	bool MonsterBulletMove = false;
	float4 MoveDir = float4::Zero;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:
	GameEngineRender* BulletRender = nullptr;
};