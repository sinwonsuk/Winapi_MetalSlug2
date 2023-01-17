#include "GameEngineActor.h"
#include "GameEngineRender.h"

GameEngineActor::GameEngineActor() 
{
}

GameEngineActor::~GameEngineActor() 
{
	for (GameEngineRender* _Render : RenderList)
	{
		if (nullptr == _Render)
		{
			continue;
		}

		delete _Render;
		_Render = nullptr;
	}
}

GameEngineRender* GameEngineActor::CreateRender(const std::string_view& _Image, int _Order /*= 0*/)
{
	GameEngineRender* Render = CreateRender(_Order);
	Render->SetImage(_Image);
	return Render;
}

GameEngineRender* GameEngineActor::CreateRender(int _Order /*= 0*/)
{
	GameEngineRender* Render = new GameEngineRender();
	// 분명뭔가 좀 보기 좋지 않다.
	Render->SetParent(this);
	Render->Owner = this;
	Render->SetOrder(_Order);
	RenderList.push_back(Render);
	return Render;
}