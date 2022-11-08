#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;


Player::Player() {//Default Constructor
	playerInvintory = { "player","player","player" };
	playerName = "The Nameless";
	playerDamage = 10;
	int playerHealth=10;

	int playerPosition_X=0; 
	int playerPosition_Y=0;  
}

Player::Player(string name) { //Constructor, name only
	playerInvintory = { "player","player","player" };
	playerName = name;
	playerDamage = 10;
	int playerHealth = 10;

	int playerPosition_X = 0;
	int playerPosition_Y = 0;
}

Player::Player(string name, int damage, int health) { //Constructor, name and damage
	playerInvintory = { "player","player","player" };
	playerName = name;
	playerDamage = damage;
	playerHealth = health;

	int playerPosition_X = 0;
	int playerPosition_Y = 0;
}

void Player::attack() {

}

void Player::setPlayerDamage(int newDamage) {
	cout << "\n\nYou now do " << newDamage << " damage to enemies!\n\n";
	playerDamage=newDamage;
}

int Player::getPlayerHealth()
{
	return playerHealth;
}

void Player::getPlayerInvintory() {

	cout << "\n";
	for(string temp:playerInvintory) //prints each element in list playerInvintory
		cout<<temp<< " "; 
	cout << "\n";
}

void Player::setPlayerPos(int newPolayerPos_X, int newPlayerPos_y) { //sets new player positions in abode array
	playerPosition_X = newPolayerPos_X;
	playerPosition_Y = newPlayerPos_y;
}

int Player::getPlayerPos_X() { //returns x position of player in abode array
	return playerPosition_X;
}

int Player::getPlayerPos_Y() { //returns y position of player in abode array
	return playerPosition_Y;
}