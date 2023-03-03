#pragma once
#include <GameEngineCore/GameEngineActor.h>



// Ό³Έν :
class PalaceRebel : public GameEngineActor
{
public:
	

	// constrcuter destructer
	PalaceRebel();
	~PalaceRebel();
	// delete Function
	PalaceRebel(const PalaceRebel& _Other) = delete;
	PalaceRebel(PalaceRebel&& _Other) noexcept = delete;
	PalaceRebel& operator=(const PalaceRebel& _Other) = delete;
	PalaceRebel& operator=(PalaceRebel&& _Other) noexcept = delete;
	
	
	

	bool GetAttackCheck()
	{
		return AttackCheck;
	}


	
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	
	GameEngineRender* AnimationRender = nullptr;

	float4 MoveDir = float4::Zero;
	float DeathTime = 0;	
	float JumpSpeed = 650;
	float MoveSpeed = 100;
	

	bool AttackCheck = false;




	

};

