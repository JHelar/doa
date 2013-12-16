#pragma once

#include <iostream>
#include <conio.h>

#include "PlayerData.h"

class Game
{
public:

	Game(void)
	{
	}

	~Game(void)
	{
	}

	void printGameField()
	{
		
	}

	PlayerData mainGame()
	{
		PlayerData returnData;
		if(_kbhit())
		{
			returnData.moveKey = this->getPlayerMoveKey();
			returnData.playerID = this->checkPlayer(returnData.moveKey);
			return returnData;
		}
		else
			returnData.playerID = 0;
		this->printGameField();
		return returnData;
	}

	char getPlayerMoveKey()
	{
		return _getch();
	}

	int checkPlayer(char moveKey)
	{
		if(moveKey == 'w' || moveKey == 'a' || moveKey == 's' || moveKey == 'd')
			return 1;
		else if(moveKey == 'i' || moveKey == 'k' || moveKey == 'l' || moveKey == 'j')
			return 2;
		else
			return 0;
	}

	void setPlayer(PlayerData pd)
	{
		if(pd.playerID == 1)
		
		else if(pd.playerID == 2)
	}
};

