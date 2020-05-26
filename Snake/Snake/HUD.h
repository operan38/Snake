#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"
#include "GameState.h"
#include "Text.h"

class HUD
{
   public:
	  HUD(AppResources* pAppResources, GameState* pGameState);
	  ~HUD();
	  void Draw(sf::RenderWindow &window);
	  void Update(float TimeSec);
	  void SetHUDColor(int FieldID);
	  void Reset();
   private:
	   void TimerLvL(float TimeSec);
	   void CreateControls();
	   void ClearControls();
	   float TimerSec;
	   int TimerMin;
	   sf::Sprite sprScore,sprTimer;
	   sf::String ScoreStr, TimerLvlStr;
	   std::vector<Text*> text;
	   std::vector<Text*>::iterator itText;
	   sf::Color colorType;
	   AppResources* appResources;
	   GameState* gameState;
};