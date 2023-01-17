#pragma once
#include <GameEngineCore/GameEngineCore.h>

// �̷��� Ŭ������ ����� ��� ����ü�� �̱����̶�� �մϴ�.

// ���� :
class MetalSlugCore : public GameEngineCore
{
public:
	// delete Function
	MetalSlugCore(const MetalSlugCore& _Other) = delete;
	MetalSlugCore(MetalSlugCore&& _Other) noexcept = delete;
	MetalSlugCore& operator=(const MetalSlugCore& _Other) = delete;
	MetalSlugCore& operator=(MetalSlugCore&& _Other) noexcept = delete;

	// �̱���
	static MetalSlugCore& GetInst()
	{
		return Core;
	}

	// �����ͷ� ����ÿ��� �߰��� ������ �����ϴٴ� ������ �ִ�.
	//static StudyGameCore& Destroy()
	//{
	//	delete Core;
	//}

protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	// �����ڸ� ����.
	// constrcuter destructer
	MetalSlugCore();
	~MetalSlugCore();

	// �ڱ⸦ �ڽ��� ������
	// ���α׷��� ��Ʋ� ���� 1���� ��ü�� ���������
	// static StudyGameCore* Core;
	static MetalSlugCore Core;

};

