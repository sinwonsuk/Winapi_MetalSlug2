#include <Windows.h>
#include <GameEngineContents/MetalSlugCore.h>
#include <GameEngineBase/GameEngineTime.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	MetalSlugCore::GetInst().CoreStart(hInstance);
	return 1;
}