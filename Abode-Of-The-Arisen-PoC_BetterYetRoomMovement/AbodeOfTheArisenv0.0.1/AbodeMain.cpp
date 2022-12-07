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
#include <algorithm> 

#define INPUT_ERROR "ERROR"


//Global Variables + Event Flags
string input = "N/A";
bool AlarmOff = false; // Event Flag: Did the player turn off the alarm in the kitchen yet? - Dorien
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
enum Rooms { HALLWAY = 0, BATHROOM = 1, BEDROOM = 2, ERROR = 99 };
string roomStrings[NUM_ROOMS] = { "Entry Way", "BATHROOM", "BEDROOM" };

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
string validateInput(string inp) 
{

	if (RoomID == "DefunctForNow") //player first spawns and should only move EAST and SOUTH
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

	if (ID == "Entry Way")
	{
		cout << "You're still in the middle of the hallway. There's not much to do here other than connect to the other rooms right now." << endl;
	}
	else if (AlarmOff = false && ID == "Kitchen")
	{
		cout << "You're in the kitchen, and from here that damnable alarm is still going off, a little beep coming from...somewhere." << endl << "Type LOOK AROUND to take a general better look of things." << endl;
	}
	else if (ID == "BATHROOM") 
	{
		cout << "You're in the bathroom. The air in here is cold - it's clearly not been used in a while, and the sink is dry. Maybe there'll be something of use in here later." << endl;
	}
	else if (ID == "BEDROOM") 
	{
		cout << "This would be the first floor bedroom - this was clearly the master bedroom as well. A large bed, two dressers, and a cabinet across, with TV, connected bathroom, the works. Might be a good place to rest, if not for the clawing arms at the windows and moans behind the walls..." << endl;
	}

}

// Professor Vallone's Parser being inplemented. - Dorien

string playerChoice()
{
	string inp;
	//cout << endl;
	cout << "What would you like to do? ";
	getline(cin, inp); //takes user input
	cout << "**" << inp << "**";

	// validateInput(inp); //validates user input
	// Separate user input into a command (e.g. move, look, reset) & a parameter (e.g. north)
	// string format should be: <whitespace?>command<whitespace>parameter<whitespace/endl>

	// first normalize string to all upper case
	std::transform(inp.begin(), inp.end(), inp.begin(), ::toupper);

	// then loop through string, first removing whitespace, then 
	vector <char> command;
	vector <char> parameter;
	int i = 0;  // character position in string
	if (inp.length() <= 2) {    // bad - but quick
		std::cout << "Invalid entry " << inp << " Please renter ...\n";
		return INPUT_ERROR;
	}

	while (isspace(inp[i])) {
		cout << "inp[i] " << inp[i];
		i++;
	}
	cout << std::endl;
	while (!isspace(inp[i]) && (inp[i] != '\0')) {
		cout << "\ti " << i << "  inp[i] " << inp[i];
		command.push_back(inp[i]);
		i++;
	}
	// command.push_back('\0');  // terminate string
	cout << std::endl;
	// move past white space, but if end of line - stop  --- note: this breaks if no end of line
	while (isspace(inp[i]) && (inp[i] != '\0')) {
		i++;
	}
	while (!isspace(inp[i]) && (inp[i] != '\0')) {
		parameter.push_back(inp[i]);
		i++;
	}

	// done - no need to go any further
	// at this point - command has the command, parameter - if present - has the direction, etc.
	string commandString(command.begin(), command.end());
	string parameterString(parameter.begin(), parameter.end());

	cout << "Command **" << commandString << "**" << std::endl;
	cout << "Parameter " << parameterString << std::endl;  // may not work

	/* Proposed implementation - use nested if for movement, calling validateinput() to check before returning parameter string
	(as current room movement works on parameter, not command) - Dorien */

	if (commandString == "MOVE")  // ParameterString is the direction, so when it's called in main, that's what move needs to be for the code to work properly. - Dorien
	{
		if (parameterString == "WEST") 
		{
			return parameterString;
		}
		else if (parameterString == "EAST")
		{
			return parameterString;
		}
		else if (parameterString == "NORTH")
		{
			return parameterString; 
		}
		else if (parameterString == "SOUTH")
		{
			return parameterString;
		}
	}
	else if (commandString == "RESET") 
	{
		// validateInput(inp);
		// Reset the game. Deferring this to later. - Dorien
		return "Game reset! Close the window now.";
	}
	else if (commandString == "LOOK") 
	{
		DisplayDescription(RoomID);
		return parameterString;
	}

	return "Something has gone wrong - this was supposed to output parameterString and proc movement.";

}

 
void DisplayBackstory(string name) // Displays the opening preamble. Called to first thing in main() - Dorien
{
	cout << "\n\nYour name is "<<name<<". It's been a scant 5 days since the outbreak began, and life as you knew was turned into "
		 <<"a walking\n nightmare. You were unprepared.You didn't have a chance to grab anything from your home in the city "
		 <<"before you fled\n to the countryside, barely avoiding death or infection along the way. You found a house in the countryside "
		 <<"that looks\n pretty defensible, but in your hurry, you tripped the security system's alarm, and now the undead close in." << endl;

	cout << "\n\nYou are in a hallway. Type MOVE [Direction] (NORTH, SOUTH, EAST, or WEST) to move in that direction.\n Type LOOK to have a look at your surroundings."
		 << "Type PICK UP to grab something, and type STUFF to see your inventory.\n" 
		 << " If you ever get stuck, type RESET to give into the zombie hor-er, I mean, reset the game to here."
		 << "You should probably\n find a way to shut that alarm off...the controls should be in the kitchen to your east.\n\n";

}


 //Zombie interaction
int zombieAttack() {
	string tempInput;
	
	cout << "YOU ARE ATTACKED BY A ZOMBIE!!!";
	Enemy theZombie("zombie");
	theZombie.attack();
	cout << theZombie.getEnemyName() << "\n" << theZombie.getEnemyDamage() << endl;
	cout << "\n Would you like to run or fight\n Enter 'run' or 'fight': ";
	cin >> tempInput;

	//logic
	if (tempInput == "run") {
		int randomNum = rand() % 4;
		if (randomNum == 0) return 0;// "return 0" is a place holder until the parser in this code is fixed, reutrn movement when fixed
		//move north
		else if (randomNum == 1) return 0;
		//move east
		else if (randomNum == 2) return 0;
		//move south
		else return 0;
			//move west
			return theZombie.getEnemyDamage(); //To be subtracted from player health, posibly lower health over 3 cycles of game loop
	}//if(tempInput == "run")

	else {
		//invoke combat method then return calculation
		return 0;
	}//else
}//zombieAttack()




int main(){

	system("color 9e"); //changes color of console
	
	//Create player object using user input as name, not validated
	cout << "Name of Survivor: ";
	string tempName;
	cin >> tempName;
	Player player(tempName); //creates object with name input from user
	system("cls");


	//Game loop related variables
	int roomID = HALLWAY;   // set to starting room
	int count = 0; //checks the iteration of game loop


	//Game Loop
	do{ 

		
		if (count == 0) {
			player.printPlayerStats(); //Diagnostics for "player" 
			DisplayBackstory(player.getPlayerName()); //prints backstory with player's name inserted into it
			cout << "Start Game\n"; //prompts user that game has started
			system("Pause"); //pauses system till player is ready to start game
			system("color 04"); //changes color of console 
		}

		//End Game conditions
		if (player.getPlayerHealth() == 0){
			break; // Player health at 0, "You're Infected"
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

		string move = playerChoice();
		cout << "You entered: " << move << endl;
		if (move == INPUT_ERROR) {
			count++;  // increment count so we don't repeat backstory, even though not a valid move
			continue;
		}


		// zombieAttack(); //Zombie attacks player, run or fight

		// PoC for room movement
		// new roomID is derived from current room structure (roomArray[] ) for user specified direction (e.g. go to north)
		// Move is derived from ParameterString in new parser, as it is referring to the direction. - Dorien
		if (move == "north") {
			roomID = roomArray[roomID].goToNorth;
			Room newRoom(roomID);
			cout<<"\n\n"<<newRoom.getRoomDescription()<<"\n\n";
			newRoom.printRoomInventory();
		}
		else if (move == "south") {
			roomID = roomArray[roomID].goToSouth;
			Room newRoom(roomID);
			cout << "\n\n" << newRoom.getRoomDescription() << "\n\n";
			newRoom.printRoomInventory();
		}
		else if (move == "west") {
			roomID = roomArray[roomID].goToWest;
			Room newRoom(roomID);
			cout << "\n\n" << newRoom.getRoomDescription() << "\n\n";
			newRoom.printRoomInventory();
		}
		else if (move == "east") {
			roomID = roomArray[roomID].goToEast;
			Room newRoom(roomID);
			cout << "\n\n" << newRoom.getRoomDescription() << "\n\n";
			newRoom.printRoomInventory();
		}
		//CURRENTLY NOT FUNCTIONAL DUE TO INPUT ISSUES
		//user interactions
		else if (move == "quit") {
			break;
		}
		else if (move == "pick up") {
			Room newRoom(roomID); //creates new room, find better way of accessing room
			player.addPlayerInvintory(newRoom.getRoomInventory()); //gets first item from the room invintory then adds that item to the player invintory
		}
		 
		cout << "\n\nYou are now in = " << roomStrings[roomID] << endl;

		/// FOR TESTING REMOVE WHEN QUITE INPUT WORKS ///
		if (count == 4) break; //ends loop after 4 inputs because can not quit from user input
		/// FOR TESTING REMOVE WHEN QUITE INPUT WORKS ///


	count++; //itterates the loop count
	}while (true);
	
	//Ending Prompts to user
	cout << "\n\n\t   GAME OVER\n";
	if (player.getPlayerHealth() != 0) cout << "\tYou Survived!!!\n"; //player "survives" if the game ends and their health is not 0
	cout << "\tYou made " << count << " moves.\n\n";

	//looks nicer
	system("pause"); //pauses console
	system("cls"); //clears console

} //main