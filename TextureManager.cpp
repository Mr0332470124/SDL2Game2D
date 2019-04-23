#include"TextureManager.h"
#include"Game.h"

SDL_Texture* TextureManager::LoadTexture(const char*texture)
{	
	SDL_Surface* tmpSurface = IMG_Load(texture);
	//SDL_FillRect(tmpSurface, NULL, 0xffaaff);
	SDL_SetColorKey(tmpSurface,  NULL, SDL_MapRGB(tmpSurface->format, 0xff, 0x00, 0xff));
	
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}
void TextureManager::Draw(SDL_Texture* tex,SDL_Rect scrR,SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, NULL, &dest);

}