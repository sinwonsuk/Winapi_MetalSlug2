#include "Map.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Map::Map()
{
}

Map::~Map()
{
}


void Map::Start()
{
	{
		GameEngineRender* AnimationRender = CreateRender(1);
		AnimationRender->SetPosition({ 1200,430 });
		AnimationRender->SetScale({ 2400,859 });
		AnimationRender->SetImage("Stage0.Bmp");
	}
		{
		GameEngineRender* AnimationRender = CreateRender(0);

		AnimationRender->SetPosition({ 1200,430 });
		AnimationRender->SetScale({ 2400,859 });
		AnimationRender->SetImage("Stage02.Bmp");
	     }

}