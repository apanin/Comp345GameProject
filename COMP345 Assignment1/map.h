#include <iostream>
#include <map>
#include <vector>
#include "Player.h"

using namespace std;

#ifndef MAP_H
#define MAP_H

class Region {
private:
	int id;
	string name;
	int continentId;
	string continent;
	string owner;
	
	
//	int nbArmies;
	vector<pair<Player*, int>> playerArmies;
	vector<pair<Player*, bool>> playerCity;
	//Output
	friend std::ostream& operator<<(std::ostream&, const Region&);
	
public:
//	Constructors and destructors
	Region();
	Region(const Region& region);
	Region(int id, string name, string continent, int continentId);
	~Region();
	
//	setters and getters
	void setPlayers(vector<Player*> playerList);
	void setPlayersAndArmies(vector<Player*> playerList, vector<int> armyNbList);
	void setName(string name);
	void setArmies(Player* p, int nb);
	void addArmies(Player* p, int nb);
	bool addCity(Player* p);
	bool checkCity(Player* p);
	void removeArmies(Player* p, int nb);
	string getOwner();
	void setOwner(Player* player);
	void determineOwner();
	void setOwnerByName(string name);
	void setContinent(string continent);
	void setContinentId(int id);
	
	
	bool canDestroy(Player* p);
	int getId();
	string getName();
	int getTotalArmies();
	int getNbArmiesByName(string name);
	int getNbArmiesByPlayer(Player* p);
	string getContinent() const;
	int getContinentId();
	vector<pair<Player*, int>> getPlayerArmies();
	const string getPlayersAndArmiesString() const;
	bool checkStartingRegion(Map* m);
};

class Continent {
private:
	int id;
	string name;
	vector<Region*> regions;
	
	vector<int> connectedContinents;
	
	friend std::ostream& operator<<(std::ostream&, const Continent&);
public:
	//constructors and destructors
	Continent();
	Continent(const Continent& continent);
	Continent(int id, string name);
//	Continent(int id, string name, vector<Region*> regions)
	~Continent();
	
	//setters and getters
	void setId(int id);
	void setName(string name);
	void setRegions(vector<Region*> regions);
	void setConnectedContinents(vector<int> connectedContinents);

	string getOwner(Map* m);
	
	int getId();
	string getName();
	vector<Region*> getRegions();
	vector<int> getConnectedContinents();
	
	
	//extra functions for region management
	int getNbRegions();
	Region* addRegion(int id, string name);
	void addRegion(Region* region);
	bool hasRegion(int id);
	Region* getRegionById(int id);
	vector<int> getListOfRegionId();
	
	//extra function for connected continent management
	void addConnectedContinent(int id);
	bool isConnectedToContinent(int id);
	int getNbConnectedContinents();
};

class Map {
private:
	string name;
	Region* startingRegion;
	vector<Continent*> continents;
	vector<vector<int>> borders;
	vector<Player*> players;
	
	Player* immunePlayer;
	friend std::ostream& operator<<(std::ostream&, const Map&);	
	
public:
	//default constructor
	Map();
	//basic parameter constructor
	Map(string name);
	//parameter constructor
	Map(string name, vector<Continent*> continents, vector<vector<int>> borders);
	//copy constructor
	Map(const Map& map);	
	//constructor for map file
	Map(vector<vector<string>> listContinents, vector<vector<string>> listRegions, vector<vector<string>> listBorders);
	//destructor
	~Map();
	
	//setters and getters
	void setName(string name);
	void setContinents(vector<Continent*>);
	void setBorders(vector<vector<int>> borders);
	void setNbPlayersIntoMap(vector<Player*>);
	void setStartingRegion(Region* r);
	const string getName()const;
	vector<Continent*> getContinents();
	vector<vector<int>> getBorders();
	Region* getStartingRegion();
	
	//extra continent functions
	void determineStartingRegion();
	Continent* addContinent(int id, string name);
	void addContinent(Continent& continent);
	int getNbContinents() const;
	Continent* getContinentById(int id);
	bool areAdjacent(Continent* c1, Continent* c2);
	
	void setImmunePlayer(Player* p);
	Player* getImmunePlayer();
	
	vector<Player*> getPlayers();
	
	//extra Border functions
	int getNbBorders();
	void addBorder(vector<int> border);
	
	Continent* getRegionContinent(Region* r);
	
	//region methods
	int getNbRegions() const;
	Region* getRegionById(int id);
	bool hasRegionById(int id);
	bool areAdjacent(Region* r1, Region* r2);
	bool borderIsWater(Region* r1, Region* r2);
	
//	load the lists witht the map loader
	void loadContinents(vector<vector<string>> listContinents);
	void loadRegions(vector<vector<string>> listContinents);
	void loadBorders(vector<vector<string>> listBorders);
	void loadPlayers(vector<Player*> players);

	
// sub methods for validate (might be useful later also)
	bool connectedToOtherContinent(Region* r);
	bool connectedToOtherContinent(Continent * c);
	int getContinentIdofRegion(int regionId);
//	returns I
	
//	other functions
	bool canDestroy(Player* p);
	bool isNumber(string s);
	void printMap();
	void printRegions();
	void printContinents();
	bool validate(); 
	
// observer functions
	vector<Region*> getPlayersRegions(Player* p);
	int getPlayersTotalNbRegions(Player* p);
	int getPlayersTotalNbArmies(Player* p);
	int getPlayerTotalCities(Player* p);
	int getPlayersRegionsByContinent(Player* p, Continent* c);
	int getPlayersNbOfCities(Player* p);
	vector<Region*> getPlayerCities(Player* p);
	
	
	vector<pair<Player*, int>> compareTotalNumberOfRegions();
	vector<pair<Player*, int>> compareTotalNumberOfRegionsByContinent(Continent* c);
};

#endif