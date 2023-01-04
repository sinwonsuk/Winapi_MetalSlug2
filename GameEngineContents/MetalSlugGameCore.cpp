#include "MetalSlugGameCore.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "CharacterSelect.h"
// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
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

