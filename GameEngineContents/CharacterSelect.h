#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

class CharacterSelect : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelect();
	~CharacterSelect();

	// delete Function
	CharacterSelect(const CharacterSelect& _Other) = delete;
	CharacterSelect(CharacterSelect&& _Other) noexcept = delete;
	CharacterSelect& operator=(const CharacterSelect& _Other) = delete;
	CharacterSelect& operator=(CharacterSelect&& _Other) noexcept = delete;
	void BackGroundSound();
protected:
	void Start() override;

private:
	float4 MoveDir = float4::Up * 500;
	float4 MoveDir2 = float4::Up * 700;
	float4 MoveDir3 = float4::Up * 500;
	float4 MoveDir4 = float4::Up * 650;
	float4 MoveDir5 = float4::Down * 650;

	void Update(float _DeltaTime);

	GameEngineRender* BackGround = nullptr;

	GameEngineSoundPlayer BGMPlayer;
	GameEngineSoundPlayer cursor;
	GameEngineSoundPlayer CharacterSelectSound;
	//GameEngineSoundPlayer BGMPlayer;
		


	GameEngineRender* Marco = nullptr;
	GameEngineRender* Eri = nullptr;
	GameEngineRender* Tarma	 = nullptr;
	GameEngineRender* Fio = nullptr;
	GameEngineRender* FinishEri = nullptr;
	

	GameEngineRender* AnimationRender = nullptr;
	GameEngineRender* Door1 = nullptr;
	GameEngineRender* Door2 = nullptr;
	GameEngineRender* Door3 = nullptr;
	GameEngineRender* Door4 = nullptr;
	GameEngineRender* FinishDoor = nullptr;

	
	float P1Time = 0;
	float ChoiceTime = 0;
	float FinishTime = 0;
	bool P1Check = false; 
	bool DoorCheck = false;
	bool EnterCheck = false; 
	bool BackGroundSoundCheck = false;
};
