#include "StudyGameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"
#include "OpenningLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// 중간에 절대로 지워지지 않을애를 포인터형으로 만들어서 동적할당해서 사용한다는건
// 제가보기에는 왜??? 그래야하지?
StudyGameCore StudyGameCore::Core;

StudyGameCore::StudyGameCore() 
{
}

StudyGameCore::~StudyGameCore() 
{
}

void StudyGameCore::Start()
{
	// 정수의 연산 결과값은? 무조건 정수만 나옵니다.
	// 실수 1.2 원한다면 
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