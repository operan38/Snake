#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"
#include "GameState.h"

class Field
{
   public:
	  Field(AppResources *pAppResources, GameState *pGameState);
	  ~Field();
	  void Draw(sf::RenderWindow &window);
	  void Reset();
   private:
	   sf::Sprite sprField,sprObj,sprFallingObj;
	   int ObjX[45],ObjY[45];
	   int FallingObjX[30],FallingObjY[30];
	   int ObjCount,FallingObjCount;
	   void RandomPosition();
	   AppResources* appResources;
	   GameState* gameState;
};