#pragma once
#include <GameEngineCore/GameEngineActor.h>
class PalaceBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	PalaceBullet();
	~PalaceBullet();

	// delete Function
	PalaceBullet(const PalaceBullet& _Other) = delete;
	PalaceBullet(PalaceBullet&& _Other) noexcept = delete;
	PalaceBullet& operator=(const PalaceBullet& _Other) = delete;
	PalaceBullet& operator=(PalaceBullet&& _Other) noexcept = delete;

	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 MoveDir2 = float4::Zero;
	float4 LeftMoveDir = float4::Zero;


	float4 RightMoveDir = float4::Zero;
	bool sds = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(); 
private:
	float a = 1;
	int Check = 0;
	float LeftTime = 0;
	float RightTime = 0;
	float Time = 0;
	GameEngineRender* BulletRender = nullptr;
	GameEngineCollision* Collision = nullptr;
};