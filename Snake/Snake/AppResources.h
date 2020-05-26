#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <fstream>

class AppResources
{
   public:
	  AppResources();
	  ~AppResources();
	  void LoadContent();
	  void SaveSettings();
	  void LoadSettings();
	  sf::Font font;
	  sf::Texture tTitle;
	  sf::Texture tButton;
	  sf::Texture tField;
	  sf::Texture tHead;
	  sf::Texture tBody;
	  sf::Texture tHUD;
	  sf::Texture tFood;
	  sf::Texture tObj;
	  sf::Texture tFallingObj;
	  sf::Image icon;
	  int FieldID;
	  int SnakeID;
	  int ButtonID;
	  int isSound;
	  float delayMin;
	  int maxScore,Score1,Score2,Score3,Score4;
	  sf::String Difficulty;
	  sf::Sound sAppleCrunch1;
	  sf::Sound sAppleCrunch2;
	  sf::Sound sClick;
   private:
	 const char* fileSettings;
	 void Clear(const char *filename);
	 void Load(const char *filename);
	 void Save(const char *filename,std::string line);
	 sf::SoundBuffer bAppleCrunch1;
	 sf::SoundBuffer bAppleCrunch2;
	 sf::SoundBuffer bClick;
};