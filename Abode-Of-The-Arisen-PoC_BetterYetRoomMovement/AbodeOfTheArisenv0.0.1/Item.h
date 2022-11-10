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

	//Constructor
	Item(std::string name);

	//Getter Methods
	int getItemDamage();
	std::string getItemName();
	std::string getItemDescription();

	//Setter Methods
	void setItemDamage(int new_itemDamage);
	void setItemName(string new_itemName);
	void setItemDescription(string new_itemDescription);

};//class Player

#endif //ITEM_H