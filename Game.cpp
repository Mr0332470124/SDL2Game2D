#include<SDL.h>
#include<SDL_image.h>
#include<math.h>
#include"Gameobject.h"
#include"Map.h"
#include"TextureManager.h"
#include"Game.h"
#include"Menu.h"
MAP* map;
GameObject* player,*enemy;
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
//Menu* menu;
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
		}

		isRunning = true;
	}
	//menu = new Menu();
	//if (menu->isOpen())
			map = new MAP();
			player = new GameObject("pic/bkground1.png", 0, 0);
			enemy = new GameObject("pic/bkground2.png", 100, 100);
}
void Game::handleEvent()
{
	player->handleEvent();
	switch (Game::event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::update()
{
	map->LoadMap(MAP::lvl1);
	player->update();
	enemy->update();
	
}
void Game::render()
{
	
	SDL_RenderClear(renderer);
	//menu->render();
	map->DrawMap();
	player->render();
	enemy->render();
	SDL_RenderPresent(renderer);
	
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

