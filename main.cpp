#include"Game.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
Game *game = NULL;
SDL_Event events;
int main(int argc, char*argv[])
{
	const int FPS=60;
	const int FrameDelay = 1000 / FPS;
	Uint32 FrameStart;
	int FrameTime;
	
	game = new Game();
	game->init("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	
	while (game->running())
	{
		FrameStart = SDL_GetTicks();
		game->handleEvent();
		game->update();
		game->render();
		FrameTime = SDL_GetTicks() - FrameStart;
		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
	}
	game->clean();
	return 0;
}