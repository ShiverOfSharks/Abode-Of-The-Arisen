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
string RoomID = "start"; // Where is the player right now, used for the first input since the player is not able to move north or west right at the beginning


//change string to "Room" 
string abode[4][4] = { {"1","2","3","4"},
					   {"5","6","7","8"},
					   {"9","10","11","12"},
					   {"13","14","15","16"},
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


//while loop accounting for all possible inputs, and if the user types anything else, the program will prompt the user to enter again - Doug
//Added validation off the start - Doug
void validateInput(string inp) 
{
	
	getline(cin, inp);

	input = inp;

	if (RoomID == "start")
	{
		while (inp != "MOVE EAST" && inp != "move east" && inp != "MOVE SOUTH" && inp != "move south")
		{
			cout << "You can only move either east or south, try again: ";
			getline(cin, inp);
			input = inp;
			
		}
	}
	else
	{
		while (inp != "MOVE NORTH" && inp != "move north"
			&& inp != "MOVE SOUTH" && inp != "move south"
			&& inp != "MOVE EAST" && inp != "move east"
			&& inp != "MOVE SOUTH" && inp != "move south"
			&& inp != "MOVE WEST" && inp != "move west"
			&& inp != "RESET" && inp != "reset"
			&& inp != "LOOK" && inp != "look")
		{
			cout << "Please enter a valid input response: \n";
			getline(cin, inp);
			input = inp;
		}
	}

	

}

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

/*
void move(string str) {
	
	if ("Moving north...")
		i++;
	playerPosition[i][j];

	
}
*/


string playerChoice(string ID, string inp){
	
	validateInput(inp);

	inp = input;

	if (inp == "MOVE NORTH" || inp == "move north")
	{
		cout << "Moving north..." << endl;
		return "Hallway North";
	}
	else if (inp == "MOVE SOUTH" || inp == "move south")
	{
		cout << "Heading south..." << endl;
		return "Hallway South";
	}
	else if (inp == "MOVE EAST" || inp == "move east")
	{
		cout << "Heading east..." << endl;
		return "Kitchen";
	}
	else if (inp == "MOVE WEST" || inp == "move west")
	{
		cout << "Heading west..." << endl;
		return "Living Room";
	}
	else if (inp == "RESET" || inp == "reset")
	{
		system("CLS"); //clear screen
		cout << "Starting over..." << endl;
		ID = "Start"; //setting the ID to start for now, can be changed later - Doug
		playerChoice(RoomID, input);

		//clear inventory
		//reset events
	}
	else if (inp == "LOOK" || inp == "look")
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

	cout_Abode();
	
	/* cout << "Head to the kitchen by putting in MOVE WEST. You can move to the other rooms later by putting in MOVE and the other three cardinal directions." << endl; 
	- I commented this out because the player can not move west on the start - Doug*/

	cout << "Choose to move either east or south: ";

	playerChoice(RoomID, input); // Call player choice and update room ID if needed, to then display the correct description. - Dorien

	//DisplayDescription(RoomID); // Move to next area. - Dorien //this function is writing to the console after the player resets the game - Doug

	//playerChoice(RoomID, input); // Call PC again - Dorien
	

	/*
	do{ //Game Loop
		
		//End Game conditions
		if(){} // At point 16 end game you won, lock room 16 until key is found
		else if(){} // Player health at 0, "Your Infected"
		else if(){} // Time out, 5min without input "Your Infected"

		playerChoice(RoomID, input);
		

	} while ();
	*/


	

	/*
	Player dylan("Dylan");
	dylan.getPlayerInvintory(); //retrival of elements not working

	Room hallway(1);
	cout<<hallway.getRoomName();
	hallway.getRoomInvintory(); //retrival of elements not working
	*/

	//cout<<"The player is in "<<r1.getRoomName();

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