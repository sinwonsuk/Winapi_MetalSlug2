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
		AnimationRender->SetScale({ 1000,300 });

	}*/

	{
		GameEngineRender* AnimationRender = CreateRender(1);
		AnimationRender->SetImage("Map12.Bmp");
		AnimationRender->SetPosition({ AnimationRender->GetImage()->GetImageScale().half()});
		AnimationRender->SetScale({12784,800});		
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
