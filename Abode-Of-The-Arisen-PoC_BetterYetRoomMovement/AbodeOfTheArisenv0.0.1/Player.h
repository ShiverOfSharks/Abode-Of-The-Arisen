#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <list>
#include "Item.h" //includes "Item" class objects for list
using namespace std;
class Player { //Player class
private:

	//Variables
	list<Item> playerInvintory;
	int playerDamage;
	int playerHealth;
	std::string playerName;
	int playerPosition_X; //position of player in abode array, row
	int playerPosition_Y; //position of player in abode array, colomb 
public:
	
	//Constructors
	Player();//default
	Player(std::string name);
	Player(std::string name, int damage, int health);
	 
	std::string getPlayerName();
	int getPlayerDamage();
	void getPlayerInvintory();
	int getPlayerHealth();

	//Setter Methods
	void setPlayerHealth(int newHealth);
	void setPlayerDamage(int newDamage);

	//Interation Mehtods
	void attack();

	void setPlayerPos(int newPolayerPos_X, int newPlayerPos_y);
	int getPlayerPos_X();
	int getPlayerPos_Y();

	void addPlayerInvintory(string newItem);
};//class Player

#endif //PLAYER_H