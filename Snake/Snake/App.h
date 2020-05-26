#pragma once
#include <SFML\Graphics.hpp>
#include "AppState.h"
#include "AppResources.h"
#include "Menu.h"
#include "Game.h"

class App
{
   public:
	   App();
	   ~App();
	   bool Init();
	   void Loop();
	   static bool isAppStateChange;
   private:
	   sf::RenderWindow window;
	   sf::Event e;
	   sf::Clock clock;
	   sf::Clock clockSec;
	   int WINDOW_WIDTH,WINDOW_HEIGHT;
	   sf::String WINDOW_TITLE;
	   int APP_STATE;
	   bool isDEBUG;
	   int frame,avgFPS;
	   float TimeSec;
	   AppState* appState;
	   AppResources* appResources;
	   void setAppState(AppState *pAppState);
};