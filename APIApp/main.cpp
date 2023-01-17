#include <Windows.h>
#include <GameEngineContents/StudyGameCore.h>
#include <GameEngineBase/GameEngineTime.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	StudyGameCore::GetInst().CoreStart(hInstance);
	return 1;
}