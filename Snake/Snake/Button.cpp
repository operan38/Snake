#include "Button.h"

Button::Button(AppResources* pAppResources, sf::String pStr, float pX, float pY, float pW, float pH, int pSize, sf::Color pColor, int pAWSpeed)
{
	appResources = pAppResources;
	str = pStr;
	x = pX; y = pY;
	w = pW; h = pH;
	size = pSize; color = pColor;
	text.setFont(appResources->font);
	text.setString(str);
	text.setPosition(x+10,y);
	text.setCharacterSize(size);
	text.setColor(color);
	sprite.setTexture(appResources->tButton);
	sprite.setPosition(x,y);
	style[0] = 0; style[1] = 200; style[2] = 400;
	isHover = false;
	isSelected = false;
	isAnimWidth = true;
	aW = 0;
	awSpeed = pAWSpeed;
	sprite.setTextureRect(sf::IntRect(style[appResources->ButtonID],0,(int)aW,(int)h));
}

Button::~Button(){}

void Button::selected()
{
	if (isSelected)
	{
		text.setColor(sf::Color(210,16,16,255));
	}
}

void Button::hover()
{
	if (isHover == true)
	{
	   text.setColor(sf::Color::Yellow);
	   sprite.setTextureRect(sf::IntRect(style[appResources->ButtonID],66,(int)aW,(int)h));
	}
	else if (isHover == false)
	{
	   text.setColor(color);
	   sprite.setTextureRect(sf::IntRect(style[appResources->ButtonID],0,(int)aW,(int)h));
	}
}
void Button::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	window.draw(text);
}

void Button::update(float TimeSec)
{
	if (isAnimWidth)
	{
        if (aW <= w)
	    {
		    aW+=TimeSec*awSpeed;
	    }
		else
		{
			isAnimWidth = false;
			aW = w;
		}
	    sprite.setTextureRect(sf::IntRect(style[appResources->ButtonID],0,(int)aW,(int)h));
	}
}