#pragma once
#include "GameEngineImage.h"
#include <map>
#include <string>

// 사운드 이미지 전부다 이녀석이 관리하겠습니다.

// 설명 :
class GameEngineResources
{
public:
	GameEngineResources(const GameEngineResources& _Other)
	{

	}
	GameEngineResources(GameEngineResources&& _Other) noexcept = delete;
	GameEngineResources& operator=(const GameEngineResources& _Other) = delete;
	GameEngineResources& operator=(GameEngineResources&& _Other) noexcept = delete;

	GameEngineResources& GetInst() 
	{
		return Inst;
	}

protected:
	// 
	void ImageLoad(const std::string_view& _Path);

private:
	static GameEngineResources Inst;

	GameEngineResources();
	~GameEngineResources();

	//        xxxx.bmp
	std::map<std::string, GameEngineImage*> AllImage;

};

