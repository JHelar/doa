#include <deque>
#include <thread>

#include "PlayerData.h"
#include "Game.h"
#include "Player.h"

using namespace std;

int main(void)
{
	Game game;
	Player p1(1,9,1);
	Player p2(19,9,2);
	PlayerData playerData;
	PlayerData playerMoveData;
	deque<PlayerData> playerPos;

	playerData.playerID = 0;

	bool go = true;
	
	while(go)
	{
		playerData = game.mainGame(playerPos.front());
		if(playerData.playerID == 1)
			playerPos.push_back(p1.setPlayer(playerData.moveKey));
		else if(playerData.playerID == 2)
			playerPos.push_back(p2.setPlayer(playerData.moveKey));
	}

	cin.get();
	return 0;
}