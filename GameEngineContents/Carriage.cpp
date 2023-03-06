#include "Carriage.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Player.h"
#include "RunMonster.h"
#include "MiniBoss.h"
#include "BulletEffect.h"

Carriage* Carriage::carriage;
Carriage::Carriage()
{

}

Carriage::~Carriage()
{

}
void Carriage::Start()
{
	carriage = this; 

	{
		AnimationRender = CreateRender(MetalSlugOrder::Carriage);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Carriage",  .ImageName = "Carriage.bmp", .Start = 0, .End = 11, .InterTime = 0.1f,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "CarriageDestory",  .ImageName = "CarriageDestory.bmp", .Start = 0, .End = 5, .InterTime = 0.1f ,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "CarriageMove",  .ImageName = "CarriageMove.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
	}

	{
		Exploision = CreateRender(MetalSlugOrder::Exploision2);
		Exploision->SetScale({ 1200,1200 });
		Exploision->SetPosition({ -80,-120 });
		Exploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });
	}

	Exploision->ChangeAnimation("Exploision"); 
	Exploision->Off(); 


	ChangeState(CarriageState::IDLE); 

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetScale({ 400,600 });
	}


}






void Carriage::Movecalculation(float _DeltaTime)
{
	if (Hp <= 0)
	{
		return;
	}


	MoveDir += float4::Down * 1500.0f * _DeltaTime;

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
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;





	if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0))))
	{
		

		Check = false;
	}




	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0))))
			{
				continue;
			}

			if (50.0f <= abs(MoveDir.y))
			{
				if (0 > MoveDir.y)
				{
					MoveDir.y = -100.0f;
				}
				else
				{
					MoveDir.y = 0.0f;
				}
			}
			Check = true;
			break;
		}
	}

	SetMove(MoveDir * _DeltaTime);


}

void Carriage::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName);
}




void Carriage::Update(float _DeltaTime)
{

	if (MonsterCollision == nullptr)
	{
		
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetScale({ 400,600 });
		
	}

	if (nullptr != MonsterCollision && StateValue == CarriageState::STOP)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			Hp--;
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				

				ColActor->Death();
			}
					
		}

		
	}
	if (nullptr != MonsterCollision && StateValue == CarriageState::STOP)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Boomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			Hp -= 5;
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();
				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				Effect->BoobBulletCheck = true; 

				ColActor->Death();
			}
			
			

		}


	}








	if (Hp <= 0)
	{
		//MonsterCollision->Death();
		Exploision->On();
		ChangeState(CarriageState::DEATH);
	}



	if (Hp > 0 && StateValue == CarriageState::STOP)
	{
		if (MiniBoss::miniboss->GetAttackCheck() == true)
		{
			Time += GameEngineTime::GlobalTime.GetFloatDeltaTime();
			if (Time > 3)
			{
				RunMonster* Actor = GetLevel()->CreateActor<RunMonster>();
				Actor->SetMove({ 4900,600 });
				Actor->SetCarriageMonster(true);
				Time = 0;
			}
		}
	}

	if (Player::MainPlayer->GetCameraMoveCheck().x > Player::MainPlayer->GetPos().x && MoveCamera == false)
	{
		if (Hp <= 0)
		{
			Player::MainPlayer->SetCameraCheck(true);
			Player::MainPlayer->SetPosCheck(Player::MainPlayer->GetCameraMoveCheck());
			MoveCamera = true;
		}
	}

	else if (Hp <= 0 && MoveCamera == false)
	{

		float4 b = float4::Right * 1000 * _DeltaTime;

		GetLevel()->SetCameraMove(b);

		if (GetLevel()->GetCameraPos().x > Player::MainPlayer->GetPos().x - 150)
		{

			Player::MainPlayer->SetCameraCheck(true);
			Player::MainPlayer->SetPosCheck(Player::MainPlayer->GetPos());
			MoveCamera = true;
		}

	}

	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}

void Carriage::Render(float _Time)
{
	//MonsterCollision->DebugRender();

}
