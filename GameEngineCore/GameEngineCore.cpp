#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "GameEngineLevel.h"

GameEngineCore* Core;

void GameEngineCore::GlobalStart() 
{
	Core->Start();
}

void GameEngineCore::GlobalUpdate() 
{
	Core->Update();
	if (nullptr == Core->MainLevel)
	{
		MsgAssert("������ ���������� ���� ���·� �ھ �����߽��ϴ�");
		return;
	}
	
}

void GameEngineCore::GlobalEnd() 
{
	Core->End();
}


GameEngineCore::GameEngineCore() 
{
	GameEngineDebug::LeakCheck();
	Core = this;
}

GameEngineCore::~GameEngineCore() 
{
	std::map<std::string, GameEngineLevel*>::iterator StartIter = Levels.begin();
	std::map<std::string, GameEngineLevel*>::iterator EndIter = Levels.end();

	for (size_t i = 0; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
		}
	}

	Levels.clear();
}

void GameEngineCore::CoreStart(HINSTANCE _instance)
{
	GameEngineWindow::WindowCreate(_instance, "MainWindow", { 1280, 1120 }, { 0, 0 });
	GameEngineWindow::WindowLoop(GameEngineCore::GlobalStart, GameEngineCore::GlobalUpdate, GameEngineCore::GlobalEnd);
}

void GameEngineCore::ChangeLevel(const std::string_view& _Name) 
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = Levels.find(_Name.data());

	if (FindIter == Levels.end())
	{
		std::string Name = _Name.data();
		MsgAssert(Name + "�������� �ʴ� ������ �����Ű���� �߽��ϴ�");
		return;
	}

	MainLevel = FindIter->second;
}