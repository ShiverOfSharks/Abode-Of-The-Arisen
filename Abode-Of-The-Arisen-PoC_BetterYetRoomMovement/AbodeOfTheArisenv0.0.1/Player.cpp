#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

 //Constructors

Player::Player() {//Default Constructor
	playerInvintory;
	playerName = "The Nameless";
	setPlayerDamage(10);
	setPlayerHealth(10);
}

Player::Player(string name) { //Constructor, name only
	playerInvintory;
	playerName = name;
	setPlayerDamage(10);
	setPlayerHealth(10);
}
 
Player::Player(string name, int damage, int health){ //Constructor, name/damage/health
	playerInvintory;
	playerName = name;
	setPlayerDamage(damage);
	setPlayerHealth(health);
}

	// Getter Methods

	void Player::getPlayerInvintory() {
		cout << "\n";
		if (playerInvintory.size() == 0)
			cout << "	No Items.";
		else
			for (Item temp : playerInvintory) //prints each elements' name string
				cout << temp.getItemName() << " ";
		cout << "\n";
	}

	int Player::getPlayerHealth(){
		return playerHealth; 
	}

	std::string Player::getPlayerName()
	{
		return playerName;
	}

	int Player::getPlayerDamage() {
		return playerDamage; 
	}


	//Setter Methods

	void Player::setPlayerHealth(int new_playerHealth)
	{
		playerHealth=new_playerHealth;
	}

	void Player::setPlayerDamage(int new_playerDamage) {
		//cout << "\n\nYou now do " << newDamage << " damage to enemies!\n\n"; //prompt to user
		playerDamage = new_playerDamage;
	}


	void Player::addPlayerInvintory(string newItem) { //adds element to "playerInvintory" 
		playerInvintory.push_back(newItem);
	}





	//Interaction Methods
	void Player::printPlayerStats(){ //couts player related information
	
		cout << "Your name is " << getPlayerName()
			<< "\nYour stats are:\nDamage: " << getPlayerDamage()
			<< "\nHealth is " << getPlayerHealth()
			<< "\nThe items in your invintory: ";
		getPlayerInvintory();
	
	}

	void Player::attack() {}
