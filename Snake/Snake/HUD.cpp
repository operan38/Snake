#include "HUD.h"

HUD::HUD(AppResources* pAppResources, GameState* pGameState)
{
	appResources = pAppResources;
	gameState = pGameState;
	sprScore.setTexture(appResources->tHUD);
	sprScore.setTextureRect(sf::IntRect(0,0,20,20));
	sprScore.setPosition(22,10);
	sprTimer.setTexture(appResources->tHUD);
	sprTimer.setTextureRect(sf::IntRect(20,0,20,20));
	sprTimer.setPosition(140,11);
	TimerMin = 0; TimerSec = 0;
	ScoreStr = ""; TimerLvlStr = "";
}

HUD::~HUD()
{
	ClearControls();
}

void HUD::CreateControls()
{
	ClearControls();
	if (gameState->state == "Standard")
	{
	   text.push_back(new Text(appResources,ScoreStr,50,10,17,colorType,3));
	   text[0]->setUpdateText(0);
	   text.push_back(new Text(appResources,TimerLvlStr,170,10,17,colorType,3));
	   text[1]->setUpdateText(1);
	}
    else if (gameState->state == "Pause")
	{
	   text.push_back(new Text(appResources,ScoreStr,50,10,17,colorType,3));
	   text[0]->setUpdateText(0);
	   text.push_back(new Text(appResources,TimerLvlStr,170,10,17,colorType,3));
	   text[1]->setUpdateText(1);
	   text.push_back(new Text(appResources,L"Пауза",300,250,55,colorType,3));
	   text[2]->setAnimMove(300,230,40);
	}
	else if (gameState->state == "isExit")
	{
		text.push_back(new Text(appResources,ScoreStr,50,10,18,colorType,3));
		text[0]->setUpdateText(0);
		text.push_back(new Text(appResources,TimerLvlStr,170,10,18,colorType,3));
		text[1]->setUpdateText(1);
	    text.push_back(new Text(appResources,L"Вы уверены что хотите\nвыйти в меню Да(Y),Нет(N)",220,250,24,colorType,4));
		text[2]->setAnimMove(220,230,40);
	}
	else if (gameState->state == "GameOver")
	{
	   text.push_back(new Text(appResources,ScoreStr,50,10,17,colorType,3));
	   text[0]->setUpdateText(0);
	   text.push_back(new Text(appResources,TimerLvlStr,170,10,17,colorType,3));
	   text[1]->setUpdateText(1);
	   text.push_back(new Text(appResources,L"Рестарт: R",690,10,17,colorType,3));
	   text[2]->setAnimMove(690,0,20);
	   text.push_back(new Text(appResources,L"Игра окончена",180,250,55,sf::Color(255,0,0,255),3));
	   text[3]->setAnimMove(180,200,40);
	}
	else if (gameState->state == "GameWin")
	{
	   text.push_back(new Text(appResources,ScoreStr,50,10,17,colorType,3));
	   text[0]->setUpdateText(0);
	   text.push_back(new Text(appResources,TimerLvlStr,170,10,17,colorType,3));
	   text[1]->setUpdateText(1);
	   text.push_back(new Text(appResources,L"Победа",280,250,55,sf::Color(0,255,0,255),3));
	   text[2]->setAnimMove(280,200,40);
	}
}

void HUD::ClearControls()
{
	for (itText = text.begin(); itText != text.end();){Text *b = *itText; itText = text.erase(itText); delete b;}
	text.clear();
	std::vector<Text*>(text).swap(text);
}

void HUD::SetHUDColor(int FieldID)
{
	switch (FieldID)
	{
	    case 0:
	       colorType.r = 255; colorType.b = 255; colorType.g = 255; colorType.a = 250;
		break;
		case 1:
	       colorType.r = 0; colorType.b = 0; colorType.g = 0; colorType.a = 250;
		break;
		case 2:
	       colorType.r = 0; colorType.b = 0; colorType.g = 0; colorType.a = 250;
		break;
		case 3:
	       colorType.r = 255; colorType.b = 255; colorType.g = 255; colorType.a = 250;
		break;
	}
}

void HUD::Draw(sf::RenderWindow &window)
{
	if (!gameState->isCreateControls){
		CreateControls();
		gameState->isCreateControls = true;
	}
	ScoreStr = std::to_string(gameState->score) + "/" + std::to_string(appResources->maxScore);
	if (TimerSec >= 60)
    {
	     if (TimerMin <= 9)
		 {TimerLvlStr = "0" + std::to_string(TimerMin) + ":" + std::to_string((int)TimerSec);}
	     else if (TimerMin >= 10)
	     {TimerLvlStr = "" + std::to_string(TimerMin) + ":" + std::to_string((int)TimerSec);}
	     TimerMin += 1;
	     TimerSec = 0;
    }
    else if (TimerSec > 10)
	{
		 if (TimerMin <= 9)
		 {TimerLvlStr = "0" + std::to_string(TimerMin) + ":" + std::to_string((int)TimerSec);}
		 else if (TimerMin >= 10)
		 {TimerLvlStr = "" + std::to_string(TimerMin) + ":" + std::to_string((int)TimerSec);}
	}
    else
	{
		 if (TimerMin <= 9)
		 {TimerLvlStr = "0" + std::to_string(TimerMin) + ":" + "0" + std::to_string((int)TimerSec);}
		 else if (TimerMin >= 10)
		 {TimerLvlStr = "" + std::to_string(TimerMin) + ":" + "0" + std::to_string((int)TimerSec);}
	}
	for (itText = text.begin(); itText != text.end(); itText++)
	{
		(*itText)->draw(window);
	}
    window.draw(sprScore);
	window.draw(sprTimer);
}

void HUD::Update(float TimeSec)
{
    for (itText = text.begin(); itText != text.end(); itText++)
	{
		if ((*itText)->getUpdateText() == 0)
			(*itText)->updateText(ScoreStr);
		if ((*itText)->getUpdateText() == 1)
			(*itText)->updateText(TimerLvlStr);

		(*itText)->update(TimeSec);
	}
	if (gameState->state == "Standard")
	    TimerLvL(TimeSec);
}

void HUD::TimerLvL(float TimeSec)
{
     if (TimerSec >= 60)
	 {
	     TimerMin += 1;
	     TimerSec = 0;
	 }
	 else
	 {
	     TimerSec += TimeSec;
	 }
}

void HUD::Reset()
{
	TimerSec = 0;
	TimerMin = 0;
}