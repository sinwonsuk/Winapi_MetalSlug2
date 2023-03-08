#include "Map.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
Map::Map()
{
}

Map::~Map()
{
}


void Map::Start()
{
	
	
	/*{
		GameEngineRender* AnimationRender = CreateRender(0);
		AnimationRender->SetImage("BackGround1.Bmp");
		AnimationRender->SetPosition({ AnimationRender->GetImage()->GetImageScale().half() });
		AnimationRender->Set
		
		
		({ 1000,300 });

	}*/

	{
		DebugActor = CreateRender();
		DebugActor->SetImage("Map11.Bmp");
		DebugActor->SetPosition({ DebugActor->GetImage()->GetImageScale().half()});
		DebugActor->SetScale({12784,800});		
		DebugActor->Off();
	}

	/*{
		GameEngineRender* AnimationRender = CreateRender();
		AnimationRender->SetImage("Map10.Bmp");
		AnimationRender->SetPosition({ AnimationRender->GetImage()->GetImageScale().half() });
		AnimationRender->SetScale({ 12784,800 });
	}*/

	{
		Actor = CreateRender();
		Actor->SetImage("Map12.Bmp");
		Actor->SetPosition({ Actor->GetImage()->GetImageScale().half() });
		Actor->SetScale({ 12784,1000 });
	}

	{
		DestoryBase = CreateRender(0);
		DestoryBase->SetImage("DestoryBase.Bmp");
		DestoryBase->SetPosition({ 6600,500 });
		DestoryBase->SetScale({1200,430});		
	}

	if (false == GameEngineInput::IsKey("DegBug"))
	{

	
		GameEngineInput::CreateKey("DegBug", '3');
		
		
	}
		

}

void Map::Update(float _DeltaTime)
{
	if (Debug == false)
	{
		if (GameEngineInput::IsDown("DegBug"))
		{
			DebugActor->On();
			Actor->Off();
		}
		Debug = true;
	}
	else if (Debug == true)
	{
		if (GameEngineInput::IsDown("DegBug"))
		{
			DebugActor->Off();
			Actor->On();
		}
		Debug = false;
	}




}
