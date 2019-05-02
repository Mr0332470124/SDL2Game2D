#include "Game.h"
#include"MainObj.h"
#include<time.h>

MainObj* WaterList = new MainObj[rowmax * columnmax];
Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	//bkgr
	bkgr.h = Screen_Height; bkgr.w = Screen_Width; bkgr.x = 0; bkgr.y = 0;
	bkground = TextureManager::LoadTexture("pic/bkground.png");
	//remainingturn
	remturn.h = RemTurn_Height; remturn.w = RemTurn_Width; remturn.x = 800; remturn.y = 0;
	RemainingTurn = TextureManager::LoadTexture("pic/RemainingTurn.png");
	chuc.h = 100; chuc.w = 100; chuc.x = 800 + 100; chuc.y = 200;
	donvi.h = 100; donvi.w = 100; donvi.x = 800 + 200; donvi.y = 200;
	//map
	for (int row = 0; row < rowmax; row++)
	{
		for (int column = 0; column < columnmax; column++)
		{

			WaterList[row * columnmax + column].SetLvl(rand() % 5);
			WaterList[row * columnmax + column].SetRectDes(column* WidthMainObj, row  * HeightMainObj);
			WaterList[row * columnmax + column].update();
		}
	}

}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT and countturn>0)
		{

			MainObj water = WaterList[event.button.x / WidthMainObj + event.button.y / HeightMainObj * columnmax];
			int lvl_ = water.GetLvl();
			if (lvl_!=0)
			{
			countturn -= 1;
			WaterList[event.button.x / WidthMainObj + event.button.y / HeightMainObj * columnmax].SetLvl(lvl_ + 1);
			WaterList[event.button.x / WidthMainObj + event.button.y / HeightMainObj * columnmax].update();
			}
		}
	}
	layhangchuc();
	layhangdonvi();

}

void Game::update()
{
	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, bkground, NULL, &bkgr);
	SDL_RenderCopy(renderer, RemainingTurn, NULL, &remturn);
	SDL_RenderCopy(renderer, chuctex, NULL, &chuc);
	SDL_RenderCopy(renderer, donvitex, NULL, &donvi);
	for (int row = 0; row < rowmax; row++)
	{
		for (int column = 0; column < columnmax; column++)
		{	
			WaterList[row * columnmax + column].render();
		}
	}
	for (int row = 0; row < rowmax; row++)
	{
		for (int column = 0; column < columnmax; column++)
		{
			WaterList[row * columnmax + column].MakeBlast(WaterList);
		}
	}
	
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::layhangchuc()
{
	
	switch (countturn/10)
	{
	case 0:
		chuctex = TextureManager::LoadTexture("pic/khong.png");
		break;
	case 1:
		chuctex = TextureManager::LoadTexture("pic/mot.png");
		break;
	case 2:
		chuctex = TextureManager::LoadTexture("pic/hai.png");
		break;
	case 3:
		donvitex = TextureManager::LoadTexture("pic/ba.png");
		break;
	case 4:
		donvitex = TextureManager::LoadTexture("pic/bon.png");
		break;
	case 5:
		donvitex = TextureManager::LoadTexture("pic/nam.png");
		break;
	case 6:
		donvitex = TextureManager::LoadTexture("pic/sau.png");
		break;
	case 7:
		donvitex = TextureManager::LoadTexture("pic/bay.png");
		break;
	case 8:
		donvitex = TextureManager::LoadTexture("pic/tam.png");
		break;
	case 9:
		donvitex = TextureManager::LoadTexture("pic/chin.png");
		break;
	default:
		break;
	}
}

void Game::layhangdonvi()
{
	switch (countturn % 10)
	{
	case 0:
		donvitex = TextureManager::LoadTexture("pic/khong.png");
		break;
	case 1:
		donvitex = TextureManager::LoadTexture("pic/mot.png");
		break;
	case 2:
		donvitex = TextureManager::LoadTexture("pic/hai.png");
		break;
	case 3:
		donvitex = TextureManager::LoadTexture("pic/ba.png");
		break;
	case 4:
		donvitex = TextureManager::LoadTexture("pic/bon.png");
		break;
	case 5:
		donvitex = TextureManager::LoadTexture("pic/nam.png");
		break;
	case 6:
		donvitex = TextureManager::LoadTexture("pic/sau.png");
		break;
	case 7:
		donvitex = TextureManager::LoadTexture("pic/bay.png");
		break;
	case 8:
		donvitex = TextureManager::LoadTexture("pic/tam.png");
		break;
	case 9:
		donvitex = TextureManager::LoadTexture("pic/chin.png");
		break;
	default:
		break;
	}
}
