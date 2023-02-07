#pragma once
#include <GameEngineCore/GameEngineActor.h>
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
	float4 CamerPos = float4::Zero;
};

