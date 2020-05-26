#pragma once
#include "App.h"
#include "AppState.h"
#include "AppResources.h"
#include "Text.h"
#include "Button.h"
#include <iostream>

class Menu : public AppState
{
   public:
	  Menu(AppResources* pAppResources);
	  ~Menu();
	  void Draw(sf::RenderWindow &window);
	  void Update(float TimeSec);
	  void Event(sf::Event e, sf::RenderWindow &window);
	  sf::String GetPage(){return Page;}
	  int GetTab(){return Tab;}
   private:
	   sf::Sprite sprTitle;
	   std::vector<Text*> text;
	   std::vector<Text*>::iterator itText;
	   std::vector<Button*> button;
	   std::vector<Button*>::iterator itBut;
	   sf::String Page;
	   sf::String strField[4];
	   sf::String strSnake[8];
	   sf::String strButton[3];
	   sf::String strSound[2];
	   int Tab,iTab;
	   bool isMouseOverTab;
	   bool isCreateControls;
	   void setTitle(int titleID);
	   void CreateControls();
	   sf::Color colorTypeText;
	   void ClearControls();
	   AppResources* appResources;
};