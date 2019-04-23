#pragma once
#include<SDL.h>
#include<SDL_image.h>
class GameObject
{
public:
	
	GameObject(const char* texturesheet, int x, int y);
	void update();
	void render();
	void handleEvent();

private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect   scr, dest;
	
};
