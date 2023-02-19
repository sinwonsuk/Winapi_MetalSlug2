#include "MonsterCamelEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "MonsterCamel.h"

MonsterCamelEffect::MonsterCamelEffect()
{

}

MonsterCamelEffect::~MonsterCamelEffect()
{

}

void MonsterCamelEffect::Start()
{
	{
		CamelEffect = CreateRender(2);
		CamelEffect->SetImage("MonsterCamelEffect.Bmp");
		CamelEffect->SetPosition({ 200,0 });
		CamelEffect->SetScale({ 50,50 });
		CamelEffect->EffectCameraOff();
	}
	{
		CamelEffect1 = CreateRender(2);
		CamelEffect1->SetImage("MonsterCamelEffect.Bmp");
		CamelEffect1->SetPosition({ 100,0 });
		CamelEffect1->SetScale({ 50,50 });
		CamelEffect1->EffectCameraOff();
	}

	{
		CamelEffect2 = CreateRender(2);
		CamelEffect2->SetImage("MonsterCamelEffect.Bmp");
		CamelEffect2->SetPosition({ 100,0 });
		CamelEffect2->SetScale({ 50,50 });
		CamelEffect2->EffectCameraOff();
	}
	{
		CamelEffect3 = CreateRender(2);
		CamelEffect3->SetImage("MonsterCamelEffect.Bmp");
		CamelEffect3->SetPosition({ 100,0 });
		CamelEffect3->SetScale({ 50,50 });
		CamelEffect3->EffectCameraOff();
	}
	{
		CamelEffect4 = CreateRender(2);
		CamelEffect4->SetImage("MonsterCamelEffect.Bmp");
		CamelEffect4->SetPosition({ 100,0 });
		CamelEffect4->SetScale({ 50,50 });
		CamelEffect4->EffectCameraOff();
	}
	{
		CamelEffect5 = CreateRender(2);
		CamelEffect5->SetImage("MonsterCamelEffect.Bmp");
		CamelEffect5->SetPosition({ 100,0 });
		CamelEffect5->SetScale({ 50,50 });
		CamelEffect5->EffectCameraOff();
	}
}

void MonsterCamelEffect::Update(float _DeltaTime)
{
	//MonsterCamel::CamelMonster->GetPos()
	MoveDir += float4::Down *  2000 * _DeltaTime;
	MoveDir1 += float4::Down * 2000 * _DeltaTime;
	MoveDir2 += float4::Down * 2000 * _DeltaTime;
	MoveDir3 += float4::Down * 2000 * _DeltaTime;
	MoveDir4 += float4::Down * 2000 * _DeltaTime;
	MoveDir5 += float4::Down * 2000 * _DeltaTime;

	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	


	if (test == false)
	{
		CamelEffect->SetPosition({ MonsterCamel::CamelMonster->GetPos().x,MonsterCamel::CamelMonster->GetPos().y-75 });
		MoveDir += float4::Up * 850;
		MoveDir += float4::Left * 75; 

		CamelEffect1->SetPosition({ MonsterCamel::CamelMonster->GetPos().x,MonsterCamel::CamelMonster->GetPos().y - 75 });
		MoveDir1 += float4::Up * 850;
		MoveDir1 += float4::Right * 75;

		CamelEffect2->SetPosition({ MonsterCamel::CamelMonster->GetPos().x,MonsterCamel::CamelMonster->GetPos().y - 75 });
		MoveDir2 += float4::Up * 950;
		MoveDir2 += float4::Left * 50;

		CamelEffect3->SetPosition({ MonsterCamel::CamelMonster->GetPos().x,MonsterCamel::CamelMonster->GetPos().y - 75 });
		MoveDir3 += float4::Up * 950;
		MoveDir3 += float4::Right * 50;

		CamelEffect4->SetPosition({ MonsterCamel::CamelMonster->GetPos().x,MonsterCamel::CamelMonster->GetPos().y - 75 });
		MoveDir4 += float4::Up * 1000;
		MoveDir4 += float4::Left * 100;

		CamelEffect5->SetPosition({ MonsterCamel::CamelMonster->GetPos().x,MonsterCamel::CamelMonster->GetPos().y -75 });
		MoveDir5 += float4::Up * 1000;
		MoveDir5 += float4::Right * 100;


	}




	test = true;
	CamelEffect->SetMove(MoveDir * _DeltaTime);
	CamelEffect1->SetMove(MoveDir1 * _DeltaTime);
	CamelEffect2->SetMove(MoveDir2 * _DeltaTime);
	CamelEffect3->SetMove(MoveDir3 * _DeltaTime);
	CamelEffect4->SetMove(MoveDir4 * _DeltaTime);
	CamelEffect5->SetMove(MoveDir5 * _DeltaTime);
	


}
