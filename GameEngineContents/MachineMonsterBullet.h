#pragma once
#include <GameEngineCore/GameEngineActor.h>

class MachineMonsterBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	MachineMonsterBullet();
	~MachineMonsterBullet();

	// delete Function
	MachineMonsterBullet(const MachineMonsterBullet& _Other) = delete;
	MachineMonsterBullet(MachineMonsterBullet&& _Other) noexcept = delete;
	MachineMonsterBullet& operator=(const MachineMonsterBullet& _Other) = delete;
	MachineMonsterBullet& operator=(MachineMonsterBullet&& _Other) noexcept = delete;
	bool BulletMove = false;
	bool DeathCheck = false;
	float TimeCheck = 0;
	float4 MoveDir = float4::Zero;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* BulletRender = nullptr;
	GameEngineRender* Effect = nullptr;
};
