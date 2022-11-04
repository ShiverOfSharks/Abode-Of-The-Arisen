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

	void getPlayerHealth();
	void setPlayerHealth(int newHealth);

};//class Player

#endif //PLAYER_H