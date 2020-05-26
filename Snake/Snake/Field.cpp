#include "Field.h"

Field::Field(AppResources *pAppResources, GameState *pGameState)
{
	appResources = pAppResources;
	gameState = pGameState;
	ObjCount = 0;
	FallingObjCount = 0;
	sprField.setTexture(appResources->tField);
	sprObj.setTexture(appResources->tObj);
	switch (appResources->FieldID)
	{
	    case 0:
			 sprField.setTextureRect(sf::IntRect(0,0,64,64));
			 sprObj.setTextureRect(sf::IntRect(0,0,32,32));
			 ObjCount = 30;
		break;
		case 1:
			sprField.setTextureRect(sf::IntRect(64,0,64,64));
			sprObj.setTextureRect(sf::IntRect(32,0,32,32));
			ObjCount = 10;
		break;
		case 2:
			sprField.setTextureRect(sf::IntRect(128,0,64,64));
			sprObj.setTextureRect(sf::IntRect(64,0,32,32));
			sprFallingObj.setTexture(appResources->tFallingObj);
			ObjCount = 10;
			FallingObjCount = 15;
		break;
	    case 3:
			sprField.setTextureRect(sf::IntRect(192,0,64,64));
			sprObj.setTextureRect(sf::IntRect(96,0,32,32));
			ObjCount = 40;
		break;
	}
	RandomPosition();
}

Field::~Field(){}

void Field::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 13*64; i += 64)
	{
	   for (int j = 0; j < 10*64; j += 64){
		    sprField.setPosition((float)i,(float)j); 
		    window.draw(sprField);
	   }
	}
	for (int i = 0; i < ObjCount; i++)
	{
	     sprObj.setPosition((float)ObjX[i], (float)ObjY[i]);
	     window.draw(sprObj);
	}
	if (FallingObjCount != 0)
	{
	   for (int i = 0; i < FallingObjCount; i++)
	   {
		  if (gameState->state == "Standard" || gameState->state == "GameOver" || gameState->state == "GameWin")
		      FallingObjY[i] += 1;
		  if (FallingObjY[i] >= 600){
	          FallingObjX[i] = rand() % 700 + 10;
	          FallingObjY[i] = rand() % 300 + 10;
		      FallingObjY[i] *= -2;
		  }
	      sprFallingObj.setPosition((float)FallingObjX[i], (float)FallingObjY[i]+1);
	      window.draw(sprFallingObj);
	   }
	}
}

void Field::RandomPosition()
{
	for (int i = 0; i < ObjCount; i++)
	{
	    ObjX[i] = rand() % 700 + 50;
	    ObjY[i] = rand() % 460 + 60;
	}
	if (FallingObjCount != 0)
	{
	   for (int i = 0; i < FallingObjCount; i++)
	   {
	      FallingObjX[i] = rand() % 700 + 10;
	      FallingObjY[i] = rand() % 300 + 10;
		  FallingObjY[i] *= -2;
	   }
	}
}

void Field::Reset()
{
	RandomPosition();
}