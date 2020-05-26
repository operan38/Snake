#pragma once
#include <SFML\Graphics.hpp>
#include "AppResources.h"

class AppState
{
   public:
	   AppState(){}
	   AppState(AppResources* pAppResources){}
	   virtual ~AppState(){}
	   virtual void Draw(sf::RenderWindow &window){}
	   virtual void Update(float TimeSec){}
	   virtual void Event(sf::Event e, sf::RenderWindow &window){}
	   virtual sf::String GetPage(){return Page;}
	   virtual int GetTab(){return Tab;}
	   virtual sf::String GetGameState(){return state;}
   private:
	  sf::String Page;
	  sf::String state;
	  int Tab;
};