#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

class FinishInterFace : public GameEngineActor
{
public:
	FinishInterFace();
	~FinishInterFace();

	// delete Function
	FinishInterFace(const FinishInterFace& _Other) = delete;
	FinishInterFace(FinishInterFace&& _Other) noexcept = delete;
	FinishInterFace& operator=(const  FinishInterFace& _Other) = delete;
	FinishInterFace& operator=(FinishInterFace&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float TimeCheck = 0;
	bool Time = false;
	float Value = 10;
	float Value1 = 200;


	float4 CamerPos = float4::Zero;

	GameEngineRender* BaseBullet = nullptr;
	GameEngineRender* M = nullptr;
	GameEngineRender* I = nullptr;
	GameEngineRender* S = nullptr;
	GameEngineRender* S1 = nullptr;
	GameEngineRender* I1 = nullptr;
	GameEngineRender* O = nullptr;
	GameEngineRender* N = nullptr;
	GameEngineRender* C = nullptr;
	GameEngineRender* O1 = nullptr;
	GameEngineRender* M1 = nullptr;
	GameEngineRender* P = nullptr;
	GameEngineRender* L = nullptr;
	GameEngineRender* E = nullptr;
	GameEngineRender* T = nullptr;
	GameEngineRender* E1 = nullptr;

	bool SoundCheck = false;
	//bool MissionSoundCheck = false;


	GameEngineSoundPlayer MissionComplete;
	GameEngineSoundPlayer BackGround;

};
