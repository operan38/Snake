#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"
#include "GameState.h"
#include "Food.h"

class Player
{
   public:
	  Player(AppResources* pAppResources, GameState* pGameState, Food* pFood);
	  ~Player();
	  void Draw(sf::RenderWindow &window);
	  void Update(float TimeSec);
	  void Event(sf::Event e);
	  void Reset();
   private:
	  float delay;
	  float delayMin;
	  int x[901],y[901];
	  int w,h;
	  int dir,length;
	  int speed;
	  void Eat();
	  void CheckFoodSpawn();
	  void setSnake();
	  sf::Sprite sprHead;
	  sf::Sprite sprBody;
      AppResources* appResources;
	  GameState* gameState;
	  Food* food;
};