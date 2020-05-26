#pragma once
#include "App.h"
#include "AppState.h"
#include "AppResources.h"
#include "GameState.h"
#include "Field.h"
#include "Player.h"
#include "Food.h"
#include "HUD.h"

class Game : public AppState
{
   public:
	  Game(AppResources* pAppResources);
	  ~Game();
	  void Draw(sf::RenderWindow &window);
	  void Update(float TimeSec);
	  void Event(sf::Event e, sf::RenderWindow &window);
	  sf::String GetGameState(){return gameState->GetGameSate();}
   private:
	   void Reset();
	   AppResources* appResources;
	   GameState* gameState;
	   Field* field;
	   Player* player;
	   Food* food;
	   HUD* hud;
};