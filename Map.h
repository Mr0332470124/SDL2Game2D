#pragma once
#include<SDL.h>
#include<SDL_image.h>
class MAP
{
public:
	static int lvl1[20][25];
	MAP();
	void LoadMap(int arr[20][25]);
	void DrawMap();
private:
	SDL_Rect scrR, destR;
	SDL_Texture* Dirt, * Glass,* Water;
	int map[20][25];
};

