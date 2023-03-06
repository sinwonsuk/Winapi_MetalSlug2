#include "MonsterCamelEffect.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineTime.h>
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
		CamelEffect = CreateRender(5);
		CamelEffect->SetImage("MonsterCamelEffect.Bmp");
		//CamelEffect->SetPosition({ 0,0 });
		CamelEffect->SetScale({ 50,50 });
	//	CamelEffect->EffectCameraOff();
	}
	{
		CamelEffect1 = CreateRender(5);
		CamelEffect1->SetImage("MonsterCamelEffect.Bmp");
		//CamelEffect1->SetPosition({ 100,0 });
		CamelEffect1->SetScale({ 50,50 });
	//	CamelEffect1->EffectCameraOff();
	}

	{
		CamelEffect2 = CreateRender(5);
		CamelEffect2->SetImage("MonsterCamelEffect.Bmp");
		//CamelEffect2->SetPosition({ 100,0 });
		CamelEffect2->SetScale({ 50,50 });
	//	CamelEffect2->EffectCameraOff();
	}
	{
		CamelEffect3 = CreateRender(5);
		CamelEffect3->SetImage("MonsterCamelEffect.Bmp");
		//CamelEffect3->SetPosition({ 100,0 });
		CamelEffect3->SetScale({ 50,50 });
	//	CamelEffect3->EffectCameraOff();
	}
	{
		CamelEffect4 = CreateRender(5);
		CamelEffect4->SetImage("MonsterCamelEffect.Bmp");
		//CamelEffect4->SetPosition({ 100,0 });
		CamelEffect4->SetScale({ 50,50 });
	//	CamelEffect4->EffectCameraOff();
	}
	{
		CamelEffect5 = CreateRender(5);
		CamelEffect5->SetImage("MonsterCamelEffect.Bmp");
	//	CamelEffect5->SetPosition({ 100,0 });
		CamelEffect5->SetScale({ 50,50 });
	//	CamelEffect5->EffectCameraOff();
	}
}

void MonsterCamelEffect::Update(float _DeltaTime)
{
	TimeCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();


	if (TimeCheck > 4)
	{
		this->Death();
		return;
	}
	if (test == true)
	{
		MoveDir += float4::Down * 2000 * _DeltaTime;
		MoveDir1 += float4::Down * 2000 * _DeltaTime;
		MoveDir2 += float4::Down * 2000 * _DeltaTime;
		MoveDir3 += float4::Down * 2000 * _DeltaTime;
		MoveDir4 += float4::Down * 2000 * _DeltaTime;
		MoveDir5 += float4::Down * 2000 * _DeltaTime;
	}


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


	float4 Pos = -CamelEffect->GetPosition();
	float4 NextPos = Pos + MoveDir * _DeltaTime;


	test = true;
	if (MonsterCamel::CamelMonster->GetPos().y < CamelEffect->GetPosition().y)
	{
		CamelEffect->Off();
	}
	if (MonsterCamel::CamelMonster->GetPos().y < CamelEffect1->GetPosition().y)
	{
		CamelEffect1->Off();
	}
	if (MonsterCamel::CamelMonster->GetPos().y < CamelEffect2->GetPosition().y)
	{
		CamelEffect2->Off();
	}
	if (MonsterCamel::CamelMonster->GetPos().y < CamelEffect3->GetPosition().y)
	{
		CamelEffect3->Off();
	}
	if (MonsterCamel::CamelMonster->GetPos().y < CamelEffect4->GetPosition().y)
	{
		CamelEffect4->Off();
	}
	if (MonsterCamel::CamelMonster->GetPos().y < CamelEffect5->GetPosition().y)
	{
		CamelEffect5->Off();
	}
	


	



	CamelEffect->SetMove(MoveDir * _DeltaTime);
	CamelEffect1->SetMove(MoveDir1 * _DeltaTime);
	CamelEffect2->SetMove(MoveDir2 * _DeltaTime);
	CamelEffect3->SetMove(MoveDir3 * _DeltaTime);
	CamelEffect4->SetMove(MoveDir4 * _DeltaTime);
	CamelEffect5->SetMove(MoveDir5 * _DeltaTime);
	


}

void MonsterCamelEffect::Render()
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);


}
