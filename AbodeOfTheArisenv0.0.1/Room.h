#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <list>
using namespace std;
class Room { //Room class
private:

	//Variables
	list<string> roomItems; //Items to be collected from this room
	int roomNumber; //Room number identifier, retrieved from array
	std::string roomName; //This room's name
public:
	
	//Methods
	Room(int roomId);
	std::string getRoomName();
	void getRoomInvintory();
};//class Room

#endif //ROOM_H