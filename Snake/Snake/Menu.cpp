#include "Menu.h"

Menu::Menu(AppResources* pAppResources)
{
	appResources = pAppResources;
	strField[0] = L"Луг"; strField[1] = L"Пустыня"; strField[2] = L"Зима"; strField[3] = L"Космос";
	strSnake[0] = L"Серый"; strSnake[1] = L"Красный"; strSnake[2] = L"Зелёный"; strSnake[3] = L"Синий"; strSnake[4] = L"Белый"; strSnake[5] = L"Чёрный"; strSnake[6] = L"Жёлтый"; strSnake[7] = L"Розовый";
	strButton[0] = L"Стиль 1"; strButton[1] = L"Стиль 2"; strButton[2] = L"Стиль 3";
	strSound[0] = L"Выкл"; 	strSound[1] = L"Вкл";
	sprTitle.setTexture(appResources->tTitle);
	isMouseOverTab = false;
	isCreateControls = false;
	Page = "MainMenu";
	Tab = 0;
	iTab = 0;
	setTitle(appResources->FieldID);
}

Menu::~Menu()
{
	ClearControls();
}

void Menu::ClearControls()
{
	for (itText = text.begin(); itText != text.end();){Text *b = *itText; itText = text.erase(itText); delete b;}
    text.clear();
	std::vector<Text*>(text).swap(text);
	for (itBut = button.begin(); itBut != button.end();){Button *b = *itBut; itBut = button.erase(itBut); delete b;}
	button.clear();
	std::vector<Button*>(button).swap(button);
}

void Menu::setTitle(int titleID)
{
	switch (titleID)
	{
	    case 0:
		   sprTitle.setTextureRect(sf::IntRect(0,0,800,600));
	       colorTypeText.r = 255; colorTypeText.g = 255; colorTypeText.b = 255; colorTypeText.a = 250;
		break;
		case 1:
		   sprTitle.setTextureRect(sf::IntRect(800,0,800,600));
	       colorTypeText.r = 0; colorTypeText.g = 0; colorTypeText.b = 0; colorTypeText.a = 250;
		break;
		case 2:
		   sprTitle.setTextureRect(sf::IntRect(1600,0,800,600));
	       colorTypeText.r = 0; colorTypeText.g = 0; colorTypeText.b = 0; colorTypeText.a = 250;
		break;
		case 3:
		   sprTitle.setTextureRect(sf::IntRect(2400,0,800,600));
	       colorTypeText.r = 255; colorTypeText.g = 255; colorTypeText.b = 255; colorTypeText.a = 250;
		break;
	}
}

void Menu::CreateControls()
{
	ClearControls();
	if (Page == "MainMenu")
	{
		text.push_back(new Text(appResources,L"Версия: 0.4d (Март 2016) SFML 2.3.2",5,5,14,colorTypeText,4));
		text[0]->setAnimMove(5,0,10);
		button.push_back(new Button(appResources,L"Старт",100,100,150,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Инфо",100,150,150,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Опции",100,200,150,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Выход",100,250,150,30,20,sf::Color(0,0,0,250),400));
    }
	else if (Page == "SelectDifficulty")
	{
		text.push_back(new Text(appResources,L"Выбор сложности",300,15,22,colorTypeText,4));
		text[0]->setAnimMove(300,0,20);
		text.push_back(new Text(appResources,L"Мой счет:",610,50,22,colorTypeText,3));
		text[1]->setAnimMove(610,20,35);
		text.push_back(new Text(appResources,L"Новичок: " + std::to_wstring(appResources->Score1)+L"/"+std::to_wstring(appResources->maxScore),620,90,16,colorTypeText,3));
		text[2]->setAnimMove(620,60,35);
		text.push_back(new Text(appResources,L"Игрок: " + std::to_wstring(appResources->Score2)+L"/"+std::to_wstring(appResources->maxScore),620,110,16,colorTypeText,3));
		text[3]->setAnimMove(620,80,35);
		text.push_back(new Text(appResources,L"Эксперт: " + std::to_wstring(appResources->Score3)+L"/"+std::to_wstring(appResources->maxScore),620,130,16,colorTypeText,3));
		text[4]->setAnimMove(620,100,35);
		text.push_back(new Text(appResources,L"Мастер: " + std::to_wstring(appResources->Score4)+L"/"+std::to_wstring(appResources->maxScore),620,150,16,colorTypeText,3));
		text[5]->setAnimMove(620,120,35);
		button.push_back(new Button(appResources,L"Новичок",100,100,150,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Игрок",100,150,150,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Эксперт",100,200,150,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Мастер",100,250,150,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
	}
	else if (Page == "Info")
	{
		text.push_back(new Text(appResources,L"Информация",340,15,22,colorTypeText,4));
		text[0]->setAnimMove(340,0,30);
		text.push_back(new Text(appResources,L"Автор: Горбунов Иван",625,5,14,colorTypeText,4));
		text[1]->setAnimMove(625,0,10);
		text.push_back(new Text(appResources,L"Управление:",90,50,22,colorTypeText,3));
		text[2]->setAnimMove(90,20,50);
		text.push_back(new Text(appResources,L"Перемещение: 'Вверх', 'Вниз', 'Влево', 'Вправо'.\nПауза: 'P'.\nРестарт(при поражении или победе): 'R'.\nВ меню(если в игре): 'Esc'.\nDEBUG: 'F1'.",40,90,16,colorTypeText,3));
		text[3]->setAnimMove(40,60,50);
		text.push_back(new Text(appResources,L"Об игре:",600,50,22,colorTypeText,3));
		text[4]->setAnimMove(600,20,50);
		text.push_back(new Text(appResources,L"Данная игра является клоном\nпопулярной змейки, которых\nуже тысячи. При созданни игры,\nвсе яблоки остались целыми,\nнууу... почти все =).",500,90,16,colorTypeText,3));
		text[5]->setAnimMove(500,60,50);
		text.push_back(new Text(appResources,L"Внимание: Счет сохраняется при\nпоражении или победе.",40,190,16,colorTypeText,3));
		text[6]->setAnimMove(40,160,50);
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
	}
    else if (Page == "Settings")
	{
		text.push_back(new Text(appResources,L"Опции",340,15,22,colorTypeText,4));
		text[0]->setAnimMove(340,0,30);
		text.push_back(new Text(appResources,L"Тип поля: " + strField[appResources->FieldID],540,90,17,colorTypeText,4));
		text[1]->setAnimMove(540,70,25);
		text.push_back(new Text(appResources,L"Цвет змейки: " + strSnake[appResources->SnakeID],540,115,17,colorTypeText,4));
		text[2]->setAnimMove(540,95,25);
		text.push_back(new Text(appResources,L"Стиль конопок: " + strButton[appResources->ButtonID],540,140,17,colorTypeText,4));
		text[3]->setAnimMove(540,120,25);
		text.push_back(new Text(appResources,L"Звук: " + strSound[appResources->isSound],540,165,17,colorTypeText,4));
		text[4]->setAnimMove(540,145,25);
		button.push_back(new Button(appResources,L"Тип поля",100,100,165,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Цвет змейки",100,150,165,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,L"Стиль кнопок",100,200,165,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Звук",100,250,165,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
	}
	else if (Page == "Settings(FieldType)")
	{
		text.push_back(new Text(appResources,L"Тип поля",340,15,22,colorTypeText,4));
		text[0]->setAnimMove(340,0,30);
		button.push_back(new Button(appResources,strField[0],100,100,155,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strField[1],100,150,155,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strField[2],100,200,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,strField[3],100,250,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
		button[appResources->FieldID]->isSelected = true;
		button[appResources->FieldID]->selected();
	}
	else if (Page == "Settings(ColorSnake)")
	{
		text.push_back(new Text(appResources,L"Цвет змейки",340,15,22,colorTypeText,4));
		text[0]->setAnimMove(340,0,30);
		button.push_back(new Button(appResources,strSnake[0],100,100,155,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strSnake[1],100,150,155,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strSnake[2],100,200,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,strSnake[3],100,250,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,strSnake[4],100,300,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,strSnake[5],100,350,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,strSnake[6],300,100,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,strSnake[7],300,150,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
	    button[appResources->SnakeID]->isSelected = true;
		button[appResources->SnakeID]->selected();
	}
    else if (Page == "Settings(ButtonStyle)")
	{
		text.push_back(new Text(appResources,L"Стиль кнопок",320,15,22,colorTypeText,4));
		text[0]->setAnimMove(320,0,30);
		button.push_back(new Button(appResources,strButton[0],100,100,155,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strButton[1],100,150,155,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strButton[2],100,200,155,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
	    button[appResources->ButtonID]->isSelected = true;
		button[appResources->ButtonID]->selected();
	}
	else if (Page == "Settings(Sound)")
	{
		text.push_back(new Text(appResources,L"Звук",350,15,22,colorTypeText,4));
		text[0]->setAnimMove(350,0,30);
		button.push_back(new Button(appResources,strSound[0],100,100,165,30,20,sf::Color(0,0,0,250),400));
	    button.push_back(new Button(appResources,strSound[1],100,150,165,30,20,sf::Color(0,0,0,250),400));
		button.push_back(new Button(appResources,L"Назад",40,520,88,30,20,sf::Color(0,0,0,250),400));
	    button[appResources->isSound]->isSelected = true;
		button[appResources->isSound]->selected();
	}
}

void Menu::Draw(sf::RenderWindow &window)
{
	window.draw(sprTitle);
	if (isMouseOverTab == false)	
	    Tab = 0;
	if (!isCreateControls){
		CreateControls();
		isCreateControls = true;
	}
	iTab = 0;
	for (itBut = button.begin(); itBut != button.end(); itBut++)
	{ 
		iTab++;
		if (sf::IntRect((int)(*itBut)->x,(int)(*itBut)->y,(int)(*itBut)->w,(int)(*itBut)->h).contains(sf::Mouse::getPosition(window)))
		{
			Tab = iTab;
			(*itBut)->isHover = true;
			(*itBut)->hover();
			isMouseOverTab = true;
		}
		else if ((*itBut)->isHover == true) {(*itBut)->isHover = false; (*itBut)->hover(); (*itBut)->selected(); isMouseOverTab = false;}
		(*itBut)->draw(window);
	}
	for (itText = text.begin(); itText != text.end(); itText++)
	{
		(*itText)->draw(window);
	}
}

void Menu::Update(float TimeSec)
{
	for (itBut = button.begin(); itBut != button.end(); itBut++)
	{ 
		(*itBut)->update(TimeSec);
	}
	for (itText = text.begin(); itText != text.end(); itText++)
	{
		(*itText)->update(TimeSec);
	}
}

void Menu::Event(sf::Event e, sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && e.type == sf::Event::MouseButtonPressed)
	{
		if (Page == "MainMenu") // Главное меню
		{
			if (Tab == 1){Page = "SelectDifficulty"; isCreateControls = false;}
			if (Tab == 2){Page = "Info"; isCreateControls = false;}
			if (Tab == 3){Page = "Settings"; isCreateControls = false;}
			if (Tab == 4){appResources->SaveSettings(); window.close();}
		}
		else if (Page == "SelectDifficulty") // Выбор сложности (Старт игры)
		{
			if (Tab == 1){appResources->delayMin = (float)0.080; appResources->Difficulty = "Easy"; App::isAppStateChange = true;}
			if (Tab == 2){appResources->delayMin = (float)0.040; appResources->Difficulty = "Normal"; App::isAppStateChange = true;} 
			if (Tab == 3){appResources->delayMin = (float)0.020; appResources->Difficulty = "Hard"; App::isAppStateChange = true;}
			if (Tab == 4){appResources->delayMin = (float)0.001; appResources->Difficulty = "VeryHard"; App::isAppStateChange = true;}
			if (Tab == 5){Page = "MainMenu"; isCreateControls = false;}
		}
		else if (Page == "Info") // Инфо
		{
			if (Tab == 1){Page = "MainMenu"; isCreateControls = false;}
		}
		else if (Page == "Settings") // Опции
		{
			if (Tab == 1){Page = "Settings(FieldType)"; isCreateControls = false;}
			if (Tab == 2){Page = "Settings(ColorSnake)"; isCreateControls = false;}
			if (Tab == 3){Page = "Settings(ButtonStyle)"; isCreateControls = false;}
			if (Tab == 4){Page = "Settings(Sound)"; isCreateControls = false;}
			if (Tab == 5){Page = "MainMenu"; isCreateControls = false;}
		}
		else if (Page == "Settings(FieldType)") // Тип поля (Опции)
		{
			if (Tab == 1){appResources->FieldID = 0; Page = "Settings"; setTitle(appResources->FieldID); isCreateControls = false;}
			if (Tab == 2){appResources->FieldID = 1; Page = "Settings"; setTitle(appResources->FieldID); isCreateControls = false;}
			if (Tab == 3){appResources->FieldID = 2; Page = "Settings"; setTitle(appResources->FieldID); isCreateControls = false;}
			if (Tab == 4){appResources->FieldID = 3; Page = "Settings"; setTitle(appResources->FieldID); isCreateControls = false;}
			if (Tab == 5){Page = "Settings"; isCreateControls = false;}
		}
		else if (Page == "Settings(ColorSnake)") // Цвет змейки (Опции)
		{
			if (Tab == 1){appResources->SnakeID = 0; Page = "Settings"; isCreateControls = false;}
			if (Tab == 2){appResources->SnakeID = 1; Page = "Settings"; isCreateControls = false;}
			if (Tab == 3){appResources->SnakeID = 2; Page = "Settings"; isCreateControls = false;}
			if (Tab == 4){appResources->SnakeID = 3; Page = "Settings"; isCreateControls = false;}
			if (Tab == 5){appResources->SnakeID = 4; Page = "Settings"; isCreateControls = false;}
			if (Tab == 6){appResources->SnakeID = 5; Page = "Settings"; isCreateControls = false;}
			if (Tab == 7){appResources->SnakeID = 6; Page = "Settings"; isCreateControls = false;}
			if (Tab == 8){appResources->SnakeID = 7; Page = "Settings"; isCreateControls = false;}
			if (Tab == 9){Page = "Settings"; isCreateControls = false;}
		}
		else if (Page == "Settings(ButtonStyle)") // Стиль кнопок (Опции)
		{
			if (Tab == 1){appResources->ButtonID = 0; Page = "Settings"; isCreateControls = false;}
			if (Tab == 2){appResources->ButtonID = 1; Page = "Settings"; isCreateControls = false;}
			if (Tab == 3){appResources->ButtonID = 2; Page = "Settings"; isCreateControls = false;}
			if (Tab == 4){Page = "Settings"; isCreateControls = false;}
		}
		else if (Page == "Settings(Sound)") // Звук (Опции)
		{
			if (Tab == 1){appResources->isSound = 0; Page = "Settings"; isCreateControls = false;}
			if (Tab == 2){appResources->isSound = 1; Page = "Settings"; isCreateControls = false;}
			if (Tab == 3){Page = "Settings"; isCreateControls = false;}
		}
		if (appResources->isSound && Tab != 0)
		    appResources->sClick.play();

		Tab = 0;
	}
}