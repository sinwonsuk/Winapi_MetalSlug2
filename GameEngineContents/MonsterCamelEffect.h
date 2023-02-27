#pragma once
#include <GameEngineCore/GameEngineActor.h>
class MonsterCamelEffect : public GameEngineActor
{
public:
	MonsterCamelEffect();
	~MonsterCamelEffect();

	// delete Function
	MonsterCamelEffect(const MonsterCamelEffect& _Other) = delete;
	MonsterCamelEffect(MonsterCamelEffect&& _Other) noexcept = delete;
	MonsterCamelEffect& operator=(const  MonsterCamelEffect& _Other) = delete;
	MonsterCamelEffect& operator=(MonsterCamelEffect&& _Other) noexcept = delete;
	bool test = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(); 
private:
	float TimeCheck = 0;
	bool Time = false;
	float Value = 10;
	


	float4 CamerPos = float4::Zero;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 MoveDir2 = float4::Zero;
	float4 MoveDir3 = float4::Zero;
	float4 MoveDir4 = float4::Zero;
	float4 MoveDir5 = float4::Zero;
	


	GameEngineRender* CamelEffect = nullptr;
	GameEngineRender* CamelEffect1 = nullptr;
	GameEngineRender* CamelEffect2 = nullptr;
	GameEngineRender* CamelEffect3 = nullptr;
	GameEngineRender* CamelEffect4 = nullptr;
	GameEngineRender* CamelEffect5 = nullptr;



	/*GameEngineRender* I = nullptr;
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
	GameEngineRender* Sign = nullptr;*/
};
