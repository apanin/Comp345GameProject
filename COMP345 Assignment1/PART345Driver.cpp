#include <iostream>
#include "mainLoop.h"
#include "gameStart.h"
using namespace std;

int main() {
	//*******************************
	//COPY FROM GAMESTART FOR TESTING
	//*******************************
	Map* map = GameStart::selectMap("./maps/BirdsL.map");
	
	//	//manually enter players
	//	vector<Player*> players= GameStart::setPlayers();
	
	vector<Player*> pl;
	pl.push_back(new Player("anna"));
	pl.push_back(new Player("paul"));
	GameStart::setPlayers(pl);
	map->loadPlayers(pl);
	
	Deck* deck = GameStart::setDeck();
	//*******************************
	//COPY FROM GAMESTART FOR TESTING
	//*******************************
	map->setStartingRegion(map->getRegionById(5));
	map->getStartingRegion()->setArmies(pl.at(0), 4);
	map->getStartingRegion()->setArmies(pl.at(1), 4);
	
	MainLoop ml = MainLoop(pl, deck, map);
	
	ml.playGame();
	
	
	
}