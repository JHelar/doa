#include <deque>
#include <thread>

#include "PlayerData.h"
#include "Game.h"
#include "Player.h"

using namespace std;
int main(void)
{
	Game game;
	Player p1(0,5);
	Player p2(10,5);
	PlayerData playerData;
	PlayerData playerMoveData;
	deque<PlayerData> p1Data,p2Data;
	deque<PlayerData> playerPos;

	bool go = true;


	while(go)
	{
		playerData = game.mainGame();
		if(playerData.playerID == 1)
			p1Data.push_back(playerData);
		else if(playerData.playerID == 2)
			p2Data.push_back(playerData);
		playerMoveData = p1Data.front();
		p1Data.pop_front();
		playerPos.push_back(p1.setPlayer(playerMoveData.moveKey,playerMoveData.playerID));
		playerMoveData = p2Data.front();
		p2Data.pop_front();
		playerPos.push_back(p2.setPlayer(playerMoveData.moveKey,playerMoveData.playerID));
		game.setPlayer(playerPos.front());
		playerPos.pop_front();
	}

	cin.get();
	return 0;
}