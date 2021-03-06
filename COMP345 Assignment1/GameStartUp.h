#ifndef GAMESTARTUP_H
#define GAMESTARTUP_H

#include <iostream>

#include "map.h"
#include "mapLoader.h"
#include "Cards.h"
#include "gameStart.h"

using namespace std;

class GameStartUp {
public:
	static void setCardCost(Deck* d);
	static void shuffleDeck(Deck* d);
	static void setPlayerPieces(vector<Player*> pl, Map *m);
	static void chooseStartingRegion(Map* m);
	static Player* makeBids(vector<Player*> pl);
	static void placeInitialPieces(vector<Player*> pl, Map* m);
	static void placeInitialPieces(vector<Player*> pl, Map* m, int indexes[10]);
};

#endif