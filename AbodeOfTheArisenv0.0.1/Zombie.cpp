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
	//Enemy( name, int damage)
	enemyName = name;
	enemyDamage = 10;
}

Enemy::Enemy(string name, int damage) {
	enemyName = name;
	enemyDamage = damage;
}

void Enemy::attack() {
	
}

string Enemy::getEnemyName() {
	return enemyName;
}

int Enemy::getEnemyDamage() {
	return enemyDamage;
}
