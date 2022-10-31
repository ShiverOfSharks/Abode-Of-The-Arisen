#include "Room.h"
#include <iostream>
#include <list>
using namespace std;

Room::Room(int roomId) {
	list<string> roomItems = { "room","room","room" };
	roomNumber = roomId;
	if (roomNumber == 1)
		roomName = "Enterence";
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