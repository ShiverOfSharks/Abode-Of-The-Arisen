// Abode Of The Arisen - Build V0.0.1b
// By Dorien Fields, Douglas Grosch, Geoffery Gin, Dylan De Muth, & Angelique Mueller


//Imports
#include <stdlib.h>
#include <vector>
#include <array>
#include <string>
#include <iostream>

using namespace std;

int room; 
string move; 
string take;
string stuff; 
string item;
string quit; 

vector <string> inventory(4);


void DisplayBackstory(string name) // Displays the opening preamble. Called to first thing in main() - Dorien
{
	cout << "\n\nYour name is " << name << ". It's been a scant 5 days since the outbreak began, and life as you knew was turned into "
		<< "a walking\n nightmare. You were unprepared.You didn't have a chance to grab anything from your home in the city "
		<< "before you fled\n to the countryside, barely avoiding death or infection along the way. You found a house in the countryside "
		<< "that looks\n pretty defensible, but in your hurry, you tripped the security system's alarm, and now the undead close in." << endl;
	cout << endl;
	cout << "Instructions: " << endl;
	cout << "Commands, type (command) then enter to see furthur instructions - \n"
		<< "move - to move from room to room\n"
		<< "take - to take an item from room \n"
		<< "stuff - to see inventory\n"
		<< "quit - to quit the game" << endl;
	cout << endl;

}

void room_hall()
{
	cout << "You are in the the hall. \n"
		<< "The lights are dimmed and there's cobb webbs from floor to cieling.\n"
		<< "You spot the alram in the hall\n";
	string alarm;
	cin >> alarm; 
	if (alarm == "alarm")
	{
		cout << "what is the 4- number code to disable the alarm?" << endl;
		int password;
		cin >> password;
		if (password == 2190)
		{
			cout << "congrats you are still alive and won the game!!" << endl;
			exit(0);
		}
		else
		{
			cout << "wrong password" << endl;
			cout << endl;
		}
	}
	cout << endl;

}

void room_bathroom()
{
	cout << "You are now in the bathroom. \n"
		<< "The mirror is broken and the window is borded shut. \n "
		<< "You take a closer look on the mirror and see 11011011 - 0 in lipstick" << endl; 
	cout << endl;
}

void room_living()
{
	string option;

	cout << "You are now in the living room\n"
		<< "The couch is flipped over and there is an old key hanging on the wall" << endl; 
	cout << "OHH NOO There is a zombie in the far corner!!!" << endl;
	cout << "Do you want to attack or run" << endl; 
	cin >> option; 
	if (option == "attack")
	{
		cout << "attack with . . . " << endl; 
		cout << endl; 
		cout << "This is your inventory" << endl;
		for (string x : inventory)
		{
			cout << x << endl;
		}
		cout << endl;

		string weapon;
		cin >> weapon;

		if (weapon == "bat" || weapon == "knife")
		{
			cout << "zombie is dead" << endl;
		}
		else
		{
			cout << "You now died from the zombie" << endl; 
		}

	}
	else if (option == "run")
	{
		cout << "enter move to move to a different room" << endl; 
	}
	else
	{
		cout << "input a valid command (attack or run)" << endl; 
	}
	cout << endl;
}

void room_bedroom()
{
	cout << "You are now in the bedroom\n"
		<< "There is a chest at the foot of the bed\n"
		<< "And a baseball bat by the closet" << endl; 
	cout << endl;
}

void room_kitchen()
{
	cout << "you are now in the kitchen. \n"
		<< "There is a knife next to old rotten veggies" << endl;
	cout << endl; 
}

void RoomDisplays(int room)
{
	cout << "insert a number to select a room" << endl; 
	cout << "1 - Hall" << endl;
	cout << "2 - Bathroom" << endl;
	cout << "3 - Living Room" << endl;
	cout << "4 - Bedroom" << endl;
	cout << "5 - Kitchen" << endl;
	cout << endl;
}

void SelectRoom(int room)
{
	if (room == 1)
	{
		room_hall(); 
	}
	else if (room == 2)
	{
		room_bathroom();
	}
	else if (room == 3)
	{
		room_living();
	}
	else if (room == 4)
	{
		room_bedroom();
	}
	else if (room == 5)
	{
		room_kitchen(); 
	}
	else
	{
		cout << "Please insert a number to go to the room you want" << endl; 
	}
}


int main() {
	string input; 

	string getName;
	cout << "Enter your name: \n" << endl;
	getline(cin, getName);
	DisplayBackstory(getName);

	RoomDisplays(room);
	cin >> room;
	SelectRoom(room);

	int i;
	for (i = 0; i < 10; i++)
	{
		system("color 03");
		cin >> input;
		if (input != quit)
		{
			 if (input == "move")
			{
				RoomDisplays(room);
				cin >> room;
				SelectRoom(room);
			}
			else if (input == "take")
			{
				cout << "What item do you want to take?" << endl;
				cin >> item;
				if (item == "key")
				{
					string key;
					inventory.push_back("key");
				}
				else if (item == "bat")
				{
					string bat;
					inventory.push_back("bat");

				}
				else if (item == "knife")
				{
					string knife;
					inventory.push_back("knife");
				}
				else
				{
					cout << "please select an item to take" << endl;
				}
				cout << endl;
			}
			else if (input == "stuff")
			{
				cout << "This is your inventory" << endl;
				for (string x : inventory)
				{
					cout << x << endl;
				}
				cout << endl;
			}
		}
		else
		{
			exit(0);
		}
	}

	cout << "Too many moves, the zombies got to you" << endl;

} //main
