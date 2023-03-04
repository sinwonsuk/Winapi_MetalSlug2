#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class MiniMonsterState
{

	IDLE,
	IDLE2,
	LEFTMOVE,
	RIGHTMOVE,
	ATTACK,
	SURRENDER

};

// Ό³Έν :
class MapEffect : public GameEngineActor
{
public:
	static MapEffect* mapEffect;

	// constrcuter destructer
	MapEffect();
	~MapEffect();
	// delete Function
	MapEffect(const MapEffect& _Other) = delete;
	MapEffect(MapEffect&& _Other) noexcept = delete;
	MapEffect& operator=(const MapEffect& _Other) = delete;
	MapEffect& operator=(MapEffect&& _Other) noexcept = delete;

	
	

	

	
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:

	GameEngineRender* BackGroundRender = nullptr;
	GameEngineRender* MiddleTent = nullptr;
	GameEngineRender* MiddleJumpTent = nullptr;
	GameEngineRender* RightTent = nullptr;
	GameEngineRender* RightJumpTent = nullptr;

	GameEngineCollision* LeftEffect = nullptr;
	GameEngineCollision* RightEffect = nullptr;

	float4 MoveDir = float4::Zero;

	bool LeftCheck = false;
	bool RightCheck = false;

};
