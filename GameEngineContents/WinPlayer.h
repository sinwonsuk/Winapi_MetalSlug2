#pragma once
#include <GameEngineCore/GameEngineActor.h>

class WinPlayer : public GameEngineActor
{
public:
	

	// constrcuter destructer
	WinPlayer();
	~WinPlayer();
	// delete Function
	WinPlayer(const WinPlayer& _Other) = delete;
	WinPlayer(WinPlayer&& _Other) noexcept = delete;
	WinPlayer& operator=(const WinPlayer& _Other) = delete;
	WinPlayer& operator=(WinPlayer&& _Other) noexcept = delete;

	
	
	
	
	

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	
	GameEngineRender* AnimationRender = nullptr;

	GameEngineRender* AnimationBloodRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;

	float4 MoveDir = float4::Zero;

	

	
};


