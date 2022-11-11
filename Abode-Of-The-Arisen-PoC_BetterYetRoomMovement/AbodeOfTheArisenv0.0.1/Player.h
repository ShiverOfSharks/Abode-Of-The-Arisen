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

	void addPlayerInvintory(string newItem);
};//class Player

#endif //PLAYER_H