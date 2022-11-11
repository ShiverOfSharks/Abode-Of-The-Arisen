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
	std::string itemDescription;

public:

	//Methods
	Item(std::string name);
	std::string getItemName();
	std::string getItemDescription();

};//class Player

#endif //ITEM_H