#pragma once
#include <Windows.h>
#include <map>
#include <string_view>
#include <GameEngineBase/GameEngineDebug.h>

// core�� ������ ��������ٰ� ���������� �����̴ϴ�.

// ���� : �������� ���� �ε��ؾ��� �ʼ����� ���ҽ��� 
// ���������Լ��� �����ϱ� �߻�Ŭ���̴�.
class GameEngineLevel;
class GameEngineCore
{
private:
	static void GlobalStart();
	static void GlobalUpdate();
	static void GlobalEnd();

public:
	// constrcuter destructer
	GameEngineCore();
	~GameEngineCore();

	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;

	void CoreStart(HINSTANCE _instance);


protected:
	template<typename LevelType>
	void CreateLevel(const std::string_view& _Name) 
	{
		if (Levels.end() != Levels.find(_Name.data()))
		{			
			std::string Name = _Name.data();
			MsgAssert(Name + "�̹� �����ϴ� �̸��� ������ ������� �߽��ϴ�");
			return;
		}

		GameEngineLevel* Level = new LevelType();
		Levels.insert(std::make_pair(_Name.data(), Level));
	}

	void ChangeLevel(const std::string_view& _Name);

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

private:
	// �׷��� map�� ����Ѵ�. 
	std::map<std::string, GameEngineLevel*> Levels;

	GameEngineLevel* MainLevel = nullptr;

};

