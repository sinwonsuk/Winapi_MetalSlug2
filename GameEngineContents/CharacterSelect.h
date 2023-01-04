#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class CharacterSelect : public GameEngineLevel
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

private:

};