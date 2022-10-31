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
	std::string playerName;
public:

	//Methods
	Player();//default
	Player(std::string name);
	Player(std::string name, int damage);
	void attack();
	std::string getPlayerName();
	int getPlayerDamage();
	void getPlayerInvintory();
	//void startGame();//holds the game loop
};//class Player

#endif //PLAYER_H