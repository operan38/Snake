#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"

class Button
{
   public:
	  Button(AppResources* pAppResources, sf::String pStr, float pX, float pY, float pW, float pH, int pSize, sf::Color pColor, int pAWSpeed);
	  ~Button();
	  void draw(sf::RenderWindow &window);
	  void update(float TimeSec);
	  void hover();
	  void selected();
	  bool isSelected;
	  bool isHover;
	  float x,y,w,h,aW;
   private:
	   bool isAnimWidth;
	   int awSpeed;
	   int size;
	   int style[3];
	   sf::Color color;
	   sf::Sprite sprite;
	   sf::String str;
	   sf::Text text;
	   AppResources* appResources;
};