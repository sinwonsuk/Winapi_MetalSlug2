#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
class HeavyGun : public GameEngineActor
{



public:


	//enum Direction Dir = Direction::IDLE;
	// constrcuter destructer
	HeavyGun();
	~HeavyGun();
	Direction Dir = Direction::IDLE;
	// delete Function
	HeavyGun(const HeavyGun& _Other) = delete;
	HeavyGun(HeavyGun&& _Other) noexcept = delete;
	HeavyGun& operator=(const HeavyGun& _Other) = delete;
	HeavyGun& operator=(HeavyGun&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	bool test = false;
	float Speed = 2000;
	
	GameEngineCollision* Collision = nullptr;
	//float4 MoveDir = float4::Zero;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
private:
	
	float DeathCheck = 0;
	GameEngineRender* RightHeavyBullet = nullptr;
	GameEngineRender* RightUpHeavyBullet = nullptr;
	GameEngineRender* RightUpHeavyBullet1 = nullptr;
	GameEngineRender* RightUpHeavyBullet2 = nullptr;
	GameEngineRender* RightUpHeavyBullet3 = nullptr;
	GameEngineRender* RightUpHeavyBullet4 = nullptr;
	GameEngineRender* UpHeavyBullet = nullptr;


	GameEngineRender* LeftHeavyBullet = nullptr;
	GameEngineRender* LeftUpHeavyBullet = nullptr;
	GameEngineRender* LeftUpHeavyBullet1 = nullptr;
	GameEngineRender* LeftUpHeavyBullet2 = nullptr;
	GameEngineRender* LeftUpHeavyBullet3 = nullptr;
	GameEngineRender* LeftUpHeavyBullet4 = nullptr;




};


