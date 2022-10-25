#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>

class Enemy { //Zombie class
private:

	//Variables
	int enemyDamage;
	std::string enemyName;
public:

	//Methods
	Enemy(std::string name);
	Enemy(std::string name, int damage);
	void attack();
	std::string getEnemyName();
	int getEnemyDamage();
};//class Zombie : public Enemy


#endif //ENEMY_H