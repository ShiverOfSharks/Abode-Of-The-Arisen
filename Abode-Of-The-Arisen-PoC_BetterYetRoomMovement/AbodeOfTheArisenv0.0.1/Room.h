#ifndef ROOM_H
#define ROOM_H

#include "Item.h" //allows items to be accessed
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Room { //Room class
private:

	//Variables
	list<Item> roomItems; //Items to be collected from this room
	int roomNumber; //Room number identifier, retrieved from array
	std::string roomName; //This room's name
	std::string roomDescription; //Text about the room including directions for user
public:
	 
	//Methods
	Room(int roomId);
	std::string getRoomName();
	void getRoomInventory();
	string getRoomDescription();
	void addRoomInvintory(Item newItem);
};//class Room

#endif //ROOM_H