#pragma once

#include <iostream>

#include "PlayerData.h"

using namespace std;
class Player
{
private:
	PlayerData pd;
public:

	Player(int xPos, int yPos, int id)
	{
		this->pd.xPos = this->pd.xPrev = xPos;
		this->pd.yPos = this->pd.yPrev = yPos;
		this->pd.playerID = id;
	}

	~Player(void)
	{
	}

	PlayerData setPlayer(char moveKey)
	{
		this->pd.xPrev = this->pd.xPos;
		this->pd.yPos = this->pd.yPos;
		this->setPos(moveKey);
		return this->getPos();
	}

	void setPos(char moveKey)
	{
		if(moveKey == 'w' || moveKey == 'i')
			if((pd.yPos - 2) < 0)
				pd.yPos -= 2;
		else if(moveKey == 's' || moveKey == 'k')
			if((pd.yPos + 2) < 10)
				pd.yPos += 2;
		else if(moveKey == 'd' || moveKey == 'l')
			if((pd.xPos + 2) < 10)
				pd.xPos += 2;
		else if(moveKey == 'a' || moveKey == 'j')
			if((pd.xPos - 2) > 0)
				pd.xPos -= 2;
	}

	PlayerData getPos(){return this->pd;}
};

