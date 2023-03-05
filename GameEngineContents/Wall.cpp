#include "Wall.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Player.h"
#include "MachineMonster.h"
#include "BulletEffect.h"
Wall* Wall::wall;

Wall::Wall()
{
}

Wall::~Wall()
{
}


void Wall::Start()
{
	wall = this;
	{
		AnimationRender = CreateRender(MetalSlugOrder::Wall);
		AnimationRender->SetScale({ 1600,1600 });

		AnimationRender->CreateAnimation({ .AnimationName = "WallDown",  .ImageName = "Wall.bmp", .Start = 0, .End = 0, .InterTime = 0.1f,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "WallMiddle",  .ImageName = "Wall.bmp", .Start = 1, .End = 1, .InterTime = 0.1f ,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "WallUp",  .ImageName = "Wall.bmp", .Start = 2, .End = 2, .InterTime = 0.1f,.Loop = false });
	}
	{
		Ston = CreateRender(MetalSlugOrder::Wall);
		Ston->SetScale({ 800,800 });
		Ston->SetPosition({ -20,-300 });
		Ston->CreateAnimation({ .AnimationName = "Ston",  .ImageName = "StonEffect.bmp", .Start = 0, .End = 7, .InterTime = 0.05f,.Loop = true });
	}
	{
		Ston2 = CreateRender(MetalSlugOrder::Wall);
		Ston2->SetScale({ 800,800 });
		Ston2->SetPosition({ -10,-100 });
		Ston2->CreateAnimation({ .AnimationName = "Ston",  .ImageName = "StonEffect.bmp", .Start = 0, .End = 7, .InterTime = 0.05f,.Loop = true });
	}
	{
		Ston3 = CreateRender(MetalSlugOrder::Wall);
		Ston3->SetScale({ 800,800 });
		Ston3->SetPosition({ 10,-200 });
		Ston3->CreateAnimation({ .AnimationName = "Ston",  .ImageName = "StonEffect.bmp", .Start = 0, .End = 7, .InterTime = 0.05f,.Loop = true });
	}
	{
		Exploision = CreateRender(MetalSlugOrder::Exploision);
		Exploision->SetScale({ 1200,1200 });
		Exploision->SetPosition({ -100,-200});
		Exploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });
	}
	Exploision->ChangeAnimation("Exploision");
	Exploision->Off();

	Ston->ChangeAnimation("Ston"); 
	Ston2->ChangeAnimation("Ston");
	Ston3->ChangeAnimation("Ston");
	Ston->Off(); 
	Ston2->Off();
	Ston3->Off();

	AnimationRender->ChangeAnimation("WallDown");

	{
		WallCollision = CreateCollision(MetalSlugOrder::Wall);
		WallCollision->SetScale({ 150,500 });
	}

}
void Wall::Movecalculation(float _DeltaTime)
{
	//WallMoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (50.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -200.0f;
		}
		else
		{
			MoveDir.x = 200.0f;
		}
	}

	//if (450.0f <= abs(MoveDir.x))
	//{
	//	if (0 > MoveDir.x)
	//	{
	//		MoveDir.x = -450.0f;
	//	}
	//	else
	//	{
	//		MoveDir.x = 450.0f;
	//	}
	//}




	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 Pos = -Ston->GetPosition();
	float4 NextPos = Pos + MoveDir * _DeltaTime;
	
	float4 Pos2 = -Ston2->GetPosition();
	float4 NextPos2 = Pos2 + MoveDir * _DeltaTime;

	float4 Pos3 = -Ston3->GetPosition();
	float4 NextPos3 = Pos3 + MoveDir * _DeltaTime;



	/*if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0))))
	{
		Ston->On();
	}
	if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos2, RGB(0, 255, 0))))
	{
		Ston2->On();
	}
	if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos3, RGB(0, 255, 0))))
	{
		Ston3->On();
	}*/



	
}

void Wall::Update(float _DeltaTime)
{
	
	


	if (nullptr != WallCollision )
	{
		std::vector<GameEngineCollision*> collision;
		if (true == WallCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());


				ColActor->Death();
			}
		
			Hp--;
		}
		if (Hp <= -50)
		{
			AnimationRender->Off();
			if (StonReset == false)
			{
				MoveDir = { 0,0 };
				Ston->SetPosition({ -20,-300 });
				Ston2->SetPosition({ -10,-100 });
				Ston3->SetPosition({ 10,-200 });
				StonReset = true;
			}

			MoveDir += float4::Down * 1500 * _DeltaTime;
			MoveDir += float4::Left * 80;
			
		
			
		}
		else if (Hp <= -30)
		{
			AnimationRender->ChangeAnimation("WallUp");

			if (StonReset == true)
			{
				MoveDir = { 0,0 };
				Ston->SetPosition({ -20,-300 });
				Ston2->SetPosition({ -10,-100 });
				Ston3->SetPosition({ 10,-200 });
				StonReset = false;
			}
			MoveDir += float4::Down * 1500 * _DeltaTime;
			MoveDir += float4::Left * 150;

		}

		else if (Hp <= 0)
		{
			AnimationRender->ChangeAnimation("WallMiddle");

			Ston->On();
			Ston2->On();
			Ston3->On();
			StonReset = true;
			MoveDir += float4::Down * 1500 * _DeltaTime;
			MoveDir += float4::Left * 100;

		}

	}
	

	if (Hp <= -50)
	{
		Exploision->On();
		WallCollision->Death();

		if (MonsterCheck == false)
		{
			MachineMonster* Monster = GetLevel()->CreateActor<MachineMonster>();
			Monster->SetMove({ 8400,720 });
			MonsterCheck = true; 
		
		}
		if (Exploision->IsAnimationEnd())
		{
			this->Death(); 
		}

	}

	Ston->SetMove(MoveDir * _DeltaTime); 
	Ston2->SetMove(MoveDir * _DeltaTime);
	Ston3->SetMove(MoveDir * _DeltaTime);
	Movecalculation(_DeltaTime); 
}

void Wall::Render(float _Time)
{
	//WallCollision->DebugRender(); 
}

