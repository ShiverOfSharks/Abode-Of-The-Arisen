// Abode Of The Arisen - Pre-Alpha Build V0.0.1b
// By Dorien Fields, Douglas Grosch, Geoffery Gin, Dylan De Muth, & Angelique Mueller


/* Global variable defintions go here. - Dorien */
#include "AbodeHeader.h"
using namespace std;

#define Abode[3][3]; // Floor layout. Used to denote where the player is, and as a check for events and possible dialogue. Very integral. - Dorien


/* Functions go here. Only make calls in main(), please do NOT
	define functions in main(). And of course, make sure to
	follow coding standards. - Dorien */

void DisplayBackstory() // displays the opening preamble. Called to first thing in main() - Dorien
{
	cout << "Your name is Anonymous. It's been a scant 5 days since the outbreak began, and life as you knew was turned into a walking nightmare." << endl;
	cout << "You were unprepared. You didn't have a chance to grab anything from your home in the city before you fled to the countryside, barely avoiding death or infection along the way." << endl;
	cout << "You found a house in the countryside that looks pretty defensible, but in your hurry, you tripped the security system's alarm, and now the undead close in." << endl;
	cout << "You are in Hallway. Type MOVE [Direction] (NORTH, SOUTH, EAST, or WEST) to move in that direction. Type LOOK to have a look at your surroundings." << endl;
	cout << "Type LOOK AT to look at more specific points or items of interest. Type PICK UP to grab something, and type STUFF to see your inventory." << endl;
	cout << "If you ever get stuck, type RESET to give into the zombie hor-er, I mean, reset the game to here." << endl;
	cout << "You should probably find a way to shut that alarm off...the controls should be in the kitchen to your east." << endl;;
}


int main()
{
	/* For now, we shall simply output text to the screen, and call it a day.*/

	DisplayBackstory();

	return 0; // Exit program successfully.
}