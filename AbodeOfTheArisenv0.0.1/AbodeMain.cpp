// Abode Of The Arisen - Pre-Alpha Build V0.0.1b
// By Dorien Fields, Douglas Grosch, Geoffery Gin, Dylan De Muth, & Angelique Mueller


/* Global variable defintions go here. - Dorien */
#include "Zombie.h"
#include "AbodeHeader.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>   // for transforming string to upper case, ToDo include only the string portion of the library

using namespace std;

string input = "N/A";
bool AlarmOff = false; // Did the player turn off the alarm in the kitchen yet? - Dorien
bool isStart;
string RoomID = "Hallway"; // Where is the player right now - will adjust to something less hard-code later - Dorien 
vector <string> playerInventory  = {"Item1","Item2","Item3"};

void DisplayBackstory();

//#define Abode[3][3]; // Floor layout. Used to denote where the player is, and as a check for events and possible dialogue. Very integral. - Dorien

// Had to comment out the line of code above because it was causing an error - Doug


/* Functions go here. Only make calls in main(), please do NOT
	define functions in main(). And of course, make sure to
	follow coding standards. - Dorien */

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

void showInventory()
{

}


void validateInput(string inp) //while loop accounting for all possible inputs, and if the user types anything else, the program will prompt the user to enter again
{

	while (inp != "MOVE NORTH" && inp != "move north"
		&& inp != "MOVE SOUTH" && inp != "move south"
		&& inp != "MOVE EAST" && inp != "move east"
		&& inp != "MOVE SOUTH" && inp != "move south"
		&& inp != "MOVE WEST" && inp != "move west"
		&& inp != "RESET" && inp != "reset"
		&& inp != "LOOK" && inp != "look"
		&& inp != "PICK UP" && inp != "pick up")
	{
		cout << "Please enter a valid input response: \n";
		getline(cin, inp);
	}

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
Let's go ahead and make sure this works like a well-oiled machine;
It's the heart of our code! - Dorien */


string playerChoice(string inp)
{
	//cout << endl;
	cout << "What would you like to do? ";
	getline(cin, inp); //takes user input

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
		return NULL;
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
	command.push_back('\0');  // terminate string
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

	cout << "Command " << commandString << std::endl;
	cout << "Parameter " << parameterString << std::endl << std::endl;  // may not work

	return commandString;
	/*
	

	if (inp == "MOVE NORTH" || inp == "move north")
	{
		cout << "Moving north..." << endl;
		ID = "Hallway North";
	}
	else if (inp == "MOVE SOUTH" || inp == "move south")
	{
		cout << "Heading south..." << endl;
		ID = "Hallway South";
	}
	else if (inp == "MOVE EAST" || inp == "move east")
	{
		cout << "Heading east..." << endl;
		ID = "Kitchen";
	}
	else if (inp == "MOVE WEST" || inp == "move west")
	{
		cout << "Heading west..." << endl;
		ID = "Living Room";
	}
	else if (inp == "RESET" || inp == "reset")
	{
		system("CLS"); //clear screen
		cout << "Starting over..." << endl;
		ID = "Start"; //setting the ID to start for now, can be changed later - Doug
		DisplayBackstory();
		playerChoice(RoomID, input);
		
		//clear inventory
		//reset events
	}
	else if (inp == "LOOK" || inp == "look")
	{
		LookAround(ID);
	}
	else if (inp == "PICK UP" || inp == "pick up") // We don't have an item class yet, so 'item' is just a stand in. - Dorien
	{ 
		// cout << "You pick up: " << item << endl;
		// playerInventory += item; 
	}
	else
	{
		cout << "Invalid input, try again." << endl;
	}
	*/

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
	
	DisplayBackstory();

	RoomID = "start"; // RoomID set to start, the user just spawned in at this point - Doug
	
	cout << "Head to the kitchen by putting in MOVE WEST. You can move to the other rooms later by putting in MOVE and the other three cardinal directions." << endl;

	cout << playerChoice(input); // Call player choice and update room ID if needed, to then display the correct description. - Dorien

	// DisplayDescription(RoomID); // Move to next area. - Dorien //this function is writing to the console after the player resets the game - Doug

	//playerChoice(RoomID, input); // Call PC again - Dorien
	

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
// Don't put functions down here - define them above! - Dorien 