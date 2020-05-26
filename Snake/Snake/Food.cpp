#include "Food.h"

Food::Food(AppResources* pAppResources)
{
	appResources = pAppResources;
	sprite.setTexture(appResources->tFood);
	w = 14; h = 14;
	x = 50; y = 50;
	type = 0;
	RandomApple();
	RandomPosition();
}

Food::~Food(){}

void Food::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Food::RandomPosition()
{
	sprite.setPosition((float)x,(float)y);
}

void Food::RandomApple()
{
	type = rand() % 2 + 1;
	if (type == 1)
		sprite.setTextureRect(sf::IntRect(0,0,w,h));
	else if (type == 2)
	    sprite.setTextureRect(sf::IntRect(14,0,w,h));
}