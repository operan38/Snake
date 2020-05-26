#include "Game.h"

Game::Game(AppResources* pAppResources)
{
	appResources = pAppResources;
	srand((unsigned int)time(0));
	gameState = new GameState(appResources);
	field = new Field(appResources,gameState);
	food = new Food(appResources);
	player = new Player(appResources,gameState,food);
	hud = new HUD(appResources,gameState);
	hud->SetHUDColor(appResources->FieldID);
}

Game::~Game()
{
	delete field;
	delete player;
	delete food;
	delete hud;
	delete gameState;
}

void Game::Draw(sf::RenderWindow &window)
{
	field->Draw(window);
	food->Draw(window);
	player->Draw(window);
	hud->Draw(window);
}

void Game::Update(float TimeSec)
{
	if (gameState->state == "Standard" || gameState->state == "GameOver")
	    player->Update(TimeSec);

	    hud->Update(TimeSec);
}

void Game::Event(sf::Event e, sf::RenderWindow &window)
{
	if (e.type == sf::Event::KeyReleased)
	{
	   if (e.key.code == sf::Keyboard::Escape && gameState->state != "Pause" && gameState->state != "isExit"){
		   gameState->state = "isExit";
		   gameState->isCreateControls = false;
	   }
	   else if (gameState->state == "isExit")
	   {
		   if (e.key.code == sf::Keyboard::Y){
			   App::isAppStateChange = true;
		   }
		   if (e.key.code == sf::Keyboard::N || e.key.code == sf::Keyboard::Escape){
			   gameState->state = "Standard";
			   gameState->isCreateControls = false;
		   }
	   }
	   if (e.key.code == sf::Keyboard::P){
		   if (gameState->state == "Standard"){
		       gameState->state = "Pause";
			   gameState->isCreateControls = false;
		   }
		   else if (gameState->state == "Pause"){
		       gameState->state = "Standard";
			   gameState->isCreateControls = false;
		   }
	   }
	   if (e.key.code == sf::Keyboard::R && gameState->state == "GameOver" )
	   {
		   gameState->state = "Standard";
		   Reset();
	   }
	}
	if (gameState->state == "Standard")
	    player->Event(e);
}

void Game::Reset()
{
	srand((unsigned int)time(0));
	player->Reset();
	field->Reset();
	gameState->Reset();
	hud->Reset();
}