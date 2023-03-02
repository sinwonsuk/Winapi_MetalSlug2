#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
class Items : public GameEngineActor
{



public:


	//enum Direction Dir = Direction::IDLE;
	// constrcuter destructer
	Items();
	~Items();
	Direction Dir = Direction::IDLE;
	// delete Function
	Items(const Items& _Other) = delete;
	Items(Items&& _Other) noexcept = delete;
	Items& operator=(const Items& _Other) = delete;
	Items& operator=(Items&& _Other) noexcept = delete;
	float4 MoveDir = float4::Zero;
	bool SetGunBoombChangeCheck(const bool& Check)
	{
		return GunBoombChangeCheck = Check; 
	}


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
private:
	float ItemTime = 0;
	bool GunBoombChangeCheck = false;
	float BoombNumber = 0;
	float HeavyMachineGuneNumber = 0;
	bool CollisionCheck = false;
	float DeathCheck = 0; 
	GameEngineRender* HeavyMachineGun = nullptr;
	GameEngineRender* Effect = nullptr;
	GameEngineRender* Boomb = nullptr;
	GameEngineCollision* Collision = nullptr;



};
