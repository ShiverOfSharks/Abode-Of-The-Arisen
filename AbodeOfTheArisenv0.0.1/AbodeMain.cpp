// Abode Of The Arisen - Pre-Alpha Build V0.0.1b
// By Dorien Fields, Douglas Grosch, Geoffery Gin, Dylan De Muth, & Angelique Mueller


//Imports
#include "Zombie.h"
#include "Player.h"
#include "Room.h"
#include <stdlib.h>
#include <vector>
#include <array>
#include <string>

using namespace std;

//Global Variables
string input = "N/A";
bool AlarmOff = false; // Did the player turn off the alarm in the kitchen yet? - Dorien
string RoomID = "Hallway"; // Where is the player right now - will adjust to something less hard-code later - Dorien 
string abode[4][4] = { {"null","null","null","null"},
					   {"null","null","null","null"},
					   {"null","null","null","null"},
					   {"null","null","null","null"},
					 }; //abode, map of the map and accessable rooms

//void cout_Abode() incompleate
void cout_Abode() {//prints abode map, visualized for player
	for (int i = 0; i < 4; i++) {//forloop iterates through row

		std::cout << "\n"; //creates a space

		for (int j = 0; j < 4; j++) {//forloop iterates through col

			std::cout << abode[i][j]; //prints element in array
			if (j <= 2) std::cout << " | "; //lines of the board

		}//for inner

		if (i <= 2) std::cout << "\n_________________________\n";

	}//for outer

	std::cout << "\n\n\n";

}//void cout_abode

/* Displays a description of the current room depending on where the player is 
and what events have been completed. - Dorien*/

void DisplayDescription(string ID)
{

	if (ID == "Hallway")
	{
		cout << "You're still in the middle of the hallway. There's not much to do here other than connect to the other rooms right now." << endl;
	}
	else if (AlarmOff = false && ID == "Kitchen")
	{
		cout << "You're in the kitchen, and from here that damnable alarm is still going off, a little beep coming from...somewhere." << endl << "Type LOOK AROUND to take a general better look of things." << endl;
	}

	/* So on and so forth for the other rooms.
	We'll need to revisit this later when we redesign the room movement code,
	but this'll work for now. - Dorien. */
}



/* LookAround command: Gives extra general information on the current room. - Dorien */

void LookAround(string ID)
{
	if (AlarmOff = false && ID == "Kitchen")
	{
		cout << "You finally locate that alarm, and shut it off. Sweet relief! Now you should be able to explore the rest of the house without attracting more of the undead." << endl;
		AlarmOff = true;
	}
}

/* Allows player to input where they would like to go.
For the demo build, assume all movement is from hallway only. - Dorien */


void playerChoice(string ID, string inp)
{
	getline(cin, inp);

	/* Player inputs where they want to go.
	What I suggest is having the RoomID char variable update depending on where they are,
	Then have a DisplayDescription function and LookAround function check which
	room they're in to display the proper description. I did an example for moving into the kitchen. - Dorien */

	if (inp == "MOVE NORTH")
	{
		cout << "Moving north..." << endl;
		ID = "Hallway North";
	}
	else if (inp == "MOVE SOUTH")
	{
		cout << "Heading south..." << endl;
		ID = "Hallway South";
	}
	else if (inp == "MOVE EAST")
	{
		cout << "Heading east..." << endl;
		ID = "Kitchen";
	}
	else if (inp == "MOVE WEST")
	{
		cout << "Heading west..." << endl;
		ID = "Living Room";
	}
	else if (inp == "RESET")
	{
		//ID = "Start"; //setting the ID to start for now, can be changed later - Doug
		system("CLS"); //clear screen
		cout << "Starting over..." << endl;
		
		//clear inventory
		//reset events
	}
	else if (inp == "LOOK AROUND" || "look around")
	{
		LookAround(ID);
	}
	
	else
	{
		cout << "Invalid input, try again." << endl;
	}

}

void DisplayBackstory() // Displays the opening preamble. Called to first thing in main() - Dorien
{
	cout << "Your name is Anonymous. It's been a scant 5 days since the outbreak began, and life as you knew was turned into a walking nightmare." << endl;
	cout << "You were unprepared. You didn't have a chance to grab anything from your home in the city before you fled to the countryside, barely avoiding death or infection along the way." << endl;
	cout << "You found a house in the countryside that looks pretty defensible, but in your hurry, you tripped the security system's alarm, and now the undead close in." << endl;
	cout << endl; //separate directions from player instructions
	cout << "You are in a hallway. Type MOVE [Direction] (NORTH, SOUTH, EAST, or WEST) to move in that direction. Type LOOK to have a look at your surroundings." << endl;
	cout << "Type LOOK AT to look at more specific points or items of interest. Type PICK UP to grab something, and type STUFF to see your inventory." << endl;
	cout << "If you ever get stuck, type RESET to give into the zombie hor-er, I mean, reset the game to here." << endl;
	cout << "You should probably find a way to shut that alarm off...the controls should be in the kitchen to your east." << endl;
	// This shouldn't call playerchoice - playerchoice is going to be called whenever they want to move, backstory only displays once - Dorien
}

int main()
{

	system("color 04"); //changes color of console 



	DisplayBackstory();
	
	cout << "Head to the kitchen by putting in MOVE WEST. You can move to the other rooms later by putting in MOVE and the other three cardinal directions." << endl;

	//playerChoice(RoomID, input); // Call player choice and update room ID if needed, to then display the correct description. - Dorien

	//DisplayDescription(RoomID); // Move to next area. - Dorien //this function is writing to the console after the player resets the game - Doug

	//playerChoice(RoomID, input); // Call PC again - Dorien
	


	cout_Abode();

	Player dylan("Dylan");
	dylan.getPlayerInvintory(); //retrival of elements not working

	Room hallway(1);
	cout<<hallway.getRoomName();
	hallway.getRoomInvintory(); //retrival of elements not working

	/*//Enemy/ Zombie test
	Enemy theZombie("zombie");
	theZombie.attack();
	cout << theZombie.getEnemyName()<<"\n" << theZombie.getEnemyDamage()<<endl;

	Enemy monster2("Ogre",100);
	monster2.attack();
	cout << monster2.getEnemyName()<< "\n" << monster2.getEnemyDamage()<<endl;

	*/
	return 0; // Exit program successfully.
}