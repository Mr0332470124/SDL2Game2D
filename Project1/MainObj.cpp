#include"MainObj.h"

MainObj::MainObj()
{
	ObjTex = NULL;
	des.w = WidthMainObj; des.h = HeightMainObj;
	des.x = 0; des.y = 0;
	lvl = lvl0;
}

MainObj::~MainObj()
{
}

void MainObj::HandleEvent()
{
	srand(NULL);
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			break;
		case SDLK_DOWN:
			break;
		case SDLK_LEFT:
			break;
		case SDLK_RIGHT:
			break;
		default:
			break;
		}
	}
	else
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
			break;
			default:
				break;
			}
		}
		else
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.type == SDL_BUTTON_LEFT)
				{

				}
			}
			else
				if (event.type == SDL_MOUSEBUTTONUP)
				{

				}
}

void MainObj::update()
{
	switch (lvl)
	{
	case lvl0:
		ObjTex = TextureManager::LoadTexture("pic/lvl0.png");
		break;
	case lvl1:
		ObjTex = TextureManager::LoadTexture("pic/lvl1.png");
		break;
	case lvl2:
		ObjTex = TextureManager::LoadTexture("pic/lvl2.png");
		break;
	case lvl3:
		ObjTex = TextureManager::LoadTexture("pic/lvl3.png");
		break;
	case lvl4:
		ObjTex = TextureManager::LoadTexture("pic/lvl4.png");
		break;
	case lvl5:
	{	
		ObjTex = TextureManager::LoadTexture("pic/lvl0.png");
		lvl = lvl0;
		//blastup
		Blast* blastup = new Blast();
		blastup->SetBlastUpTex();
		blastup->Set_Ismove(true);
		blastup->SetRectDes(des.x +25, des.y - BlastHeight* 1 / 2);
		blastup->SetvY(3);
		BlastListUp.push_back(blastup);
		//blastdown
		Blast* blastdown = new Blast();
		blastdown->SetBlastDownTex();
		blastdown->Set_Ismove(true);
		blastdown->SetRectDes(des.x + 25, des.y + HeightMainObj -BlastHeight*1/2 );
		blastdown->SetvY(3);
		BlastListDown.push_back(blastdown);
		//blastright
		Blast* blastright = new Blast();
		blastright->SetBlastRightTex();
		blastright->Set_Ismove(true);
		blastright->SetRectDes(des.x +  WidthMainObj-BlastHeight*1/2, des.y + 25 );
		blastright->SetvX(3);
		BlastListRight.push_back(blastright);
		//blastleft
		Blast* blastleft = new Blast();
		blastleft->SetBlastLeftTex();
		blastleft->Set_Ismove(true);
		blastleft->SetRectDes(des.x - BlastHeight * 1 / 2, des.y + 25);
		blastleft->SetvX(3);
		BlastListLeft.push_back(blastleft);

	}
	break;
	default:
		break;
	}
}

void MainObj::render()
{
	SDL_RenderCopy(Game::renderer, ObjTex, NULL, &des);
}

void MainObj::MakeBlast(MainObj* waterlist)
{
	for (int i = 0; i < BlastListDown.size(); i++)
	{
		Blast* blastD = BlastListDown.at(i);
		if (blastD != NULL)
		{
			if (blastD->Get_Ismove())
			{
				blastD->MoveDown(Screen_Width*2/3, Screen_Height);
				blastD->render();
				MainObj* water= (waterlist + (blastD->getX() + BlastWidth / 2) / WidthMainObj + (blastD->getY() + BlastHeight / 2) / HeightMainObj * columnmax);
				if (water->GetLvl() != 0)
				{
					//if (blastD->getX() + BlastWidth / 2 > water->getX() + 1 / 3 * WidthMainObj
					//	and blastD->getX() + BlastWidth / 2 < water->getX() + 2 / 3 * WidthMainObj
					//	and blastD->getY() + BlastHeight / 2 > water->getY() + 1 / 3 * HeightMainObj
					//	and blastD->getY() + BlastHeight / 2 < water->getY() + 2 / 3 * HeightMainObj)
					{
						(waterlist + (blastD->getX() + BlastWidth / 2) / WidthMainObj + (blastD->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->SetLvl(water->GetLvl() + 1);
						(waterlist + (blastD->getX() + BlastWidth / 2) / WidthMainObj + (blastD->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->update();
						blastD->Set_Ismove(false);
					}
				}
			}
				else
				{
					if (blastD != NULL)
					{
						BlastListDown.erase(BlastListDown.begin() + i);
						delete blastD;
						blastD = NULL;
					}
				}
		}
	}
	for (int i = 0; i < BlastListUp.size(); i++)
	{
		Blast* blastup = BlastListUp.at(i);
		if (blastup != NULL)
		{
			if (blastup->Get_Ismove())
			{
				blastup->MoveUp(Screen_Width*2/3, Screen_Height);
				blastup->render();
				MainObj* water = (waterlist + (blastup->getX() + BlastWidth / 2) / WidthMainObj + (blastup->getY() + BlastHeight / 2) / HeightMainObj * columnmax);
				if (water->GetLvl() != 0)
				{
					//if (blastD->getX() + BlastWidth / 2 > water->getX() + 1 / 3 * WidthMainObj
					//	and blastD->getX() + BlastWidth / 2 < water->getX() + 2 / 3 * WidthMainObj
					//	and blastD->getY() + BlastHeight / 2 > water->getY() + 1 / 3 * HeightMainObj
					//	and blastD->getY() + BlastHeight / 2 < water->getY() + 2 / 3 * HeightMainObj)
					{
						(waterlist + (blastup->getX() + BlastWidth / 2) / WidthMainObj + (blastup->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->SetLvl(water->GetLvl() + 1);
						(waterlist + (blastup->getX() + BlastWidth / 2) / WidthMainObj + (blastup->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->update();
						blastup->Set_Ismove(false);
					}
				}
			}
			else
			{
				if (blastup != NULL)
				{
					BlastListUp.erase(BlastListUp.begin() + i);
					delete blastup;
					blastup= NULL;
				}
			}
		}
	}
	for (int i = 0; i < BlastListRight.size(); i++)
	{
		Blast* blastright = BlastListRight.at(i);
		if (blastright != NULL)
		{
			if (blastright->Get_Ismove())
			{
				blastright->MoveRight(Screen_Width*2/3, Screen_Height);
				blastright->render();
				MainObj* water = (waterlist + (blastright->getX() + BlastWidth / 2) / WidthMainObj + (blastright->getY() + BlastHeight / 2) / HeightMainObj * columnmax);
				if (water->GetLvl() != 0)
				{
					//if (blastD->getX() + BlastWidth / 2 > water->getX() + 1 / 3 * WidthMainObj
					//	and blastD->getX() + BlastWidth / 2 < water->getX() + 2 / 3 * WidthMainObj
					//	and blastD->getY() + BlastHeight / 2 > water->getY() + 1 / 3 * HeightMainObj
					//	and blastD->getY() + BlastHeight / 2 < water->getY() + 2 / 3 * HeightMainObj)
					{
						(waterlist + (blastright->getX() + BlastWidth / 2) / WidthMainObj + (blastright->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->SetLvl(water->GetLvl() + 1);
						(waterlist + (blastright->getX() + BlastWidth / 2) / WidthMainObj + (blastright->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->update();
						blastright->Set_Ismove(false);
					}
				}
			}
			else
			{
				if (blastright != NULL)
				{
					BlastListRight.erase(BlastListRight.begin() + i);
					delete blastright;
					blastright = NULL;
				}
			}
		}
	}
	for (int i = 0; i < BlastListLeft.size(); i++)
	{
		Blast* blastleft = BlastListLeft.at(i);
		if (blastleft != NULL)
		{
			if (blastleft->Get_Ismove())
			{
				blastleft->MoveLeft(Screen_Width*2/3, Screen_Height);
				blastleft->render();
				MainObj* water = (waterlist + (blastleft->getX() + BlastWidth / 2) / WidthMainObj + (blastleft->getY() + BlastHeight / 2) / HeightMainObj * columnmax);
				if (water->GetLvl() != 0)
				{
					//if (blastD->getX() + BlastWidth / 2 > water->getX() + 1 / 3 * WidthMainObj
					//	and blastD->getX() + BlastWidth / 2 < water->getX() + 2 / 3 * WidthMainObj
					//	and blastD->getY() + BlastHeight / 2 > water->getY() + 1 / 3 * HeightMainObj
					//	and blastD->getY() + BlastHeight / 2 < water->getY() + 2 / 3 * HeightMainObj)
					{
						(waterlist + (blastleft->getX() + BlastWidth / 2) / WidthMainObj + (blastleft->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->SetLvl(water->GetLvl() + 1);
						(waterlist + (blastleft->getX() + BlastWidth / 2) / WidthMainObj + (blastleft->getY() + BlastHeight / 2) / HeightMainObj * columnmax)->update();
						blastleft->Set_Ismove(false);
					}
				}
			}
			else
			{
				if (blastleft != NULL)
				{
					BlastListLeft.erase(BlastListLeft.begin() + i);
					delete blastleft;
					blastleft = NULL;
				}
			}
		}
	}
}
