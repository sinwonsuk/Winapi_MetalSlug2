#include "StudyGameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
MetalSlugCore MetalSlugCore::Core;

MetalSlugCore::MetalSlugCore() 
{
}

MetalSlugCore::~MetalSlugCore() 
{
}

void MetalSlugCore::Start()
{
	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
	GameEngineWindow::SettingWindowSize({1200.0f, (1200.0f / 800.0f) * 600.0f});

	new int();

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<PlayLevel>("PlayLevel");
	// static_assert
	// CreateLevel<HPlayer>("Title1");
	ChangeLevel("TitleLevel");

	float4 AAAA = {100, 100};

	AAAA = -AAAA;
}

void MetalSlugCore::Update()
{
	
}
void MetalSlugCore::End() 
{
	
}