#include "AppResources.h"

AppResources::AppResources()
{
	FieldID = 0;
	SnakeID = 0;
	ButtonID = 0;
	isSound = 1;
	delayMin = 0;
	Score1 = 0; Score2 = 0; Score3 = 0; Score4 = 0;
	maxScore = 800;
	fileSettings = "Data/Settings.txt";
}

AppResources::~AppResources(){}

void AppResources::Save(const char *filename,std::string line)
{
	std::ofstream file;
	file.open(filename,std::ios::app);
    file << "\n" << line;
	file.close();
}

void AppResources::Clear(const char *filename)
{
	std::ofstream file;
	file.open(filename);
	file.clear();
	file.close();
}

void AppResources::Load(const char *filename)
{
	std::ifstream file;
	file.open(filename);
	int i = 0;
	if (file.is_open())
	{
		while(!file.eof())
		{
			int line;
			file >> line;
			if (i == 0){if (line >= 0  && line <= 3) FieldID = line;}
			if (i == 1){if (line >= 0  && line <= 7) SnakeID = line;}
			if (i == 2){if (line >= 0  && line <= 2) ButtonID = line;}
			if (i == 3){if (line >= 0  && line <= 1) isSound = line;}
			if (i == 4){if (line >= 0  && line <= maxScore) Score1 = line;}
			if (i == 5){if (line >= 0  && line <= maxScore) Score2 = line;}
			if (i == 6){if (line >= 0  && line <= maxScore) Score3 = line;}
			if (i == 7){if (line >= 0  && line <= maxScore) Score4 = line;}
			i++;
		}
	}
	file.close();
}

void AppResources::LoadSettings()
{
	Load(fileSettings);
}

void AppResources::SaveSettings()
{
	Clear(fileSettings);
	Save(fileSettings,std::to_string(FieldID));
	Save(fileSettings,std::to_string(SnakeID));
	Save(fileSettings,std::to_string(ButtonID));
	Save(fileSettings,std::to_string(isSound));
	Save(fileSettings,std::to_string(Score1));
	Save(fileSettings,std::to_string(Score2));
	Save(fileSettings,std::to_string(Score3));
	Save(fileSettings,std::to_string(Score4));
}

void AppResources::LoadContent()
{
	font.loadFromFile("Data/verdana.ttf");
	icon.loadFromFile("Data/Icon.png");
	tTitle.loadFromFile("Data/Textures/Menu/Title.png");
	tButton.loadFromFile("Data/Textures/Menu/Button.png");
	tField.loadFromFile("Data/Textures/Game/Field.png");
	tBody.loadFromFile("Data/Textures/Game/Body.png");
	tHead.loadFromFile("Data/Textures/Game/Head.png");
	tHUD.loadFromFile("Data/Textures/Game/HUDIcon.png");
	tObj.loadFromFile("Data/Textures/Game/Objects.png");
	tFood.loadFromFile("Data/Textures/Game/Food.png");
	tFallingObj.loadFromFile("Data/Textures/Game/SnowFlake.png");
	bAppleCrunch1.loadFromFile("Data/Sound/AppleCrunch1.wav");
	sAppleCrunch1.setBuffer(bAppleCrunch1);
	bAppleCrunch2.loadFromFile("Data/Sound/AppleCrunch2.wav");
	sAppleCrunch2.setBuffer(bAppleCrunch2);
	bClick.loadFromFile("Data/Sound/Click.wav");
	sClick.setBuffer(bClick);
}