#include"Map.h"
#include"Game.h"
#include"TextureManager.h"
int MAP::lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,0,0,1,0,0,1,0,0,0,0,1,0,2,0,1,0,2,0,1,0,0,0},
	{0,0,1,0,0,0,0,0,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,0,0,3,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,0,0,0,2,0,1,0,3,3,0,0,0,0,0,2,0,0,0,0,2,0,2},
	{0,0,0,0,1,0,0,0,1,0,3,0,0,0,0,0,0,0,2,0,1,0,0,2,0},
	{0,0,2,0,1,0,1,2,1,0,3,0,0,0,0,0,0,0,2,1,0,0,0,0,0},
	{0,2,0,0,1,0,0,0,1,0,3,0,0,0,0,0,0,0,2,0,0,1,0,0,0},
	{0,2,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,0,0,1,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0},
	{0,0,1,0,0,1,0,0,1,1,1,1,0,0,2,2,2,2,2,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},
	{0,0,1,0,2,0,1,0,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},
	{0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},
	{0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},
	{0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},

};

MAP::MAP()
{
	Dirt = TextureManager::LoadTexture("pic/dirt.png");
	Water = TextureManager::LoadTexture("pic/water.png");
	Glass = TextureManager::LoadTexture("pic/glass.png");
	scrR.x = scrR.y = 0;
	scrR.h = destR.h = scrR.w = destR.w = 32;
	scrR.x = destR.y = 0;
}
void MAP::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			destR.x = column * 32;
			destR.y = row * 32;

			type = map[row][column];
			switch (type)
			{
			case 1:
				TextureManager::Draw(Water, scrR, destR);
				break;
			case 2:
				TextureManager::Draw(Dirt, scrR, destR);
				break;
			case 3:
				TextureManager::Draw(Glass, scrR, destR);
				break;
			default:
				break;
			}
		}

	}
}
void MAP::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column]=arr[row][column];
		}

	}
}