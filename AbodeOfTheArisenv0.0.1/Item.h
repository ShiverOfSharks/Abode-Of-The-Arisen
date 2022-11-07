#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <list>
using namespace std;
class Player { //Player class
private:

	//Variables
	int itemDamage;
	std::string playerName;

public:

	//Methods
	Player(std::string name);
	std::string getItemName();

};//class Player

#endif //ITEM_H