#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class OpenningLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	OpenningLevel();
	~OpenningLevel();

	// delete Function
	OpenningLevel(const OpenningLevel& _Other) = delete;
	OpenningLevel(OpenningLevel&& _Other) noexcept = delete;
	OpenningLevel& operator=(const OpenningLevel& _Other) = delete;
	OpenningLevel& operator=(OpenningLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;

private:

};

