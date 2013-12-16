#pragma once

#include <iostream>
#include <conio.h>
#include <vector>

#include "PlayerData.h"

using namespace std;
class Game
{
private:
	vector<vector<char>> gameField;
public:

	Game(void)
	{
		vector<char> gameRow;
		gameRow.push_back(char(218));
		for(int i = 0; i < 10; i++)
		{
			gameRow.push_back(char(196));
			gameRow.push_back(char(194));
		}
		gameRow.pop_back();
		gameRow.push_back(char(191));
		gameField.push_back(gameRow);
		gameRow.clear();
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				gameRow.push_back(char(179));
				gameRow.push_back(' ');
			}
			gameRow.push_back(char(179));
			gameField.push_back(gameRow);
			gameRow.clear();
			gameRow.push_back(char(195));
			for(int j = 0; j < 10; j++)
			{
				gameRow.push_back(char(196));
				gameRow.push_back(char(197));
			}
			gameRow.pop_back();
			gameRow.push_back(char(180));
			gameField.push_back(gameRow);
			gameRow.clear();
		}
		gameField.pop_back();
		gameRow.push_back(char(192));
		for(int i = 0; i < 10; i++)
		{
			gameRow.push_back(char(196));
			gameRow.push_back(char(193));
		}
		gameRow.pop_back();
		gameRow.push_back(char(217));
		gameField.push_back(gameRow);
		gameField[9][19] = '2';
		gameField[9][1] = '1';
	}		

	~Game(void)
	{
	}

	void printGameField()
	{
		for(int i = 0; i < gameField.size(); i++)
		{
			for(int j = 0; j < gameField[i].size(); j++)
			{
				cout << gameField[i][j];
			}
			cout << endl;
		}
	}

	void mainGame(PlayerData *pd,PlayerData playerMoveData)
	{
		if(_kbhit())
		{
			(*pd).moveKey = this->getPlayerMoveKey();
			(*pd).playerID = this->checkPlayer((*pd).moveKey);
		}
		else
			(*pd).playerID = 0;
		if(playerMoveData.playerID != 0)
		{
			this->setPlayer(playerMoveData);
		}
		this->printGameField();
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
		{
			if(gameField[pd.yPos][pd.xPos] != '2')
			{
				gameField[pd.yPrev][pd.xPrev] = ' ';
				gameField[pd.yPos][pd.xPos] = '1';
			}
			else
				gameField[pd.yPos][pd.xPos] = 'X';
		}
		else if(pd.playerID == 2)
		{
			if(gameField[pd.yPos][pd.xPos] != '1')
			{
				gameField[pd.yPrev][pd.xPrev] = ' ';
				gameField[pd.yPos][pd.xPos] = '2';
			}
			else
				gameField[pd.yPos][pd.xPos] = 'X';
		}
	}
};

