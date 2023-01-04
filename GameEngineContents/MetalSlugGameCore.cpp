#include "MetalSlugGameCore.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "CharacterSelect.h"
// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// 중간에 절대로 지워지지 않을애를 포인터형으로 만들어서 동적할당해서 사용한다는건
// 제가보기에는 왜??? 그래야하지?
MetalSlugGameCore MetalSlugGameCore::Core;

MetalSlugGameCore::MetalSlugGameCore()
{
}

MetalSlugGameCore::~MetalSlugGameCore()
{
}


void MetalSlugGameCore::Start()
{	
	CreateLevel<PlayLevel>("Title");
	CreateLevel<CharacterSelect>("Select");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Title");
}

void MetalSlugGameCore::Update()
{
	
}
void MetalSlugGameCore::End()
{
	
}

