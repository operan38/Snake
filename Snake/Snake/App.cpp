#include "App.h"

bool App::isAppStateChange = false;

App::App()
{
	WINDOW_WIDTH = 800; WINDOW_HEIGHT = 600;
	WINDOW_TITLE = "Snake";
	isDEBUG = false; // DEBUG default
	frame = 0;
	avgFPS = 0;
	TimeSec = 0;
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),WINDOW_TITLE,sf::Style::Titlebar | sf::Style::Close);
}

App::~App()
{
	delete appState;
	delete appResources;
}

void App::setAppState(AppState *pAppState)
{
	delete appState;
	appState = NULL;
	appState = pAppState;
}

bool App::Init()
{
	window.setFramerateLimit(60); // Max FPS
	appResources = new AppResources();
	appResources->LoadContent();
	appResources->LoadSettings();
	window.setIcon(appResources->icon.getSize().x,appResources->icon.getSize().y,appResources->icon.getPixelsPtr());
	APP_STATE = 0; // 0 - MENU 1 - GAME
	appState = new Menu(appResources);
	return true;
}

void App::Loop()
{
	while (window.isOpen())
    {
		if (isAppStateChange)
		{
			switch(APP_STATE)
			{
			   case 0:
				   setAppState(new Game(appResources));
				   APP_STATE = 1;
			   break;

			   case 1:
				   setAppState(new Menu(appResources));
				   APP_STATE = 0;
			   break;
			}
			isAppStateChange = false;
		}
		if(clock.getElapsedTime().asSeconds() >= 1)
        {
			avgFPS = frame;
			frame = 0;
			clock.restart();
		}
		TimeSec = clockSec.getElapsedTime().asSeconds();
		clockSec.restart();
		while (window.pollEvent(e))
        {
			if (e.type == sf::Event::Closed)
			{
				appResources->SaveSettings();
				window.close();
			}
			if (e.type == sf::Event::KeyReleased)
			{
				if (e.key.code == sf::Keyboard::F1){
				    if (!isDEBUG) isDEBUG = true; else if (isDEBUG) isDEBUG = false;
				}
			}
			appState->Event(e,window);
		}

		if (isDEBUG)
		{
			if (APP_STATE == 0)
				window.setTitle("FPS: " + std::to_string(avgFPS) + " APP_STATE: " + std::to_string(APP_STATE) + " Page: " + appState->GetPage() + " Tab: " + std::to_string(appState->GetTab()));
			if (APP_STATE == 1)
				window.setTitle("FPS: " + std::to_string(avgFPS) + " APP_STATE: " + std::to_string(APP_STATE) + " GAME_STATE: " + appState->GetGameState());
		}
		else
			window.setTitle(WINDOW_TITLE);

		window.clear();

		appState->Update(TimeSec);
		appState->Draw(window);

		window.display();

		frame++;
	}
}