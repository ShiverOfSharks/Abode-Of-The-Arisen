#include "Room.h"
#include <iostream>
#include <list>
using namespace std;

Room::Room(int roomId) { //Constructor
	list<string> roomItems = { "room","room","room" };
	roomNumber = roomId;
	
	if (roomNumber == 1 || roomNumber==4)
		roomName = "Enterence";
	else if (roomNumber == 2)
		roomName = "Kitchen";
	else if (roomNumber == 3)
		roomName = "Hallway";
	else
		roomName = "Somewhere";
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