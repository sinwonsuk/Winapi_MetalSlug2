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


	float Time = 0;
	float Time1 = 0;
	float Time2 = 0;
	bool P1Check = false; 
	bool DoorCheck = false;
	bool EnterCheck = false; 
};
