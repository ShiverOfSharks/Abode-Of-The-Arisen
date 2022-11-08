#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <list>
using namespace std;
class Player { //Player class
private:

	//Variables
	list<string> playerInvintory;
	int playerDamage;
	int playerHealth;
	std::string playerName;
	int playerPosition_X; //position of player in abode array, row
	int playerPosition_Y; //position of player in abode array, colomb 
public:
	
	//Methods
	Player();//default
	Player(std::string name);
	Player(std::string name, int damage, int health);
	void attack();
	std::string getPlayerName();
	int getPlayerDamage();
	void getPlayerInvintory();
	void setPlayerDamage(int newDamage);

	int getPlayerHealth();
	void setPlayerHealth(int newHealth);

	void setPlayerPos(int newPolayerPos_X, int newPlayerPos_y);
	int getPlayerPos_X();
	int getPlayerPos_Y();
};//class Player

#endif //PLAYER_H