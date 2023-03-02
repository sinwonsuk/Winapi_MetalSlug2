#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>

class InterFace : public GameEngineActor
{
public:
	InterFace();
	~InterFace();

	// delete Function
	 InterFace(const InterFace& _Other) = delete;
	 InterFace(InterFace&& _Other) noexcept = delete;
	 InterFace& operator=(const  InterFace& _Other) = delete;
	 InterFace& operator=(InterFace&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float TimeCheck = 0;
	bool Time = false;
	float Value = 10;
	float Value1 = 200;
	NumberRenderObject TestNumber;
	NumberRenderObject TestNumber1;

	float4 CamerPos = float4::Zero;

	GameEngineRender* BaseBullet = nullptr;
	GameEngineRender* M = nullptr;
	GameEngineRender* I = nullptr;
	GameEngineRender* S = nullptr;
	GameEngineRender* S1 = nullptr;
	GameEngineRender* I1 = nullptr;
	GameEngineRender* O = nullptr;
	GameEngineRender* N = nullptr;
	GameEngineRender* S2 = nullptr;
	GameEngineRender* T = nullptr;
	GameEngineRender* A = nullptr;
	GameEngineRender* R = nullptr;
	GameEngineRender* T1 = nullptr;
	GameEngineRender* Sign = nullptr;

};

