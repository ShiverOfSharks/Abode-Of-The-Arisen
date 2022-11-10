#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

 //Constructors

Player::Player() {//Default Constructor
	playerInvintory = { "player","player","player" };
	playerName = "The Nameless";
	setPlayerDamage(10);
	int playerHealth=10;

	int playerPosition_X=0; 
	int playerPosition_Y=0;  
}

Player::Player(string name) { //Constructor, name only
	playerInvintory = { "player","player","player" };
	playerName = name;
	setPlayerDamage(10);
	int playerHealth = 10;

	int playerPosition_X = 0;
	int playerPosition_Y = 0;
}

Player::Player(string name, int damage, int health){ //Constructor, name/damage/health
	playerInvintory = { "player","player","player" };
	playerName = name;
	setPlayerDamage(damage);
	playerHealth = health;

	int playerPosition_X = 0;
	int playerPosition_Y = 0;
}

	// Getter Methods

	void Player::getPlayerInvintory() {
		cout << "\n";
		for (string temp : playerInvintory) //prints each element in list playerInvintory
			cout << temp << " ";
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

	void Player::setPlayerDamage(int new_playerDamage) {
		//cout << "\n\nYou now do " << newDamage << " damage to enemies!\n\n"; //prompt to user
		playerDamage = new_playerDamage;
	}


	void Player::setPlayerInvintory(string newItem) { //adds element to "playerInvintory" 
		//playerInvintory.add(newItem);
	}





	//Interaction Methods

	void Player::attack() {}

	void Player::setPlayerPos(int newPolayerPos_X, int newPlayerPos_y){ //sets new player positions in abode array
		playerPosition_X = newPolayerPos_X;
		playerPosition_Y = newPlayerPos_y;
	}

	int Player::getPlayerPos_X(){ //returns x position of player in abode array
		return playerPosition_X;
	}

	int Player::getPlayerPos_Y(){ //returns y position of player in abode array
		return playerPosition_Y;
	}