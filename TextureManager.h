#pragma once
#include<SDL.h>
#include<SDL_image.h>
class TextureManager
{
public:
	
	static SDL_Texture* LoadTexture(const char* FileName);
	static void Draw(SDL_Texture* tex, SDL_Rect scr, SDL_Rect dest);
	static SDL_Surface* tmpSurface;
private:
	
};

