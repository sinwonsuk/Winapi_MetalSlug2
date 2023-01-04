#pragma once
#include <GameEngineCore/GameEngineCore.h>

// �̷��� Ŭ������ ����� ��� ����ü�� �̱����̶�� �մϴ�.

// ���� :
class MetalSlugGameCore : public GameEngineCore
{
public:
	// delete Function
	MetalSlugGameCore(const MetalSlugGameCore& _Other) = delete;
	MetalSlugGameCore(MetalSlugGameCore&& _Other) noexcept = delete;
	MetalSlugGameCore& operator=(const MetalSlugGameCore& _Other) = delete;
	MetalSlugGameCore& operator=(MetalSlugGameCore&& _Other) noexcept = delete;

	// �̱���
	static MetalSlugGameCore& GetInst()
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
	 MetalSlugGameCore();
	~MetalSlugGameCore();

	// �ڱ⸦ �ڽ��� ������
	// ���α׷��� ��Ʋ� ���� 1���� ��ü�� ���������
	// static StudyGameCore* Core;
	static MetalSlugGameCore Core;

};

