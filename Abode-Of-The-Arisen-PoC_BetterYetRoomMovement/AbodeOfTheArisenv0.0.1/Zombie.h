#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>

class Enemy { //Zombie class
private:

	//Variables
	int enemyDamage;
	int enemyHealth;
	std::string enemyName;
	enum enemyLocation place;
public:
	 
	//Methods
	Enemy(std::string name);
	Enemy(std::string name, int damage);
	void attack();
	std::string getEnemyName();
	int getEnemyDamage();
	int getEnemyHealth();
	void getEnemyLocation();

	void setEnemyName(std::string newName);
	void setEnemyDamage(int newDamage);
	void setEnemyLocation(enum room roomID); 
	void setEnemyHealth(int newHealth);


};//class Zombie : public Enemy

#endif //ENEMY_H