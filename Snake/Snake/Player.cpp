#include "Player.h"

Player::Player(AppResources* pAppResources, GameState* pGameState, Food* pFood)
{
	appResources = pAppResources;
	gameState = pGameState;
	food = pFood;
	sprHead.setTexture(appResources->tHead);
	sprBody.setTexture(appResources->tBody);
	delay = 0; delayMin = appResources->delayMin;
	for (int i = 1; i < 801; i++){x[i] = -50; y[i] = -50;}
	x[0] = 100; y[0] = 100;
	w = 12; h = 12;
	length = 4;
	dir = 0;
	speed = 10;
	setSnake();
}

Player::~Player(){}

void Player::Draw(sf::RenderWindow &window)
{
	for (int i = length; i > 0; i--)
	{   
		if (x[i] != -50 && y[i] != -50){
		   sprBody.setPosition((float)x[i], (float)y[i]);
		   window.draw(sprBody);
		}
	}
	sprHead.setPosition((float)x[0],(float)y[0]);
	window.draw(sprHead);
}

void Player::Update(float TimeSec)
{
	delay += TimeSec;
	for (int i = 5; i < length; i++)
	{
		 if (x[0] >= x[i]-w && x[0]-x[i] <= w &&
		      y[0] >= y[i]-h && y[0]-y[i] <= h)
		 {
			 x[0] = -50;
			 if (gameState->state != "GameOver")
			     gameState->GameOver();

			 break;
		 }
	}
	if (delay > delayMin)
	{
	    for (int i = length; i > 0; i--)
		{
	        x[i]=x[i-1]; 
            y[i]=y[i-1];
	    }
	    delay = 0;
		if (gameState->state == "Standard"){
	        switch (dir)
	        {
	           case 0: x[0] += speed; break;
	           case 1: x[0] -= speed; break;
		       case 2: y[0] -= speed; break;
		       case 3: y[0] += speed; break;
	        }
			if (x[0] <= -1){x[0] = 800;}
	        else if (x[0] >= 801){x[0] = 0;}
	        if (y[0] <= -1) {y[0] = 600;}
	        else if (y[0] >= 601) {y[0] = 0;}

			Eat();
		}
	}
	if (gameState->score >= appResources->maxScore && gameState->state != "GameWin"){
		gameState->GameWin();
	}
}

void Player::Event(sf::Event e)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 1 && y[0] < 600 && y[0] > 0)
	{
		dir = 0;
	    switch (appResources->SnakeID)
		{
	    case 0:
			sprHead.setTextureRect(sf::IntRect(0,0,w,h));
		break;
	    case 1:
			sprHead.setTextureRect(sf::IntRect(0,12,w,h));
		break;
		case 2:
			sprHead.setTextureRect(sf::IntRect(0,24,w,h));
		break;
		case 3:
			sprHead.setTextureRect(sf::IntRect(0,36,w,h));
		break;
		case 4:
			sprHead.setTextureRect(sf::IntRect(0,48,w,h));
		break;
		case 5:
			sprHead.setTextureRect(sf::IntRect(0,60,w,h));
		break;
		case 6:
			sprHead.setTextureRect(sf::IntRect(0,72,w,h));
		break;
		case 7:
			sprHead.setTextureRect(sf::IntRect(0,84,w,h));
		break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != 0 && y[0] < 600 && y[0] > 0)
	{
		dir = 1;
		switch (appResources->SnakeID)
	    {
	    case 0:
		    sprHead.setTextureRect(sf::IntRect(14,0,w,h));
		break;
		case 1:
		    sprHead.setTextureRect(sf::IntRect(14,12,w,h));
		break;
		case 2:
			sprHead.setTextureRect(sf::IntRect(14,24,w,h));
		break;
		case 3:
		    sprHead.setTextureRect(sf::IntRect(14,36,w,h));
		break;
		case 4:
			sprHead.setTextureRect(sf::IntRect(14,48,w,h));
		break;
	    case 5:
			sprHead.setTextureRect(sf::IntRect(14,60,w,h));
		break;
		case 6:
			sprHead.setTextureRect(sf::IntRect(14,72,w,h));
		break;
		case 7:
			sprHead.setTextureRect(sf::IntRect(14,84,w,h));
		break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != 3 && x[0] < 800 && x[0] > 0)
	{
		dir = 2;
		switch (appResources->SnakeID)
	    {
	    case 0:
			sprHead.setTextureRect(sf::IntRect(28,0,w,h));
		break;
	    case 1:
			sprHead.setTextureRect(sf::IntRect(28,12,w,h));
		break;
		case 2:
			sprHead.setTextureRect(sf::IntRect(28,24,w,h));
		break;
		case 3:
			sprHead.setTextureRect(sf::IntRect(28,36,w,h));
		break;
		case 4:
			sprHead.setTextureRect(sf::IntRect(28,48,w,h));
		break;
		case 5:
			sprHead.setTextureRect(sf::IntRect(28,60,w,h));
		break;
		case 6:
			sprHead.setTextureRect(sf::IntRect(28,72,w,h));
		break;
		case 7:
			sprHead.setTextureRect(sf::IntRect(28,84,w,h));
		break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != 2 && x[0] < 800 && x[0] > 0)
	{
		dir = 3;
	    switch (appResources->SnakeID)
	    {
	    case 0:
			sprHead.setTextureRect(sf::IntRect(42,0,w,h));
		break;
	    case 1:
			sprHead.setTextureRect(sf::IntRect(42,12,w,h));
		break;
		case 2:
			sprHead.setTextureRect(sf::IntRect(42,24,w,h));
		break;
	    case 3:
			sprHead.setTextureRect(sf::IntRect(42,36,w,h));
		break;
		case 4:
			sprHead.setTextureRect(sf::IntRect(42,48,w,h));
		break;
		case 5:
			sprHead.setTextureRect(sf::IntRect(42,60,w,h));
		break;
		case 6:
			sprHead.setTextureRect(sf::IntRect(42,72,w,h));
		break;
		case 7:
			sprHead.setTextureRect(sf::IntRect(42,84,w,h));
		break;
		}
	}
}

void Player::setSnake()
{
	switch (appResources->SnakeID)
	{
	    case 0:
		   sprBody.setTextureRect(sf::IntRect(0,0,w,h));
		   sprHead.setTextureRect(sf::IntRect(0,0,w,h));
		break;
		case 1:
		   sprBody.setTextureRect(sf::IntRect(12,0,w,h));
		   sprHead.setTextureRect(sf::IntRect(0,12,w,h));
		break;
	    case 2:
		   sprBody.setTextureRect(sf::IntRect(24,0,w,h));
		   sprHead.setTextureRect(sf::IntRect(0,24,w,h));
		break;
		case 3:
		   sprBody.setTextureRect(sf::IntRect(36,0,w,h));
		   sprHead.setTextureRect(sf::IntRect(0,36,w,h));
		break;
		case 4:
		   sprBody.setTextureRect(sf::IntRect(48,0,w,h));
		   sprHead.setTextureRect(sf::IntRect(0,48,w,h));
		break;
		case 5:
		  sprBody.setTextureRect(sf::IntRect(60,0,w,h));
		  sprHead.setTextureRect(sf::IntRect(0,60,w,h));
		break;
		case 6:
		  sprBody.setTextureRect(sf::IntRect(72,0,w,h));
		  sprHead.setTextureRect(sf::IntRect(0,72,w,h));
		break;
		case 7:
		  sprBody.setTextureRect(sf::IntRect(84,0,w,h));
		  sprHead.setTextureRect(sf::IntRect(0,84,w,h));
		break;
	}
}

void Player::Eat()
{
	int i = 0;
	if (x[0] >= food->getX()-food->getW() && x[0]-food->getX() <= food->getW() &&
		y[0] >= food->getY()-food->getH() && y[0]-food->getY() <= food->getH())
	{
		length++;
		gameState->score++;
		food->setX(rand() % 700 + 50);
        food->setY(rand() % 460 + 60);
		if (appResources->isSound){
			switch(food->getType())
			{
			   case 1:
		       appResources->sAppleCrunch1.play();
			   break;
			   case 2:
		       appResources->sAppleCrunch2.play();
			   break;
			}
		}

		CheckFoodSpawn();
	}
}

void Player::CheckFoodSpawn()
{
	for (int i = 0; i < length; i++){
	   if (x[i] >= food->getX()-food->getW() && x[i]-food->getX() <= food->getW() &&
		   y[i] >= food->getY()-food->getH() && y[i]-food->getY() <= food->getH()){
		        food->setX(rand() % 700 + 50);
                food->setY(rand() % 460 + 60);
				CheckFoodSpawn();
				break;
	   }
	}
	food->RandomApple();
	food->RandomPosition();
}

void Player::Reset()
{
	for (int i = 1; i < 801; i++){x[i] = -50; y[i] = -50;}
	length = 4;
	dir = 0;
	x[0] = 100; y[0] = 100;
	delay = 0;
	setSnake();
}