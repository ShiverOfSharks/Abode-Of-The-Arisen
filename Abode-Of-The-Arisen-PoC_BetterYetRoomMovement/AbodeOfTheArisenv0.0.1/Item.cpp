#include "Item.h"
#include <iostream>
#include <list>
using namespace std;



	//Constructor
	Item::Item(string name){
		setItemDamage(10);
		setItemName(name);
		setItemDescription("itemDescription");
		setEquipStatus(false);
	}

	 
	//Getter Methods
	int Item::getItemDamage() {
		return itemDamage;
	}

	string Item::getItemName(){
		return itemName;
	}

	string Item::getItemDescription() {
		return itemDescription;
	}

	bool Item::getEquipStatus() {
		return isWeapon;
	}

	//Setter Methods
	void Item::setItemDamage(int new_itemDamage) {
		itemDamage=new_itemDamage;
	}

	void Item::setItemName(string new_itemName) {
		itemName=new_itemName;
	}

	void Item::setItemDescription(string new_itemDescription) {
		itemDescription=new_itemDescription;
	}

	void Item::setEquipStatus(bool isEquippableNew) {
		isWeapon = isEquippableNew;
	}