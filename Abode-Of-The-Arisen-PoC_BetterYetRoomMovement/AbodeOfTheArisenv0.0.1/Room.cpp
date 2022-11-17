#include "Room.h"
#include <iostream>
#include <list>
using namespace std;

// for the moment - make the names match the roomStrings[] defined in main
// string roomStrings[NUM_ROOMS] = {"HALLWAY", "BATHROOM", "BEDROOM"};
// enum Rooms { HALLWAY = 0, BATHROOM = 1, BEDROOM = 2, ERROR = 99};

Room::Room(int roomId) { //Constructor
	roomItems;
	roomNumber = roomId;

	if (roomNumber == 0) {
		roomName = "HALLWAY";
		roomDescription = "A dimly lit hallway with stained white walls.\nThere is an odd smell emulating from the carpet beneath your feet.\nAs you investigate further you realize that there are stains of blood\non wall and beneath your feet.The trail leads into the kitchen";
	
		addRoomInvintory("Battle Axe");//POC TEST, future implementation should use ITEM objects instead of strings
	
	}
	else if (roomNumber == 1) {
		roomName = "BATHROOM";
		roomDescription = "-ensuite - Your typical bathroom with a shower/bathtub and a jack\n and jill sink. There is tacky wallpaper on the walls. Don’t forget to check\n behind the shower curtain.- hallway bathroom - The bathroom was\n clearly used recently, the toilet was left unflushed,\n and mysteriously there is bloodand used gauze in the sink.";
	
		addRoomInvintory("Hammer");//POC TEST, future implementation should use ITEM objects instead of strings
		addRoomInvintory("Hat");//POC TEST, future implementation should use ITEM objects instead of strings

	}
	else if (roomNumber == 2) {
		roomName = "BEDROOM";
		roomDescription = "As you traverse through the house the bedroom seems untouched, the bed was made and all the family heirlooms are still in tact. Maybe youre safe in here for now… dont forget to check under the bed.";
		
		addRoomInvintory("Base Ball Bat");//POC TEST, future implementation should use ITEM objects instead of strings

	}
	else if (roomNumber == 3) {
		roomName = "KITCHEN";
		roomDescription = "As you enter the kitchen, you follow a trail of blood that leads\n to a dismembered zombie sitting in the corner. After realizing you are safe\n for now you take a moment to adjust your surroundings. The kitchen is a modern finish\n with white quartz counters and a new gas range.\n There are most certainly weapons here.";
	
		addRoomInvintory("First Aid Pack");//POC TEST, future implementation should use ITEM objects instead of strings

	}
	else {
		roomName = "Somewhere";
		roomDescription = "Unknown room";
	}
}



string Room::getRoomName() {
	return roomName;
}
 
void Room::getRoomInventory() {
	int count = 0; //flag for number of times loop runs

	cout << "\n";
	if (roomItems.size() == 0)
		cout << "	No Items.";
	else
		for (auto temp : roomItems) { //prints each element in list roomItems
			cout << temp << " ";
			if (count < 1) cout << ", ";
			
			count++;
		} //for
	cout << "\n";
}

string Room::getRoomDescription(){
	return roomDescription;
}

void Room::addRoomInvintory(string newItem) { //adds element to "roomItems" 
	roomItems.push_back(newItem);
}