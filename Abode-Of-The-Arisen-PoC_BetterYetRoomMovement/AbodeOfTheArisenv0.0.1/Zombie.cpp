#include "Zombie.h"
#include <iostream>
using namespace std;

/*
class Enemy { //Abstract class for all enemies
public:
	//Variables
	int damageAmount = 10;//Variable for damage
	//Methods
	virtual void attack() = 0;//Pure virtual function, always needs an override
};//class Enemy
*/
 
Enemy::Enemy(string name) {
	//Enemy(name, int damage)
	setEnemyName(name);
	setEnemyDamage(10);
}

Enemy::Enemy(string name, int damage) {
	setEnemyName(name);
	setEnemyDamage(damage);
}

void Enemy::attack() {
	
}

string Enemy::getEnemyName() {
	return enemyName;
}

int Enemy::getEnemyDamage() {
	return enemyDamage;
}

int Enemy::getEnemyHealth() {
	return enemyHealth;
}


void Enemy::setEnemyName(string newName) {
	enemyName = newName;
}
void Enemy::setEnemyDamage(int newDamage) {
	enemyDamage = newDamage;
}

void Enemy::setEnemyHealth(int newHealth) {
	enemyHealth = newHealth; 
}


void Enemy::setEnemyLocation(enum room roomID) {
	place == roomID;
}

void Enemy::getEnemyLocation(room roomID) {
	return roomID;
}
