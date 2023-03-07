#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>
class BulletEffect : public GameEngineActor
{



public:


	//enum Direction Dir = Direction::IDLE;
	// constrcuter destructer
	BulletEffect();
	~BulletEffect();
	
	// delete Function
	BulletEffect(const BulletEffect& _Other) = delete;
	BulletEffect(BulletEffect&& _Other) noexcept = delete;
	BulletEffect& operator=(const BulletEffect& _Other) = delete;
	BulletEffect& operator=(BulletEffect&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	
	bool BoobBulletCheck = false;
	bool ExploisionCheck = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
private:
	//GameEngineRender* Effect = nullptr;
	//bool BoobBulletCheck = false;
	bool EffectCheck = true;
	bool boomSound = false;
	bool GunSound = false;
	GameEngineRender* Exploision = nullptr;
	GameEngineRender* Effect = nullptr;
	GameEngineRender* BobmEffect = nullptr;
	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;
	GameEngineSoundPlayer GunHit;
	GameEngineSoundPlayer BoomSound;


};
