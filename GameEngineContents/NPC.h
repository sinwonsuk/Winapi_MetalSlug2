#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "MonsterCamelEffect.h"
enum class NpcState
{
	
	IDLE,
	MOVEPRE,
	LEFTMOVE,
	RIGHTMOVE,
	PlAYERCHECK,
	COLLISION,
	COLLISIONAFTER,
	
	DEATH,


};

// Ό³Έν :
class NPC : public GameEngineActor
{
public:
	static NPC* CamelMonster;

	// constrcuter destructer
	NPC();
	~NPC();
	std::string DirString = "Left_";
	// delete Function
	NPC(const NPC& _Other) = delete;
	NPC(NPC&& _Other) noexcept = delete;
	NPC& operator=(const NPC& _Other) = delete;
	NPC& operator=(NPC&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(NpcState _State);

	

	void IdleStart();
	void IdleUpdate(float _Time);

	void MovePreStart();
	void MovePreUpdate(float _Time);

	void MoveLeftStart();
	void MoveLeftUpdate(float _Time);

	void MoveRightStart();
	void MoveRightUpdate(float _Time);
	
	void CollisionStart(); 
	void CollisionUpdate(float _Time); 

	void CollisionAfterStart(); 
	void CollisionAfterUpdate(float _Time);


	

	void DeathStart();
	void DeathUpdate(float _Time);



	GameEngineCollision* GetPlayerCollision()
	{
		return NpcCollision;
	}


	
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	GameEngineCollision* NpcCollision = nullptr;
	NpcState StateValue = NpcState::IDLE;

	GameEngineRender* AnimationRender = nullptr;


	float4 MoveDir = float4::Zero;
	
	float TimeCheck = 0;
	float JumpSpeed = 650;
	float MoveSpeed = 100;
	float DeathCheck = 0; 
	bool EffectCheck = false;




	GameEngineCollision* MonsterCollision = nullptr;

	

	

};