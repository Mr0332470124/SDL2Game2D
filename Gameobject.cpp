#include"Gameobject.h"
#include"Game.h"
#include"TextureManager.h"
#include"Map.h"
#include"iostream"
GameObject::GameObject(const char* texturesheet, int x, int y)
	{
			objTexture = TextureManager::LoadTexture(texturesheet);
			xpos = x;
			ypos = y;
			
	}
void GameObject::update()
	{
			dest.x = xpos;
			dest.y = ypos;
			dest.w = 32;
			dest.h = 32;
	}
void GameObject::render()
	{
		SDL_RenderCopy(Game::renderer, objTexture,NULL,&dest );
	}
void GameObject::handleEvent()
{
	if(SDL_PollEvent(&Game::event))
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_d: 
			this->xpos+=4;
			std::cout << xpos << " " << ypos << std::endl;
					 break;
		case SDLK_a: 
			this->xpos-=4;
			std::cout << xpos << " " << ypos << std::endl;
					 break;
		case SDLK_w: 
			this->ypos-=4;
			std::cout << xpos << " " << ypos << std::endl;
					 break;
		case SDLK_s:
			this->ypos+=4;
			std::cout << xpos << " " << ypos << std::endl;
					break;
		default:
			break;
		}
	}
}