#pragma once

class GameState
{
    public:
		GameState(AppResources* pAppResources){appResources = pAppResources; score = 0; state = "Standard"; isCreateControls = false;}
		sf::String GetGameSate(){return state;}
	    int score;
		int isCreateControls;
		void GameOver()
        {
	       state = "GameOver";
	       SaveScore();
		   isCreateControls = false;
        }
        void GameWin()
        {
	       state = "GameWin";
	       SaveScore();
		   isCreateControls = false;
        }
		void SaveScore()
		{
			 if (appResources->Difficulty == "Easy" && score >= appResources->Score1)
				 appResources->Score1 = score;
			 if (appResources->Difficulty == "Normal" && score >= appResources->Score2)
				 appResources->Score2 = score;
			 if (appResources->Difficulty == "Hard" && score >= appResources->Score3)
				 appResources->Score3 = score;
			 if (appResources->Difficulty == "VeryHard" && score >= appResources->Score4)
				 appResources->Score4 = score;
		}
		void Reset()
		{
			score = 0;
			state = "Standard";
			isCreateControls = false;
		}
		sf::String state; // state = 0(standard) state = 1(pause) state = 2(isExit) state = 3(GameOver) state = 4(GameWin)
    private:
		AppResources* appResources;
};