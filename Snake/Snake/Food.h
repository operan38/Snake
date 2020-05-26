#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"

class Food
{
   public:
	  Food(AppResources* pAppResources);
	  ~Food();
	  void Draw(sf::RenderWindow &window);
	  int getW(){return w;}
	  int getH(){return h;}
	  int getX(){return x;}
	  int getY(){return y;}
	  void setX(int pX){x = pX;}
	  void setY(int pY){y = pY;}
	  int getType(){return type;}
	  void RandomApple();
	  void RandomPosition();
   private:
	  sf::Sprite sprite;
	  AppResources* appResources;
	  int w,h;
	  int x,y;
	  int type;
};