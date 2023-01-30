#include "StudyGameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"
#include "OpenningLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
StudyGameCore StudyGameCore::Core;

StudyGameCore::StudyGameCore() 
{
}

StudyGameCore::~StudyGameCore() 
{
}

void StudyGameCore::Start()
{
	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
	GameEngineWindow::SettingWindowSize({1200.0f, (1200.0f / 800.0f) * 600.0f});

	new int();


	CreateLevel<TitleLevel>("Title");
	CreateLevel<OpenningLevel>("Openning");
	CreateLevel<PlayLevel>("Play");
	// static_assert
	// CreateLevel<HPlayer>("Title1");
	ChangeLevel("Play");
}

void StudyGameCore::Update()
{
	
}
void StudyGameCore::End() 
{
	
}