#include "Room.h"
#include <iostream>
#include <list>
using namespace std;

// for the moment - make the names match the roomStrings[] defined in main
// string roomStrings[NUM_ROOMS] = {"HALLWAY", "BATHROOM", "BEDROOM"};
// enum Rooms { HALLWAY = 0, BATHROOM = 1, BEDROOM = 2, ERROR = 99};

Room::Room(int roomId) { //Constructor
	list<string> roomItems = { "room","room","room" };
	roomNumber = roomId;

	if (roomNumber == 0) {
		roomName = "HALLWAY";
		roomDescription = "HALLWAY";
	}
	else if (roomNumber == 1) {
		roomName = "BATHROOM";
		roomDescription = "BATHROOM";
	}
	else if (roomNumber == 2) {
		roomName = "BEDROOM";
		roomDescription = "BEDROOM";
	}
	else {
		roomName = "Somewhere";
		roomDescription = "Unknown room";
	}
}



string Room::getRoomName() {
	return roomName;
}
 
void Room::getRoomInvintory() {
	cout << "\n";
	for (auto const& temp : roomItems) //prints each element in list roomItems
		cout << temp << " ";
	cout << "\n";
}

string Room::getRoomDescription(){
	// cout << roomDescription;
	return roomDescription;
}