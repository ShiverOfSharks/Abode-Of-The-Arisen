#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;


Player::Player() {
	vector<string> playerInvintory = { "player","player","player" };
	playerName = "The Nameless";
	playerDamage = 10;
}

Player::Player(string name) {
	vector<string> playerInvintory = { "player","player","player" };
	playerName = name;
	playerDamage = 10;
}

Player::Player(string name, int damage) {
	vector<string> playerInvintory = { "player","player","player" };
	playerName = name;
	playerDamage = damage;
}

void Player::attack() {

}

string Player::getPlayerName() {
	return playerName;
}

int Player::getPlayerDamage() {
	return playerDamage;
}

void Player::getPlayerInvintory() {

	cout << "\n";
	for(string temp:playerInvintory) //prints each element in list playerInvintory
		cout<<temp<< " ";
	cout << "\n";
	
}
