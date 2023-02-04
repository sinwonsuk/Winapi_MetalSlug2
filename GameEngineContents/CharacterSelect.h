#pragma once
#include <GameEngineCore/GameEngineActor.h>
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

protected:
	void Start() override;

private:

	void Update(float _DeltaTime);

	GameEngineRender* BackGround = nullptr;


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
};
