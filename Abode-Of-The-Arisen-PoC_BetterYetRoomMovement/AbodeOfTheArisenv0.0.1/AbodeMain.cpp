// Abode Of The Arisen - Build V0.0.1b
// By Dorien Fields, Douglas Grosch, Geoffery Gin, Dylan De Muth, & Angelique Mueller


//Imports
#include "Zombie.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
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
string abode[4][4] = { {"Bed Room","Hallway","Bath Room","Bath Room"},
					   {"Bed Room","Hallway","Bath Room","Bath Room"},
					   {"Kitchen","Hallway","Living Room","Living Room"},
					   {"Kitchen","Hallway","Living Room","Living Room"},
					 }; //abode, map of the map and accessable rooms

// PoC - alternative way to navigating between rooms using similar approach
//   Define the # of rooms so we can define the room array
//   Create enums & string names for each room (Important - ToDo error checking, # of rooms MUST be consistent
//   Initialize room movement array
// ToDo - initialize room objects here as well - storing in an appropriate structure (possibly vector?)
#define NUM_ROOMS 3
enum Rooms { HALLWAY = 0, BATHROOM = 1, BEDROOM = 2, ERROR = 99};
string roomStrings[NUM_ROOMS] = {"Entry Way", "BATHROOM", "BEDROOM"};

struct RoomMap {
	int roomId;   // unique room identifier
	int goToNorth;   // North
	int goToSouth;   // South
	int goToWest;    // West
	int goToEast;	 // East
};

RoomMap roomArray[NUM_ROOMS] = { 
	{HALLWAY, BATHROOM, BEDROOM, BATHROOM, HALLWAY},  // Current room is Hallway, north goes to bathroom, south to bedroom
	{BATHROOM, HALLWAY, BEDROOM, BATHROOM, HALLWAY},  // current room bathroom
	{BEDROOM, HALLWAY, BATHROOM, BATHROOM, HALLWAY}   // current room bedroom
};


//void cout_Abode() incompleate 
void cout_Abode() {//prints abode map, visualized for player
	for (int i = 0; i < 4; i++) {//forloop iterates through row

		std::cout << "\n"; //creates a space

		for (int j = 0; j < 4; j++) {//forloop iterates through col

			std::cout << abode[i][j]; //prints element in array
			if (j <= 2) std::cout << " | "; //lines of the board

		}//for inner

		if (i <= 2) std::cout << "\n_____________________________________________\n";

	}//for outer

	std::cout << "\n\n\n";

}//void cout_abode

//while loop accounting for all possible inputs, and if the user types anything else, the program will prompt the user to enter again - Doug
string validateInput() 
{
	string inp;
	
	getline(cin, inp);

	// input = inp;

	if (RoomID == "removeForNow") //player first spawns and should only move EAST and SOUTH
	{
		while (inp != "MOVE EAST" && inp != "move east" && inp != "MOVE SOUTH" && inp != "move south")
		{
			cout << "You can only move either east or south, try again: ";
			getline(cin, inp);
			// input = inp;
			
		}
	}
	else //player can move any direction
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
			// input = inp;
		}
	}
	return inp;
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
	// get rid of white space
	// change everything to either upper or lower case
	// add quit, exit

	if (inp == "MOVE NORTH" || inp == "move north")
	{
		cout << "Moving north..." << endl;
		return "north";
	}
	else if (inp == "MOVE SOUTH" || inp == "move south")
	{
		cout << "Heading south..." << endl;
		return "south";
	}
	else if (inp == "MOVE EAST" || inp == "move east")
	{
		cout << "Heading east..." << endl;
		return "east";
	}
	else if (inp == "MOVE WEST" || inp == "move west")
	{
		cout << "Heading west..." << endl;
		return "west";
	}
	else if (inp == "RESET" || inp == "reset")
	{
		system("CLS"); //clear screen
		cout << "Starting over..." << endl;
		ID = "Start"; //setting the ID to start for now, can be changed later - Doug
		playerChoice(RoomID, input);

		//reset events
	}
	else if (inp == "LOOK" || inp == "look")
	{
		//"LookAround(ID)" is now "getRoomDescription()"
		//getRoomDescription();
	}
	else
	{
		cout << "Invalid input, try again." << endl;
	}
	return "ERROR";

}


void DisplayBackstory(string name) // Displays the opening preamble. Called to first thing in main() - Dorien
{
	cout << "Your name is "<<name<<". It's been a scant 5 days since the outbreak began, and life as you knew was turned into "
		 <<"a\n walking nightmare.You were unprepared.You didn't have a chance to grab anything from your home in the city\n "
		 <<"before you fled to the countryside, barely avoiding death or infection along the way. You found a house in\n the countryside "
		 <<"that looks pretty defensible, but in your hurry, you tripped the security system's alarm,\n and now the undead close in." << endl;
	cout << endl; //separate directions from player instructions
	cout << "You are in a hallway. Type MOVE [Direction] (NORTH, SOUTH, EAST, or WEST) to move in that direction. Type LOOK to have a look at your surroundings." << endl;
	cout << "Type LOOK AT to look at more specific points or items of interest. Type PICK UP to grab something, and type STUFF to see your inventory." << endl;
	cout << "If you ever get stuck, type RESET to give into the zombie hor-er, I mean, reset the game to here." << endl;
	cout << "You should probably find a way to shut that alarm off...the controls should be in the kitchen to your east." << endl;

}

void zombieAttack() {
	cout << "YOU ARE ATTACKED BY A ZOMBIE!!!";
	Enemy theZombie("zombie");
	theZombie.attack();
	cout << theZombie.getEnemyName() << "\n" << theZombie.getEnemyDamage() << endl;
	cout << "\n Would you like to run or fight\n Enter 'run' or 'fight': ";

}


int main()
{
	system("color 9e"); //changes color of console
	


	//put player diagnostics in a method so player can call it 

	//Diagnostics for "player" 
	Player player("Dylan");
	cout << "Your name is " << player.getPlayerName()
		<< "\nYour stats are:\nDamage: " << player.getPlayerDamage()
		<< "\nHealth is " << player.getPlayerHealth()
		<< "\nThe items in your invintory: ";
	player.getPlayerInvintory();
	
	cout << "\n\n";
	DisplayBackstory(player.getPlayerName());
	cout << "\n";


	/*
	Room hallway(1);
	cout<<hallway.getRoomName();
	hallway.getRoomInvintory();
	*/



	//Game loop related variables
	int roomID = HALLWAY;   // set to starting room
	int count = 0; //checks the iteration of game loop

	//Game Loop
	do{ 
		
		if (count == 0) {
			cout << "Start Game\n";
			system("Pause");
			system("color 04"); //changes color of console 
		}

		//End Game conditions
		if (player.getPlayerHealth() == 0){
			break; // Player health at 0, "Your Infected"
		}

		/*
		if(){break;} // At point 16 end game you won, lock room 16 until key is found
		else if(){break;} // Time out, 5min without input "Your Infected"
		*/

		//  Slight rework of console input processing
		//  Separate out getting player input & validating from
		//  Parsing the input and returning the command (e.g. north - from MOVE NORTH)
		//  Note - this separation is required to support automated testing, as otherwise the test code
		//    will just wait forever
		cout << "What direction would you like to move (North, East, South, West): ";
		string playerInput = validateInput();
		string move = playerChoice(RoomID, playerInput);


		/*
		//NOTE: intagrate interations into "playerInput"
		//Interaticions besides moving
		//cout<< "Would you like to do something(y/n): ";
		if (cin)
			interact()
		else
			continue;
		*/









		// zombieAttack(); //Zombie attacks player, run or fight

		// PoC for room movement
		// new roomID is derived from current room structure (roomArray[] ) for user specified direction (e.g. go to north)
		if (move == "north") {
			roomID = roomArray[roomID].goToNorth;
		}
		else if (move == "south") {
			roomID = roomArray[roomID].goToSouth;
		}
		else if (move == "west") {
			roomID = roomArray[roomID].goToWest;
		}
		else if (move == "east") {
			roomID = roomArray[roomID].goToEast;
		}
		cout << "\n\nYou are now in = " << roomStrings[roomID] << endl;

	count++;
	}while (true);

	cout << "\n\nGAME OVER\nYou made "<<count<<" moves.\n\n\n\n\n";
	
	

	/*//Enemy/ Zombie test
	Enemy theZombie("zombie");
	theZombie.attack();
	cout << theZombie.getEnemyName()<<"\n" << theZombie.getEnemyDamage()<<endl;

	Enemy monster2("Ogre",100);
	monster2.attack();
	cout << monster2.getEnemyName()<< "\n" << monster2.getEnemyDamage()<<endl;
	*/

	//looks nicer
	system("pause"); //pauses console
	system("cls"); //clears console

} //main