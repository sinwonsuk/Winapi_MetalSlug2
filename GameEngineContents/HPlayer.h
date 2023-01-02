#pragma once

// Ό³Έν :
class HPlayer
{
public:
	// constrcuter destructer
	HPlayer();
	~HPlayer();

	// delete Function
	HPlayer(const HPlayer& _Other) = delete;
	HPlayer(HPlayer&& _Other) noexcept = delete;
	HPlayer& operator=(const HPlayer& _Other) = delete;
	HPlayer& operator=(HPlayer&& _Other) noexcept = delete;

protected:

private:

};

