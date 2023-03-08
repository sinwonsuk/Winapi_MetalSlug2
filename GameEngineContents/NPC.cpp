#include "NPC.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "BulletEffect.h"


NPC::NPC()
{

}

NPC::~NPC()
{

}


void NPC::Start()
{

	{
		AnimationRender = CreateRender(MetalSlugOrder::NPC);
		AnimationRender->SetScale({ 600,600 });

		AnimationRender->CreateAnimation({ .AnimationName = "Npc_Idle",  .ImageName = "NpcIdle.bmp", .Start = 0, .End = 4, .InterTime = 0.2f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Npc_Move",  .ImageName = "LeftNpcMove.bmp", .Start = 0, .End = 11, .InterTime = 0.15f });
		AnimationRender->CreateAnimation({ .AnimationName = "Npc_MovePre",  .ImageName = "NpcIdle.bmp", .Start = 5, .End = 8, .InterTime = 0.15f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Npc_Move",  .ImageName = "RightNpcMove.bmp", .Start = 0, .End = 11, .InterTime = 0.15f });

		AnimationRender->CreateAnimation({ .AnimationName = "Npc_Death",  .ImageName = "NpcDeath.bmp", .Start = 0, .End = 7, .InterTime = 0.1f });
		


		AnimationRender->CreateAnimation({ .AnimationName = "Npc_Collision",  .ImageName = "NpcCollision.bmp", .Start = 0, .End = 10, .InterTime = 0.1f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Npc_CollisionAfter",  .ImageName = "NpcCollisionAfter.bmp", .Start = 0, .End = 13, .InterTime = 0.1f, .Loop = false });
	
		AnimationRender->CreateAnimation({ .AnimationName = "Npc_Bind",  .ImageName = "NpcBind.bmp", .Start = 0, .End = 8, .InterTime = 0.2f, .Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Npc_Down",  .ImageName = "NpcDown.bmp", .Start = 0, .End = 4, .InterTime = 0.1f, .Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Npc_MoveDown",  .ImageName = "NpcMoveDown.bmp", .Start = 0, .End = 13, .InterTime = 0.1f, .Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "Npc_BindMovePre",  .ImageName = "NpcBindMovePre.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = true });
	}
	
	{
		NpcCollision = CreateCollision(MetalSlugOrder::NPC);
		NpcCollision->SetScale({ 100, 100 });
		NpcCollision->SetPosition({ 0,-50 });
	}
	
	ChangeState(NpcState::IDLE);

}




void NPC::Movecalculation(float _DeltaTime)
{
	MoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (50.0f <= abs(MoveDir.x) && StateValue != NpcState::DEATH)
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -50.0f;
		}
		else
		{
			MoveDir.x = 50.0f;
		}
	}

	if (450.0f <= abs(MoveDir.x) && StateValue == NpcState::DEATH)
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -450.0f;
		}
		else
		{
			MoveDir.x = 450.0f;
		}
	}




	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;


	


	if( (RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)) )&& StateValue != NpcState::MOVEDOWN)
	{
		if (StateValue == NpcState::DOWN)
		{
			ChangeState(NpcState::LEFTMOVE);			
		}
		
		Check = false;
	}

	


	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0)) )&& StateValue != NpcState::MOVEDOWN)
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

void NPC::DirCheck(const std::string_view& _AnimationName)
{
	

	AnimationRender->ChangeAnimation(_AnimationName.data());



}

void NPC::Update(float _DeltaTime)
{



	if (death == true)
	{
		DeathCheck += GameEngineTime::GlobalTime.GetFloatDeltaTime();
	}
	


	if (DeathCheck > 1)
	{
		this->Death();
		death = false;

	}


	if (nullptr != NpcCollision && StateValue == NpcState::IDLE)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == NpcCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();

				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				ColActor->Death();

				NpcHit = GameEngineResources::GetInst().SoundPlayToControl("NpcHit.mp3");
				NpcHit.LoopCount(1);
				NpcHit.Volume(1.5f);
			}

			
			ChangeState(NpcState::MOVEPRE);

		}
	}
	if (nullptr != NpcCollision && StateValue == NpcState::BIND)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == NpcCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			for (size_t i = 0; i < collision.size(); i++)
			{
				GameEngineActor* ColActor = collision[i]->GetActor();

				BulletEffect* Effect = GetLevel()->CreateActor<BulletEffect>();
				Effect->SetMove(ColActor->GetPos());
				ColActor->Death();

				NpcHit = GameEngineResources::GetInst().SoundPlayToControl("NpcHit.mp3");
				NpcHit.LoopCount(1);
				NpcHit.Volume(1.5f);

			}
			ChangeState(NpcState::BINDMOVEPRE);

		}
	}

	if (nullptr != NpcCollision && (StateValue == NpcState::LEFTMOVE || StateValue == NpcState::RIGHTMOVE))
	{
		std::vector<GameEngineCollision*> collision;
		if (true == NpcCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{

			ChangeState(NpcState::COLLISION);
			SetPos({ GetPos().x + 50, GetPos().y});

			Thankyou = GameEngineResources::GetInst().SoundPlayToControl("Thankyou.mp3");
			Thankyou.LoopCount(1);
			Thankyou.Volume(1.5f);


		}
	}

	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);

}

void NPC::Render(float _Time)
{

	/*HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);*/
//	NpcCollision->DebugRender();
}


