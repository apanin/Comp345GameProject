#include <iostream>
#include "gameStart.h"


using namespace std;
int main(int argc, char *argv[]) {
	
//	Map* map = GameStart::selectMap();
	Map* map = GameStart::selectMap("./maps/BirdsL.map");
	
//	//manually enter players
//	vector<Player*> players= GameStart::setPlayers();

	vector<Player*> pl;
	pl.push_back(new Player("anna"));
	pl.push_back(new Player("paul"));
	GameStart::setPlayers(pl);
	
	
	Deck* deck = GameStart::setDeck();
	
	cout << *(deck->getHand()) << endl;
	pl.at(0)->exchange(deck, deck->getHand()->getCards().at(4));
	cout << *(deck->getHand()) << endl;
//	gs.exchange(pl.at(0));
}