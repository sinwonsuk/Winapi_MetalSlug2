#include "Map.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
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
		GameEngineRender* AnimationRender = CreateRender();
		AnimationRender->SetImage("Map11.Bmp");
		AnimationRender->SetPosition({ AnimationRender->GetImage()->GetImageScale().half()});
		AnimationRender->SetScale({12784,800});		
	}
	/*{
		GameEngineRender* AnimationRender = CreateRender();
		AnimationRender->SetImage("Map12.Bmp");
		AnimationRender->SetPosition({ AnimationRender->GetImage()->GetImageScale().half() });
		AnimationRender->SetScale({ 12784,1000 });
	}*/
	{
		DestoryBase = CreateRender(0);
		DestoryBase->SetImage("DestoryBase.Bmp");
		DestoryBase->SetPosition({ 6600,500 });
		DestoryBase->SetScale({1200,430});		
	}


		/*{
		GameEngineRender* AnimationRender = CreateRender(0);

		AnimationRender->SetPosition({ 1200,430 });
		AnimationRender->SetScale({ 2400,859 });
		AnimationRender->SetImage("Stage02.Bmp");
	     }*/

}

void Map::Update(float _DeltaTime)
{
	
}
