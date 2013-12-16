#pragma once

#include <iostream>

#include "PlayerData.h"

using namespace std;
class Player
{
private:
	int xPos;
	int yPos;
public:

	Player(int xPos, int yPos)
	{
		this->xPos = xPos;
		this->yPos = yPos;
	}

	~Player(void)
	{
	}

	PlayerData setPlayer(char moveKey,int id)
	{
		this->setPos(moveKey);
		return this->getPos(id);
	}

	void setPos(char moveKey)
	{
		if(moveKey == 'w' || moveKey == 'i')
			if((yPos - 2) < 0)
				yPos -= 2;
		else if(moveKey == 's' || moveKey == 'k')
			if((yPos + 2) < 10)
				yPos += 2;
		else if(moveKey == 'd' || moveKey == 'l')
			if((xPos + 2) < 10)
				xPos += 2;
		else if(moveKey == 'a' || moveKey == 'j')
			if((xPos - 2) > 0)
				xPos -= 2;
	}

	PlayerData getPos(int id)
	{
		PlayerData returnData;
		returnData.xPos = xPos;
		returnData.yPos = yPos;
		returnData.playerID = id;
		return returnData;
	}
};

