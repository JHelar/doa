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
	PlayerData *playerData,*p1Data,*p2Data;
	PlayerData playerMoveData;
	deque<PlayerData> playerPos;
	deque<PlayerData *> p1Q,p2Q;

	(*playerData).playerID = 0;

	bool go = true;

	thread gameThread(game.mainGame,playerData,playerMoveData);
	thread player1Thread(p1.setPlayer,p1Data);
	thread player2Thread(p2.setPlayer,p2Data);
	while(go)
	{
		gameThread.join();
		if((*playerData).playerID == 1)
			p1Q.push_back(playerData);
		else if((*playerData).playerID == 2)
			p2Q.push_back(playerData);
		if(p1Q.size() > 0)
		{
			p1Data = p1Q.front();
			p1Q.pop_front();
		}
		if(p2Q.size() > 0)
		{
			p2Data = p2Q.front();
			p2Q.pop_front();
		}
		player1Thread.join();
		playerPos.push_back((*p1Data));
		player2Thread.join();
		playerPos.push_back((*p2Data));
		playerMoveData = playerPos.front();
		playerPos.pop_front();
	}

	cin.get();
	return 0;
}