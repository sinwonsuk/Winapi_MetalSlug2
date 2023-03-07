#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

class RebelBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	RebelBullet();
	~RebelBullet();

	// delete Function
	RebelBullet(const RebelBullet& _Other) = delete;
	RebelBullet(RebelBullet&& _Other) noexcept = delete;
	RebelBullet& operator=(const RebelBullet& _Other) = delete;
	RebelBullet& operator=(RebelBullet&& _Other) noexcept = delete;
	bool BulletMove = false;
	bool DeathCheck = false;
	float TimeCheck = 0; 
	float4 MoveDir = float4::Zero;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* BulletRender = nullptr;
	bool SoundCheck = false;
	GameEngineSoundPlayer BulletexPloision;

};
