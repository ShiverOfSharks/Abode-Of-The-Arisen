#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Item { //Player class
private:

	//Variables
	int itemDamage;
	std::string itemName;

public:

	//Methods
	Item(std::string name);
	std::string getItemName();

};//class Player

#endif //ITEM_H