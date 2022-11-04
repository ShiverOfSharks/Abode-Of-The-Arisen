#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;


Player::Player() {//Default Constructor 
	vector<string> playerInvintory = { "player","player","player" };
	playerName = "The Nameless";
	playerDamage = 10;
	int playerHealth=10;
}

Player::Player(string name) { //Constructor, name only
	vector<string> playerInvintory = { "player","player","player" };
	playerName = name;
	playerDamage = 10;
	int playerHealth = 10;
}

Player::Player(string name, int damage, int health) { //Constructor, name and damage 
	vector<string> playerInvintory = { "player","player","player" };
	playerName = name;
	playerDamage = damage;
	playerHealth = health;
}

void Player::attack() {

}

string Player::getPlayerName() {
	return playerName;
}

int Player::getPlayerDamage() {
	return playerDamage;
}

void Player::setPlayerDamage(int newDamage) {
	cout << "\n\nYou now do " << newDamage << " damage to enemies!\n\n";
	playerDamage=newDamage;
}

void Player::getPlayerInvintory() {

	cout << "\n";
	for(string temp:playerInvintory) //prints each element in list playerInvintory
		cout<<temp<< " ";
	cout << "\n";
	
}
