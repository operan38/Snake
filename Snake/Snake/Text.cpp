#include "Text.h"

Text::Text(AppResources* pAppResources, sf::String pStr, float pX, float pY, int pSize, sf::Color pColor, int pASpeed)
{
	appResources = pAppResources;
	str = pStr;
	x = pX; y = pY;
	size = pSize; color = pColor;
	text.setFont(appResources->font);
	text.setString(str);
	text.setPosition(x,y);
	text.setCharacterSize(size);
	aColor.r = color.r;
	aColor.g = color.g;
	aColor.b = color.b;
	aColor.a = 0;
	aSpeed = pASpeed;
	isAnimAlpha = true;
	isAnimMove = false;
	isUpdate = -1;
	text.setColor(aColor);
}

Text::~Text(){}

void Text::draw(sf::RenderWindow &window)
{
	window.draw(text);
}

void Text::update(float TimeSec)
{
	if (isAnimAlpha)
	{
		if (aColor.a < color.a)
		{
			aColor.a+=aSpeed;
		}
		else
		{
			isAnimAlpha = false;
		}
		text.setColor(aColor);
	}
	if (isAnimMove)
	{
		if (mvX < x)
	        mvX += TimeSec*mvSpeed;
        if (x < mvX)
	        mvX -= TimeSec*mvSpeed;
        if (mvY < y)
	        mvY += TimeSec*mvSpeed;
        if (y < mvY)
	        mvY -= TimeSec*mvSpeed;

		text.setPosition(mvX,mvY);
		if (mvX == x && mvY == y){
		    isAnimMove = false;
	    }
	}
}

void Text::updateText(sf::String str)
{
	text.setString(str);
}

void Text::setUpdateText(int isUP)
{
	isUpdate = isUP;
}

void Text::setAnimMove(float pStX, float pStY, float pSpeed)
{
	mvX = pStX;
	mvY = pStY;
	mvSpeed = pSpeed;
	isAnimMove = true;
}