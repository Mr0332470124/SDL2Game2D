#pragma once
#include<SDL.h>
#include<SDL_image.h>
class Game
{
public:
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvent();
	void update();
	void clean();
	bool running(){ return isRunning; }
	void render();

	static SDL_Renderer* renderer;
	static SDL_Event event;
private:
	bool isRunning;
	SDL_Window* window;
};
