#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"

class Text
{
   public:
	  Text(AppResources* pAppResources, sf::String pStr, float pX, float pY, int pSize, sf::Color pColor, int pASpeed);
	  ~Text();
	  void draw(sf::RenderWindow &window);
	  void update(float TimeSec);
	  void updateText(sf::String str);
	  int getUpdateText(){return isUpdate;}
	  void setUpdateText(int isUP);
	  void setAnimMove(float pStX, float pStY, float pSpeed);
   private:
	  float x,y;
	  int aSpeed;
	  int size;
	  float mvX,mvY,mvSpeed;
	  bool isAnimAlpha;
	  bool isAnimMove;
	  int isUpdate;
	  sf::Color color;
	  sf::Color aColor;
	  sf::String str;
	  sf::Text text;
	  AppResources* appResources;
};